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

void	fill_write_code_instraction(char *content, int fd)
{
	char c;

	c = 0;
	if (!ft_strcmp(content, "live"))
		c |= LIVE;
	else if (!ft_strcmp(content, "ld"))
		c |= LD;
	else if (!ft_strcmp(content, "st"))
		c |= ST;
	else if (!ft_strcmp(content, "add"))
		c |= ADD;
	else if (!ft_strcmp(content, "and"))
		c |= AND;
	else if (!ft_strcmp(content, "or"))
		c |= OR;
	write(fd, &c, 1);
}

int		check(t_token *pointer)
{
	if (!ft_strcmp(pointer->type, INSTRACTION_NAME) && (!ft_strcmp(pointer->content, LIVE_NAME) || !ft_strcmp(pointer->content, FORK_NAME) || !ft_strcmp(pointer->content, LFORK_NAME) || !ft_strcmp(pointer->content, ZJMP_NAME)))
		return (0);
	return (1);
}

char	fill_t_reg(int iter, char c)
{
	if (iter == 1)
		c |= 64;
	else if (iter == 2)
		c |= 16;
	else if (iter == 3)
		c |= 4;
	return (c);
}

char	fill_t_dir(int iter, char c)
{
	if (iter == 1)
		c |= 128;
	else if (iter == 2)
		c |= 32;
	else if (iter == 3)
		c |= 8;
	return (c);
}

char	fill_t_ind(int iter, char c)
{
	if (iter == 1)
		c |= 192;
	else if (iter == 2)
		c |= 48;
	else if (iter == 3)
		c |= 12;
	return (c);
}

void	fill_write_code_arg(t_token *pointer, int fd)
{
	int		iter;
	char	c;

	c = 0;
	iter = 1;
	while (pointer)
	{
		if (!ft_strcmp(pointer->type, DIRECT) || !ft_strcmp(pointer->type, DIRECT_LABEL))
			c = fill_t_dir(iter, c);
		else if (!ft_strcmp(pointer->type, INDIRECT) || !ft_strcmp(pointer->type, INDIRECT_LABEL))
			c = fill_t_ind(iter, c);
		else if (!ft_strcmp(pointer->type, REGISTER))
			c = fill_t_reg(iter, c);
		iter++;
		pointer = pointer->next;
	}
	write(fd, &c, 1);
}

void	write_args(int flag, char *content, char *type)
{
	if 
}

void	fill_write_arg(t_token *pointer, int fd)
{
	t_token	*pointer_start;
	int		flag;

	pointer_start = pointer;
	flag = 0;
	while (pointer)
	{
		if (!ft_strcmp(pointer->type, INSTRACTION) && (!ft_strcmp(pointer->content, ZJMP) || !ft_strcmp(pointer->content, LDI) || !ft_strcmp(pointer->content, STI) || !ft_strcmp(pointer->content, FORK) || !ft_strcmp(pointer->content, LLDI) || !ft_strcmp(pointer->content, LFORK)))
			flag = 1;
		else if (!ft_strcmp(pointer->type, REGISTER))
			write_args(flag, atoi(ft_strsub(pointer->content, 1, strlen(pointer->content)), pointer->type);
		else if (!ft_strcmp(pointer->type, DIRECT))
			write_args(flag, atoi(ft_strsub(pointer->content, 1, strlen(pointer->content))), pointer->type);
		else if (!ft_strcmp(pointer->type, DIRECT_LABEL))
			write_args(flag, search_instraction(ft_strsub(pointer->content, 2, strlen(pointer->content))) - pointer->memory_size, pointer->type);
		else if (!ft_strcmp(pointer->type, INDIRECT_LABEL))
			write_args(flag, search_instraction(ft_strsub(pointer->content, 1, strlen(pointer->content))) - pointer->memory_size, pointer->type);
		else if (!ft_strcmp(pointer->type, INDIRECT))
			write_args(flag, atoi(pointer->content), pointer->type);
		pointer = pointer->next;
	}
}

void	fill_write(t_token *pointer, char *filename)
{
	int fd;

	fd = open(ft_strjoin(ft_strsub(filename, 0, ft_strlen(filename) - 2), ".cor"), O_CREAT | O_RDWR | O_APPEND, 664);
	fill_write_code_instraction(pointer->content, fd);
	if (check(pointer))
		fill_write_code_arg(pointer, fd);
	fill_write_arg(pointer, fd);
}

void	fill_file(t_strings *rows, char *filename)
{
	t_token *pointer;
	while (rows)
	{
		pointer = rows->string;
		while (pointer)
		{
			if (!ft_strcmp(pointer->type, INSTRACTION))
				fill_write(pointer, filename);
			pointer = pointer->next;
		}
		rows = rows->next;
	}
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
	fill_file(rows, filename);
	what_are_strings(rows);
	// clean_memory(rows);
}
