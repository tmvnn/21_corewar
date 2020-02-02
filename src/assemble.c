/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assemble.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 19:06:42 by idunaver          #+#    #+#             */
/*   Updated: 2020/01/26 15:08:40 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void check_valid(char *str){
	if ()
}

void	assemble(char *filename)
{
	int				fd;
	t_asm_content	*content;
	t_strings		*rows;

	rows = NULL;
	if ((fd = open(filename, O_RDONLY)) == -1)
		error();
	content = init_content(fd);
	while (get_next_line(fd, &content->line) > 0){
		tokenizing(&content->line, &rows, &content);
		check_valid(content->line);
	}
	printf("name: %s\ncomment: %s\n", content->name, content->comment);
	what_are_strings(rows);
}
