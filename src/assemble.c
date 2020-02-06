/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assemble.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 19:06:42 by idunaver          #+#    #+#             */
/*   Updated: 2020/02/06 21:01:15 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	assemble(char *filename, t_asm_content **content)
{
	t_strings		*rows;

	rows = NULL;
	if (((*content)->fd_src = open(filename, O_RDONLY)) == -1)
		error();
	while (get_next_line((*content)->fd_src, &(*content)->line) > 0)
		tokenizing(&(*content)->line, &rows, content);
	printf("name: %s\ncomment: %s\n", (*content)->name, (*content)->comment);
	what_are_strings(rows);
	in_bytecode(content);
}
