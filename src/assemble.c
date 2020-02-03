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

int check_valid(t_asm_content *content){
	if (content->flag_name && content->flag_comment && parse(content->line, PATTERN)){
		// printf("PATTERN\n");
		return (1);
	} else if (parse(content->line, PATTERN_NAME_CHAMPS)){
		content->flag_name = 1;
		// printf("PATTERN_NAME_CHAMPS\n");
		return (1);
	} else if (parse(content->line, PATTERN_NAME_COMMENT)){
		content->flag_comment = 1;
		// printf("PATTERN_NAME_COMMENT\n");
		return (1);
	} else if (parse(content->line, PATTERN_COMMENT)){
		// printf("PATTERN_COMMENT\n");
		return (1);
	} else if (parse(content->line, PATTERN_SPACE_OR_EMPTY_LINE)){
		// printf("PATTERN_SPACE_OR_EMPTY_LINE\n");
		return (1);
	}
	return (0);
}

void	assemble(char *filename)
{
	int				fd;
	t_asm_content	*content;
	t_strings		*rows;
	int				count = 0;

	rows = NULL;
	if ((fd = open(filename, O_RDONLY)) == -1)
		error();
	content = init_content(fd);
	while (get_next_line(fd, &content->line) > 0){
		if (!check_valid(content)){
			printf("%s not valid, error in %d line\n",content->line, count);
		}
		tokenizing(&content->line, &rows, &content);
		count++;
	}
	printf("name: %s\ncomment: %s\n", content->name, content->comment);
	what_are_strings(rows);
}
