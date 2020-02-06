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
		ft_strdel(&content->line);
		if (parse(temp, PATTERN_NAME_CHAMPS))
		{
			// printf("PATTERN_NAME_CHAMPS\n");
			if (content->flag_name == 1 || strlen(temp) > PROG_NAME_LENGTH)
				return (NULL);
			content->flag_name = 1;
			return (temp);
		}
		else if (parse(temp, PATTERN_COMMENT_CHAMPS))
		{
			// printf("PATTERN_COMMENT_CHAMPS\n");
			if (content->flag_comment == 1 || strlen(temp) > COMMENT_LENGTH)
				return (NULL);
			content->flag_comment = 1;
			return (temp);
		}
		temp = ft_strjoin(temp, "\n");
	} while (get_next_line(fd, &content->line) > 0);
	return (NULL);
}

char	*check_valid(t_asm_content *content, int fd)
{
	if (parse(content->line, PATTERN_SPACE_OR_EMPTY_LINE)){
		// printf("PATTERN_SPACE_OR_EMPTY_LINE\n");
		return (content->line);
	}
	else if (parse(content->line, PATTERN_NAME_OR_COMMENT_CHAMPS_FIRST_STAGE))
		return (help_check_name_or_comment_champs(content, fd));
	else if (parse(content->line, PATTERN_COMMENT))
	{
		// printf("PATTERN_COMMENT\n");
		return (content->line);
	}
	else if (content->flag_name && content->flag_comment && parse(content->line, PATTERN))
	{
		// printf("PATTERN\n");
		content->flag_pattern = 1;
		return (content->line);
	}
	return (NULL);
}

char	*search_label(t_strings *rows, char *content)
{
	t_token		*pointer;
	t_strings	*struct_pointer;
	char		*temp;
	char		*temp1;

	struct_pointer = rows;
	while (struct_pointer)
	{
		pointer = struct_pointer->string;
		while (pointer)
		{
			if (!ft_strcmp(pointer->type, LABEL_NAME) && parse(content, DIRECT_LABEL) && !ft_strcmp((temp = ft_strsub(pointer->content, 0, strlen(pointer->content) - 1)), (temp1 = ft_strsub(content, 2, strlen(content)))))
			{
				ft_strdel(&temp);
				ft_strdel(&temp1);
				return (content);
			}
			else if (!ft_strcmp(pointer->type, LABEL_NAME) && parse(content, INDIRECT_LABEL) && !ft_strcmp((temp = ft_strsub(pointer->content, 0, strlen(pointer->content) - 1)), (temp1 = ft_strsub(content, 1, strlen(content)))))
			{
				ft_strdel(&temp);
				ft_strdel(&temp1);
				return (content);
			}
			
			pointer = pointer->next;
		}
		struct_pointer = struct_pointer->next;
	}
	return (NULL);
}

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

// char	*clean_memory_t_asm_content(t_asm_content *content)
// {
// 	ft_strdel(&content->line)
// }

char	*clean_memory(t_strings *rows)
{
	//  && clean_memoty_t_asm_content(content)
	return (clean_memory_t_strings(rows));
}

char	*check_all_label(t_strings *rows)
{
	t_token		*pointer;
	t_strings	*struct_pointer;

	struct_pointer = rows;
	while (struct_pointer)
	{
		pointer = struct_pointer->string;
		while (pointer)
		{
			if (!ft_strcmp(pointer->type, DIRECT_LABEL_NAME) || !ft_strcmp(pointer->type, INDIRECT_LABEL_NAME))
			{
				if (!search_label(rows, pointer->content))
					return (clean_memory_t_strings(rows));
			}
			pointer = pointer->next;
		}
		struct_pointer = struct_pointer->next;
	}
	return ("very good");
}

void	assemble(char *filename)
{
	int				fd;
	t_asm_content	*content;
	t_strings		*rows;
	int				count;

	rows = NULL;
	content = NULL;
	count = 1;
	if (!(fd = open(filename, O_RDONLY)) || !(content = init_content(fd)))
		error();
	while (get_next_line(fd, &content->line) > 0)
	{
		if (!(content->line = check_valid(content, fd))){
			printf("%s not valid, error in %d line\n",content->line, count);
			return ;
		}
		tokenizing(&content->line, &rows, &content);
		// printf("line:%d\n", count);
		count++;
	}
	if (!content->flag_pattern || !check_all_label(rows))
	{
		printf("not valid file\n");
		return ;
	}
	printf("good file\n");
	printf("name: %s\ncomment: %s\n", content->name, content->comment);
	what_are_strings(rows);
	clean_memory(rows);
}
