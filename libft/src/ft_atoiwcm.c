#include <libft.h>

int	ft_atoiwcm(char *str)
{
	int	result;

	result = atoi(str);
	if (*str)
		ft_strdel(&str);
	return (result);
}
