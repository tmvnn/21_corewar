/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assemble.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 19:06:42 by idunaver          #+#    #+#             */
/*   Updated: 2020/02/16 16:51:47 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	assemble(t_asm_content **content)
{
	t_strings		*rows;

	rows = NULL;
	while (get_next_line((*content)->fd_src, &(*content)->line) > 0)
	{
		if (!((*content)->line = check_valid((*content), (*content)->fd_src))){
			printf("not valid file\n");
			return ;
		}
		tokenizing(&(*content)->line, &rows, content);
	}
	// what_are_strings(rows);
	if (!(*content)->flag_pattern || !check_all_label(rows, content))
	{
		printf("not valid file\n");
		error(*content) ;
	}
	(*content)->exec_code_size = (*content)->memory_code_size;
	(*content)->asm_size = (*content)->exec_code_size + (*content)->header_size;
	(*content)->bytecode = (char *)ft_memalloc((*content)->asm_size * sizeof(char));
	ft_bzero((*content)->bytecode, (*content)->asm_size);
	in_bytecode(content);
	if (!fill_file(rows, content))
		return ;
	write((*content)->fd_dst, (*content)->bytecode, (*content)->asm_size);
	clean_memory(content);
}
