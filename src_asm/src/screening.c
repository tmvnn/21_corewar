#include "asm.h"

char	*screen(char symbol, t_asm_content *content)
{
	char *result;

	if (!(result = ft_strnew(1)))
		error(content);
	result[0] = symbol;
	return (result);
}

char    *screening(char symbol, t_asm_content *content)
{
	char	*result_str;
	char	*str;
	int     length;

	if(!(str = ft_strnew(1)))
		error(content);
	str[0] = symbol;
	if (symbol == '*' || symbol == '+' || symbol == '?' 
	|| symbol == '.' || symbol == '[' || symbol == ']' 
	|| symbol == '|' || symbol == '^' || symbol == '$' 
	|| symbol == '{' || symbol == '}' || symbol == '(' 
	|| symbol == ')')
	{
		length = ft_strlen(SQUARE_BRACKET_OPEN) + 
		ft_strlen(BACK_SLASH) + ft_strlen(BACK_SLASH) + 
		ft_strlen(str) + ft_strlen(SQUARE_BRACKET_CLOSE);
		if (!(result_str = ft_strnew(length)))
			error(content);
		ft_strcat(result_str, SQUARE_BRACKET_OPEN);
		if (symbol != ']' && symbol != '[')
			ft_strcat(result_str, BACK_SLASH);
		if (symbol != ']' && symbol != '[')
			ft_strcat(result_str, BACK_SLASH);
		ft_strcat(result_str, str);
		ft_strcat(result_str, SQUARE_BRACKET_CLOSE);
		ft_strdel(&str);
	}
	else if (symbol == '\\' || symbol == '\'' || symbol == '\"')
	{
		length = ft_strlen(SQUARE_BRACKET_OPEN) + ft_strlen(BACK_SLASH) + 
		ft_strlen(str) + ft_strlen(SQUARE_BRACKET_CLOSE);
		if (!(result_str = ft_strnew(length)))
			error(content);
		ft_strcat(result_str, SQUARE_BRACKET_OPEN);
		ft_strcat(result_str, BACK_SLASH);
		ft_strcat(result_str, str);
		ft_strcat(result_str, SQUARE_BRACKET_CLOSE);
		ft_strdel(&str);
		// printf("%s\n", result_str);
		// printf("%lu\n", strlen(result_str));
	}
	else
		result_str = str;
	return (result_str);
}

char    *str_screening(char *str_symbols, t_asm_content *content)
{
	char	*result_str;
	char	*temp;

	if (!*str_symbols)
		return (ft_strnew(0));
	if (!(result_str = ft_strnew(0)))
		error(content);
	while (*str_symbols)
	{
		temp = screening(*str_symbols, content);
		result_str = ft_strjoinwcm(result_str, temp);
		ft_strdel(&temp);
		str_symbols++;
	}
	return (result_str);
}