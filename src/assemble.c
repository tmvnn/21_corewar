/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assemble.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timuryakubov <timuryakubov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 19:06:42 by idunaver          #+#    #+#             */
/*   Updated: 2020/02/18 15:02:49 by timuryakubo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	assemble(t_asm_content **content)
{
	t_strings		*rows;

	rows = NULL;
	while (get_next_line((*content)->fd_src, &(*content)->line) > 0)
	{
		if (!((*content)->line = check_valid((*content), (*content)->fd_src)))
			error(*content);
		tokenizing(&(*content)->line, &rows, content);
	}
	// what_are_strings(rows);
	if (!(*content)->flag_pattern || !check_all_label(rows, content))
		error(*content);
	(*content)->exec_code_size = (*content)->memory_code_size;
	(*content)->asm_size = (*content)->exec_code_size + (*content)->header_size;
	(*content)->bytecode = (char *)ft_memalloc((*content)->asm_size * sizeof(char));
	ft_bzero((*content)->bytecode, (*content)->asm_size);
	in_bytecode(content);
	fill_file(rows, content);
	write((*content)->fd_dst, (*content)->bytecode, (*content)->asm_size);
	clean_memory(content);
}
