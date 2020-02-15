/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: s39f4lt <s39f4lt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 18:37:38 by idunaver          #+#    #+#             */
/*   Updated: 2020/02/15 17:35:18 by s39f4lt          ###   ########.fr       */
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

static void	space_replacement(char **line, int size, char c)
{
	char	*copy;
	int		quotes;

	quotes = 0;
	copy = *line;
	while (*copy && --size != -1)
	{
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

	*line = ft_left_trim(line);
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
