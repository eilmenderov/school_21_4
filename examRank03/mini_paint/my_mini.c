#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

typedef struct s_zone
{
	int		wid;
	int		hid;
	char	back;
}				t_zone;

typedef struct s_data
{
	char	type;
	float	x;
	float	y;
	float	r;
	char	sym;
	int		fl;
	char	**rez;
	t_zone	*zone;
}				t_data;

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (i);
	while(str[i])
		i++;
	return (i);
}

int	ft_error(char *str)
{
	write(1, str, ft_strlen(str));
	return (1);
}

int	ft_free(FILE *file, t_data *data)
{
	int	i;

	fclose(file);
	while (data->rez && data->rez[i])
	{
		free(data->rez[i]), data->rez[i] = NULL;
		i++;
	}
	if (data->rez)
		free(data->rez), data->rez = NULL;
	return (1);
}

void	ft_create_back(t_data *data)
{
	char	**rez;
	int		i;
	int		j;

	rez = malloc(sizeof(char *) * (data->zone->hid + 1));
	i = 0;
	while (i < data->zone->hid)
	{
		rez[i] = malloc(sizeof(char) * (data->zone->wid + 1));
		j = 0;
		while (j < data->zone->wid)
			rez[i][j] = data->zone->back, j++;
		rez[i][j] = 0;
		i++;
	}
	rez[i] = NULL;
	data->rez = rez;
}

void	ft_get_zone(FILE *file, t_data *data)
{
	int	fl;

	data->fl = 0;
	fl = fscanf(file, "%d %d %c\n", &data->zone->wid, &data->zone->hid, &data->zone->back);
	if (fl != 3 || fl < 0 || data->zone->wid <= 0 || data->zone->hid <= 0
		|| data->zone->wid > 300 || data->zone->hid > 300)
	{
		data->fl = -1;
		return ;
	}
	ft_create_back(data);
}

void	ft_print_rez(t_data *data)
{
	int	i;

	i = 0;
	while (data->rez[i])
	{
		write(1, data->rez[i], ft_strlen(data->rez[i]));
		write(1, "\n", 1);
		i++;
	}
}

int	ft_solve(float x, float y, t_data *data)
{
	float	dist;

	dist = sqrt(((x - data->x) * (x - data->x)) + ((y - data->y) *(y - data->y)));
	if (dist <= data->r)
	{
		if ((data->r - dist) < 1.0)
			return (2);
		return (1);
	}
	return (0);
}

void	ft_get_draw(t_data *data)
{
	int	x;
	int	y;
	int	rad;

	y = 0;
	while (y < data->zone->hid)
	{
		x = 0;
		while (x < data->zone->wid)
		{
			rad = ft_solve(x, y, data);
			if ((rad == 2 && data->type == 'c') || (rad && data->type == 'C'))
				data->rez[y][x] = data->sym;
			x++;
		}
		y++;
	}
}

int	ft_draw(FILE *file, t_data *data)
{
	int	fl;

	while((fl = fscanf(file, "%c %f %f %f %c\n", &data->type, &data->x, &data->y, &data->r, &data->sym)) == 5)
	{
		if ((data->type != 'c' && data->type != 'C') || data->r <= 0.0)
			return (0);
		ft_get_draw(data);
	}
	if (fl != -1)
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	FILE	*file;
	t_zone	zone;
	t_data	data;

	data.zone = &zone;
	if(ac != 2)
		return (ft_error("Error: argument\n"));
	file = fopen(av[1], "r");
	if (!file)
		return (ft_error("Error: Operation file corrupted\n"));
	ft_get_zone(file, &data);
	if (data.fl)
		return (ft_error("Error: Operation file corrupted\n"));
	if (!ft_draw(file, &data))
		return (ft_free(file, &data) && ft_error("Error: Operation file corrupted\n"));
	ft_print_rez(&data);
	ft_free(file, &data);
	return (0);
}
