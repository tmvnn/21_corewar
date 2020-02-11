/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_content.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 19:01:11 by idunaver          #+#    #+#             */
/*   Updated: 2020/02/09 18:58:48 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		init_header(header_t **header) {
    if (!(*header = (header_t *)ft_memalloc(sizeof(header_t))))
		error();
    (*header)->magic = COREWAR_EXEC_MAGIC;
}

t_asm_content	*init_content()
{
	t_asm_content	*content;

	if (!(content = (t_asm_content *)ft_memalloc(sizeof(t_asm_content))))
		error();
	content->fd_dst = 0;
	content->fd_src = 0;
	content->flag_name = 0;
	content->flag_comment = 0;
	content->flag_pattern = 0;
	content->memory_code_size = 0;
	content->line = NULL;
	content->tokens = NULL;
	content->name = NULL;
	content->comment = NULL;
	content->exec_code_size = 0;
	content->bytecode = NULL;
	content->asm_size = HEADER_SIZE;
	init_header(&content->header);
	return (content);
}
