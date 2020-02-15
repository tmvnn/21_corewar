#include "libft.h"

char    *ft_strsubwcm(char *s, unsigned int start, size_t len)
{
	char    *new;

	new = ft_strsub(s, start, len);
	if (*s)
		ft_strdel(&s);
	return (new);
}