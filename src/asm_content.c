/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_content.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 19:01:11 by idunaver          #+#    #+#             */
/*   Updated: 2020/01/18 19:01:12 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_asm_content	*init_content(int fd)
{
	t_asm_content	*content;

	if (!(content = (t_asm_content *)ft_memalloc(sizeof(t_asm_content))))
		return (NULL);
	content->fd = fd;
	content->flag_name = 0;
	content->flag_comment = 0;
	content->flag_pattern = 0;
	content->memory_code_size = 0;
	content->line = NULL;
	content->tokens = NULL;
	content->name = NULL;
	content->comment = NULL;
	return (content);
}
