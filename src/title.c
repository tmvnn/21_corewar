/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   title.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 18:45:27 by idunaver          #+#    #+#             */
/*   Updated: 2020/01/21 21:43:43 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			skip_simple_comment_emptyline(char **line)
{
	if (**line == '#' || **line == ';' || ft_strlen(*line) == 0)
	{
		ft_strdel(line);
		return (1);
	}
	return (0);
}

static int	add_name(char **buff, t_asm_content **content)
{
	if (buff[1])
		(*content)->name = ft_strdup(buff[1]);
	if (!(*content)->name)
		error();
	clear_buff(buff);
	return (1);
}

static int	add_comment(char **buff, t_asm_content **content)
{
	if (buff[1])
		(*content)->comment = ft_strdup(buff[1]);
	clear_buff(buff);
	return (1);
}

int			check_name_or_comment(char **buff, t_asm_content **content)
{
	if (!buff || !*buff || ft_isspace(**buff))
		return (1);
	if (ft_strcmp(*buff, NAME_CMD_STRING) == 0)
		return (add_name(buff, content));
	else if (ft_strcmp(*buff, COMMENT_CMD_STRING) == 0)
		return (add_comment(buff, content));
	return (0);
}
