/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_content.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timuryakubov <timuryakubov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 19:01:11 by idunaver          #+#    #+#             */
/*   Updated: 2020/02/13 21:23:29 by timuryakubo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		init_header(header_t **header) {
    if (!(*header = (header_t *)ft_memalloc(sizeof(header_t))))
		error();
    (*header)->magic = COREWAR_EXEC_MAGIC;
}

t_asm_content	*init_content(char ad_flag)
{
	t_asm_content	*content;

	if (!(content = (t_asm_content *)ft_memalloc(sizeof(t_asm_content))))
		error();
	content->fd_dst = 0;
	content->fd_src = 0;
	content->asm_dsm_flag = ad_flag;
	content->line = NULL;
	content->tokens = NULL;
	content->name = NULL;
	content->comment = NULL;
	content->exec_code_size = 0;
	content->buf = NULL;
	content->b_pos = 0;
	//content->bytecode_header = NULL;
	content->bytecode_header = (char *)ft_memalloc(HEADER_SIZE * sizeof(char));
	ft_bzero(content->bytecode_header, HEADER_SIZE);
	init_header(&content->header);
	return (content);
}
