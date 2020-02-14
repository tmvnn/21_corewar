#include <stdio.h>
#include <regex.h>
#include "libft.h"

# define PATTERN_HELP_VALIDATION_FIRST_CASE "^[ 	]*([a-z0-9_]+:)?[ 	]*(live|ld|and|or|xor|zjmp|ldi|fork|lld|lldi|lfork)(%-?0*[0-9]+|%:[0-9a-z_]+).*$"
# define PATTERN_HELP_VALIDATION_SECOND_CASE "^[ 	]*[a-z0-9_]+:(live|ld|st|add|sub|and|or|xor|zjmp|ldi|sti|fork|lld|lldi|lfork|aff).*$"

char	*ft_strchr(const char *s, int c)
{
	while (*(char *)s != c)
	{
		if (!*(char *)s)
			return (NULL);
		s++;
	}
	return ((char *)s);
}

char    *rebase_str_second_case(char *content)
{
    char *result;
    char *str_cat;
	char *temp;
    char *temp1;
	
	result = NULL;
    str_cat = NULL;
	temp = NULL;
    temp1 = NULL;
	temp = ft_strchr(content, 58) + 1;
    temp1 = ft_strsub(content, 0, strlen(content) - strlen(temp));
    str_cat = ft_strjoin(temp1, ",");
    result = ft_strjoin(str_cat, temp);
    ft_strdel(&temp1);
    ft_strdel(&str_cat);
	return (result);
}

char	*rebase_str_first_case(char *content)
{
	char *result;
    char *str_cat;
	char *temp;
    char *temp1;
	
	result = NULL;
    str_cat = NULL;
	temp = NULL;
    temp1 = NULL;
	temp = ft_strchr(content, 37);
    temp1 = ft_strsub(content, 0, strlen(content) - strlen(temp));
    str_cat = ft_strjoin(temp1, ",");
    result = ft_strjoin(str_cat, temp);
    ft_strdel(&temp1);
    ft_strdel(&str_cat);
	return (result);
}

int main(int ac, char **av){
    int         err;
    regex_t     reg1;
    regmatch_t  pm;
    char        *str;

    str = rebase_str_first_case(*(av + 1));
    str = rebase_str_second_case(str);

    err = regcomp(&reg1, PATTERN_HELP_VALIDATION_SECOND_CASE, REG_EXTENDED);
    if (err != 0)
    {
        regfree(&reg1);
        ft_strdel(&str);
        printf("error with regex in file interpretation.c\n");
        return (0);
    }
    if (!regexec(&reg1, str, 0, &pm, 0))
    {
        regfree(&reg1);
        ft_strdel(&str);
        printf("good\n");
        return (1);
    }
    ft_strdel(&str);
    regfree(&reg1);
    return (0);
}