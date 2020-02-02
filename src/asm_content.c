/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_content.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 19:01:11 by idunaver          #+#    #+#             */
/*   Updated: 2020/02/02 20:53:52 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		init_header(header_t **header) {
    if (!(*header = (header_t *)ft_memalloc(sizeof(header_t))))
		error();
    (*header)->magic = COREWAR_EXEC_MAGIC;
}

t_asm_content	*init_content(int fd)
{
	t_asm_content	*content;

	if (!(content = (t_asm_content *)ft_memalloc(sizeof(t_asm_content))))
		error();
	content->fd = fd;
	content->line = NULL;
	content->tokens = NULL;
	content->name = NULL;
	content->comment = NULL;
	init_header(&content->header);
	return (content);
}
