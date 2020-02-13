/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 18:37:38 by idunaver          #+#    #+#             */
/*   Updated: 2020/02/13 22:19:03 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		clear_buff(char **buff)
{
	char	**copy;

	copy = buff;
	if (!buff || !*buff)
		return ;
	while (*copy)
		ft_strdel(&(*copy++));
	free(buff);
	buff = NULL;
}

static void	sticky_line(char **line, int diff_size, int size)
{
	char	*new_line;
	
	if (!(new_line = (char *)ft_memalloc((size + 1) * sizeof(char))))
		error();
	new_line[size] = '\0';
	ft_memcpy(new_line, *line, diff_size - 1);
	new_line[diff_size - 1] = ',';
	ft_memcpy(new_line + diff_size, *line + diff_size - 1, diff_size + 1);
	ft_strdel(line);
	*line = new_line;
}

static void	space_replacement(char **line, int size, char c)
{
	char	*copy;
	int		quotes;
	int		size_line;

	size_line = ft_strlen(*line);
	quotes = 0;
	copy = *line;
	while (*copy && --size != -1)
	{
		if (*copy == '%') {
			if (!ft_isspace(*(copy - 1)) && *(copy - 1) != ',') {
				sticky_line(line, size_line - size, size_line + 1);
				copy = *line;
				copy = copy + (size_line - size);
			}
		}
		if (*copy == '"' && quotes == 1)
			quotes = 0;
		if (*copy == '"' && quotes == 0)
			quotes = 1;
		if (ft_isspace(*copy) && quotes == 0)
			*copy = c;
		copy++;
	}
}

char		**create_buff(char **line, t_asm_content **content)
{
	char	**buff;
	char	c;

	c = (**line == '.') ? '"' : ',';
	space_replacement(line, ft_strlen(*line), c);
	buff = ft_strsplit(*line, c);
	if (**line == '.')
	{
		if (check_name_or_comment(buff, content) == 1)
			return (NULL);
	}
	ft_strdel(line);
	return (buff);
}
