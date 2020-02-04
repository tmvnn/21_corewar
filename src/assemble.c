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

char	*help_check_name_or_comment_champs(t_asm_content *content, int fd)
{
	char *temp;

	temp = "\0";
	do {
		temp = ft_strjoin(temp, content->line);
		if (parse(temp, PATTERN_NAME_CHAMPS))
		{
			if (content->flag_name == 1)
				return (NULL);
			content->flag_name = 1;
			return (temp);
		}
		else if (parse(temp, PATTERN_COMMENT_CHAMPS))
		{
			if (content->flag_comment == 1)
				return (NULL);
			content->flag_comment = 1;
			return (temp);
		}
	} while (get_next_line(fd, &content->line) > 0);
	return (NULL);
}

char	*check_valid(t_asm_content *content, int fd)
{
	if (content->flag_name && content->flag_comment && parse(content->line, PATTERN))
		return (content->line);
	else if (parse(content->line, PATTERN_NAME_OR_COMMENT_CHAMPS_FIRST_STAGE))
		return (help_check_name_or_comment_champs(content, fd));
	else if (parse(content->line, PATTERN_COMMENT))
		return (content->line);
	else if (parse(content->line, PATTERN_SPACE_OR_EMPTY_LINE))
		return (content->line);
	return (NULL);
}

void	assemble(char *filename)
{
	int				fd;
	t_asm_content	*content;
	t_strings		*rows;
	int				count = 1;

	rows = NULL;
	if ((fd = open(filename, O_RDONLY)) == -1)
		error();
	content = init_content(fd);
	while (get_next_line(fd, &content->line) > 0){
		if (!(content->line = check_valid(content, fd))){
			printf("%s not valid, error in %d line\n",content->line, count);
			return ;
		}
		tokenizing(&content->line, &rows, &content);
		count++;
	}
	printf("name: %s\ncomment: %s\n", content->name, content->comment);
	what_are_strings(rows);
}
