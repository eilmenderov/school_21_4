#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_zone
{
	int		width;
	int		height;
	char	back;
} 				t_zone;

typedef struct s_data
{
	int		fl;
	char	type;
	float	x;
	float	y;
	float	width;
	float	height;
	char	sym;
	char	**rez;
	t_zone	*zone;
}			t_data;

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if(!str)
		return (i);
	while (str[i])
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
	i = 0;
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

	rez = malloc(sizeof(char *) * (data->zone->height + 1));
	i = 0;
	while (i < data->zone->height)
	{
		rez[i] = malloc(sizeof(char) * (data->zone->width + 1));
		j = 0;
		while (j < data->zone->width)
			rez[i][j] = data->zone->back, j++;
		rez[i][j] = 0;
		i++;
	}
	rez[i] = NULL;
	data->rez = rez;
}

void	ft_get_zone(FILE *file, t_data *data)
{
	int		fl;

	data->fl = 0;
	fl = fscanf(file, "%d %d %c\n", &data->zone->width, &data->zone->height, &data->zone->back);
	if (fl != 3 || fl < 0 || data->zone->width <= 0 || data->zone->width > 300
		|| data->zone->height <= 0 || data->zone->height > 300)
	{
		data->fl = -1;
		return ;
	}
	ft_create_back(data);
}

void	ft_print_rez(t_data *data)
{
	int	i;

	if (!data->rez)
		return ;
	i = 0;
	while (data->rez[i])
	{
		write(1, data->rez[i], ft_strlen(data->rez[i]));
		write(1, "\n", 1);
		i++;
	}
}

int		ft_solve(float y, float x, t_data *data)
{
	float	check = 1.0;
	if ((x < data->x) || (data->x + data->width < x) || (y < data->y)
		|| (data->y + data->height < y))
		return (0);
	if (((x - data->x) < check) || ((data->x + data->width) - x < check)
		|| ((y - data->y) < check) || ((data->y + data->height) - y < check))
		return (2);
	return (1);
}

void	ft_get_draw(t_data *data)
{
	int	x;
	int	y;
	int	des;

	y = 0;
	while (y < data->zone->height)
	{
		x = 0;
		while (x < data->zone->width)
		{
			des = ft_solve(y, x, data);
			if ((data->type == 'r' && des == 2) || (data->type == 'R' && des))
				data->rez[y][x] = data->sym;
			x++;
		}
		y++;
	}
}

int	ft_draw(FILE *file, t_data *data)
{
	int	fl;

	while ((fl = fscanf(file, "%c %f %f %f %f %c\n", &data->type, &data->x, &data->y,
			&data->width, &data->height, &data->sym)) == 6)
	{
		if ((data->type != 'r' && data->type != 'R') || data->height <= 0.0 || data->width <= 0.0)
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
	t_data	data;
	t_zone	zone;

	data.zone = &zone;
	if (ac != 2)
		return (ft_error("Error: argument\n"));
	file = fopen(av[1], "r");
	if (!file)
		return(ft_error("Error: Operation file corrupted\n"));
	ft_get_zone(file, &data);
	if (data.fl)
		return(ft_error("Error: Operation file corrupted\n"));
	if (!ft_draw(file, &data))
		return(ft_free(file, &data) && ft_error("Error: Operation file corrupted\n"));
	ft_print_rez(&data);
	ft_free(file, &data);
	return (0);
}