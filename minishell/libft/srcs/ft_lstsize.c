#include "libft.h"

/*
**	@brief	counts the number of elements in a list
**	
**	@param	lst		pointer to the list begin
**	@return	int	lenght of the list
*/
int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*schet;

	schet = lst;
	i = 0;
	while (schet)
	{
		i++;
		schet = schet->next;
	}
	return (i);
}
