/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assemble.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellona <lbellona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 19:06:42 by idunaver          #+#    #+#             */
/*   Updated: 2020/02/16 19:17:39 by lbellona         ###   ########.fr       */
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
