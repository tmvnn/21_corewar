#include "libft.h"

char    *ft_left_trim(char **str)
{
    char    *new_str;
    char    *copy;

    copy = *str;
    new_str = NULL;
    if (!str)
        return (NULL);
    while (*copy && ft_isspace(*copy))
        copy++;
    new_str = ft_strdup(copy);
    ft_strdel(str);
    return (new_str);
}
