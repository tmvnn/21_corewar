/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: s39f4lt <s39f4lt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 18:37:38 by idunaver          #+#    #+#             */
/*   Updated: 2020/03/07 13:35:04 by s39f4lt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		clear_buff(char **buff)
{
	char	**copy;
	int		len;

	len = 0;
	copy = buff;
	if (!buff || !*buff)
		return ;
	while (*copy++)
		len++;
	while (len)
		ft_strdel(&buff[--len]);
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

// static int	name(char *line)
// {
// 	int		name_len;
// 	char	*possible_name;
// 	char	*copy;

// 	name_len = ft_strlen(NAME_CMD_STRING);
// 	if (ft_strlen(line) <= name_len && (ft_isspace(line[name_len] == 0) 
// 	|| line[name_len] != '"'))
// 		return (0);
// 	possible_name = (char*)ft_memalloc((name_len + 1) * sizeof(char));
// 	possible_name = ft_strncpy(possible_name, line, name_len);
// 	possible_name[name_len] = '\0';
// 	if (ft_strcmp(possible_name, NAME_CMD_STRING) == 0)
// 	{
// 		ft_strdel(&possible_name);
// 		return (1);
// 	}
// 	ft_strdel(&possible_name);
// 	return (0);
// }

// static int	comment(char *line)
// {
// 	int		comment_len;
// 	char	*possible_comment;

// 	comment_len = ft_strlen(COMMENT_CMD_STRING);
// 	if (ft_strlen(line) <= comment_len && ft_isspace(line[comment_len] == 0) 
// 	&& line[comment_len] != '"')
// 		return (0);
// 	possible_comment = (char*)ft_memalloc((comment_len + 1) * sizeof(char));
// 	possible_comment = ft_strncpy(possible_comment, line, comment_len);
// 	possible_comment[comment_len] = '\0';
// 	if (ft_strcmp(possible_comment, COMMENT_CMD_STRING) == 0)
// 	{
// 		ft_strdel(&possible_comment);
// 		return (1);
// 	}
// 	ft_strdel(&possible_comment);
// 	return (0);
// }

// static int	check_line_name_or_comment(char *line, t_asm_content **content)
// {
// 	char *c_name;
// 	char *c_comm;

// 	c_name = ft_strdup(NAME_CMD_STRING);
// 	c_comm = ft_strdup(COMMENT_CMD_STRING);
// 	if (!*c_name || !*c_comm)
// 		error(*content);
// 	if (name(line) == 1 && !(*content)->name)
// 		return (1);
// 	else if (comment(line) == 1 && !(*content)->comment)
// 		return (1);
// 	else
// 		return (0);
// }

char		**create_buff(char **line, t_asm_content **content)
{
	char	**buff;
	char	c;

	*line = ft_left_trim(line);
	// c = (check_line_name_or_comment(*line, content) == 0) ? 
	// SEPARATOR_CHAR : '"';
	c = (**line == '.') ? '"' : SEPARATOR_CHAR;
	space_replacement(line, ft_strlen(*line), c);
	buff = ft_strsplit(*line, c);
	if (**line == '.')
	{
		if (check_name_or_comment(buff, content) == 1)
		{
			ft_strdel(line);
			clear_buff(buff);
			free(buff);
			return (NULL);
		}
	}
	ft_strdel(line);
	return (buff);
}
