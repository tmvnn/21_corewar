/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assemble.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 19:06:42 by idunaver          #+#    #+#             */
/*   Updated: 2020/02/11 22:36:52 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*clean_memory_t_strings(t_strings *rows)
{
	t_token *pointer;
	t_token *previous;

	while (rows)
	{
		pointer = rows->string;
		while (pointer)
		{
			ft_strdel(&pointer->content);
			ft_strdel(&pointer->type);
			previous = pointer;
			pointer = pointer->next;
			free(previous);
		}
		rows = rows->next;
	}
	return(NULL);
}

char	*clean_memory(t_strings *rows)
{
	return (clean_memory_t_strings(rows));
}

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
	if (!(*content)->flag_pattern || !check_all_label(rows, content))
	{
		printf("not valid file\n");
		error() ;
	}
	(*content)->exec_code_size = (*content)->memory_code_size;
	(*content)->asm_size = (*content)->exec_code_size + (*content)->header_size;
	(*content)->bytecode = (char *)ft_memalloc((*content)->asm_size * sizeof(char));
	ft_bzero((*content)->bytecode, (*content)->asm_size);
	in_bytecode(content);
	if (!fill_file(rows, content))
		return ;
	write((*content)->fd_dst, (*content)->bytecode, (*content)->asm_size);
}
