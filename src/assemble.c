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
	//  && clean_memory_t_asm_content(content)
	return (clean_memory_t_strings(rows));
}

int		check(t_token *pointer)
{
	if (!ft_strcmp(pointer->type, INSTRACTION_NAME) && (!ft_strcmp(pointer->content, LIVE_NAME) || !ft_strcmp(pointer->content, FORK_NAME) || !ft_strcmp(pointer->content, LFORK_NAME) || !ft_strcmp(pointer->content, ZJMP_NAME)))
		return (0);
	return (1);
}

int		check_t_dir_size(t_token *pointer)
{
	if (!ft_strcmp(pointer->content, ZJMP_NAME) || !ft_strcmp(pointer->content, LDI_NAME) || !ft_strcmp(pointer->content, STI_NAME) || !ft_strcmp(pointer->content, FORK_NAME) || !ft_strcmp(pointer->content, LLDI_NAME) || !ft_strcmp(pointer->content, LFORK_NAME))
		return (0);
	return (1);
}

char	*check_all_label(t_strings *rows, t_asm_content *struct_content)
{
	t_token		*pointer;
	t_strings	*struct_pointer;
	int			flag;

	flag = 0;
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
			if (!ft_strcmp(pointer->type, INSTRACTION_NAME))
			{
				if (check(pointer))
					struct_content->memory_code_size += ONE_BYTE;
				if (check_t_dir_size(pointer))
					flag = 1;
				struct_content->memory_code_size += ONE_BYTE;
				// printf("%s %d\n", pointer->content, pointer->memory_size);
			}
			else if (!ft_strcmp(pointer->type, REGISTER_NAME))
				struct_content->memory_code_size += ONE_BYTE;
			else if (!ft_strcmp(pointer->type, INDIRECT_NAME) || !ft_strcmp(pointer->type, INDIRECT_LABEL_NAME))
				struct_content->memory_code_size += TWO_BYTE;
			else if (!ft_strcmp(pointer->type, DIRECT_NAME) || !ft_strcmp(pointer->type, DIRECT_LABEL_NAME))
				struct_content->memory_code_size += flag ? FOUR_BYTE : TWO_BYTE;
			pointer->memory_size = struct_content->memory_code_size;
			// printf("%s - %d\n", pointer->content, pointer->memory_size);
			pointer = pointer->next;
		}
		flag = 0;
		struct_pointer = struct_pointer->next;
	}
	return ("very good");
}

void	fill_write_code_instraction(char *instraction, t_asm_content *content)
{
	char c;

	c = '\0';
	if (!ft_strcmp(instraction, LIVE_NAME))
		c |= LIVE;
	else if (!ft_strcmp(instraction, LD_NAME))
		c |= LD;
	else if (!ft_strcmp(instraction, ST_NAME))
		c |= ST;
	else if (!ft_strcmp(instraction, ADD_NAME))
		c |= ADD;
	else if (!ft_strcmp(instraction, AND_NAME))
		c |= AND;
	else if (!ft_strcmp(instraction, OR_NAME))
		c |= OR;
	else if (!ft_strcmp(instraction, XOR_NAME))
		c |= XOR;
	else if (!ft_strcmp(instraction, ZJMP_NAME))
		c |= ZJMP;
	else if (!ft_strcmp(instraction, LDI_NAME))
		c |= LDI;
	else if (!ft_strcmp(instraction, STI_NAME))
		c |= STI;
	else if (!ft_strcmp(instraction, FORK_NAME))
		c |= FORK;
	else if (!ft_strcmp(instraction, LLD_NAME))
		c |= LLD;
	else if (!ft_strcmp(instraction, LLDI_NAME))
		c |= LLDI;
	else if (!ft_strcmp(instraction, LFORK_NAME))
		c |= LFORK;
	else if (!ft_strcmp(instraction, ADD_NAME))
		c |= ADD;
	ft_memcpy(content->bytecode + content->asm_size, &c, ONE_BYTE);
	content->asm_size += ONE_BYTE;
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

void	fill_write_code_arg(t_token *pointer, t_asm_content *content)
{
	int		iter;
	char	c;

	c = 0;
	iter = 1;
	while (pointer)
	{
		if (!ft_strcmp(pointer->type, DIRECT_NAME) || !ft_strcmp(pointer->type, DIRECT_LABEL_NAME))
			c = fill_t_dir(iter, c);
		else if (!ft_strcmp(pointer->type, INDIRECT_NAME) || !ft_strcmp(pointer->type, INDIRECT_LABEL_NAME))
			c = fill_t_ind(iter, c);
		else if (!ft_strcmp(pointer->type, REGISTER_NAME))
			c = fill_t_reg(iter, c);
		if (ft_strcmp(pointer->type, LABEL_NAME) && ft_strcmp(pointer->type, INSTRACTION_NAME))
			iter++;
		pointer = pointer->next;
	}
	ft_memcpy(content->bytecode + content->asm_size, &c, ONE_BYTE);
	content->asm_size += ONE_BYTE;
}

void	write_args(int length, int num, t_asm_content *content)
{
	char	temp[length];
	int		iter;
	int		i;

	iter = 0;
	i = length;
	ft_bzero(temp, 4);
	while (i--)
	{
		temp[i] = (char)(num >> iter);
		iter += 8;
	}
	ft_memcpy(content->bytecode + content->asm_size, temp, length);
	content->asm_size += length;
}

int		search_instraction(char *content, t_strings *rows)
{
	t_token *pointer;

	pointer = rows->string;
	while (rows)
	{
		pointer = rows->string;
		while (pointer)
		{
			if (!ft_strcmp(pointer->type, LABEL_NAME) && !ft_strcmp(pointer->content, content))
				return (pointer->memory_size);
			pointer = pointer->next;
		}
		rows = rows->next;
	}
	return (0);
}

int		size_content(t_token *pointer)
{
	if (!ft_strcmp(pointer->type, INSTRACTION_NAME) && check(pointer))
		return(TWO_BYTE );
	return (ONE_BYTE);
}

int		search_instraction_two(t_token *pointer)
{
	while (pointer)
	{
		if (!ft_strcmp(pointer->type, INSTRACTION_NAME))
			return (pointer->memory_size - size_content(pointer));
		pointer = pointer->previous;
	}
	return (0);
}

void	fill_write_arg(t_token *pointer, t_strings *rows, t_asm_content *content)
{
	int		flag;

	flag = 0;
	while (pointer)
	{
		if (!ft_strcmp(pointer->type, INSTRACTION_NAME) && check_t_dir_size(pointer))
			flag = 1;
		else if (!ft_strcmp(pointer->type, REGISTER_NAME))
			write_args(ONE_BYTE, atoi(ft_strsub(pointer->content, 1, strlen(pointer->content))), content);
		else if (!ft_strcmp(pointer->type, DIRECT_NAME))
			write_args(flag ? FOUR_BYTE : TWO_BYTE, atoi(ft_strsub(pointer->content, 1, strlen(pointer->content))), content);
		else if (!ft_strcmp(pointer->type, DIRECT_LABEL_NAME))
		{
			write_args(flag ? FOUR_BYTE : TWO_BYTE, search_instraction(ft_strjoin(ft_strsub(pointer->content, 2, strlen(pointer->content)), ":"), rows) - search_instraction_two(pointer), content);
			// printf("direct_label %d\n", (search_instraction(ft_strjoin(ft_strsub(pointer->content, 2, strlen(pointer->content)), ":"), rows) - search_instraction_two(pointer)));
		}
		else if (!ft_strcmp(pointer->type, INDIRECT_LABEL_NAME))
		{
			// printf("indirect_label %d\n", search_instraction(ft_strjoin(ft_strsub(pointer->content, 1, strlen(pointer->content)), ":"), rows) - search_instraction_two(pointer));
			write_args(TWO_BYTE, (search_instraction(ft_strjoin(ft_strsub(pointer->content, 1, strlen(pointer->content)), ":"), rows) - search_instraction_two(pointer)), content);
		}
		else if (!ft_strcmp(pointer->type, INDIRECT_NAME))
			write_args(TWO_BYTE, atoi(pointer->content), content);
		// printf("%s\n", pointer->content);
		pointer = pointer->next;
	}
}

int		fill_write(t_token *pointer, t_strings *rows, t_asm_content *content)
{
	fill_write_code_instraction(pointer->content, content);
	if (check(pointer))
		fill_write_code_arg(pointer, content);
	fill_write_arg(pointer, rows, content);
	return (1);
}

int		fill_file(t_strings *rows,  t_asm_content *content)
{
	t_token		*pointer;
	t_strings	*rows_start;

	rows_start = rows;
	while (rows)
	{
		pointer = rows->string;
		while (pointer)
		{
			if (!ft_strcmp(pointer->type, INSTRACTION_NAME))
			{
				if (!fill_write(pointer, rows_start, content))
					return (0);
			}
			pointer = pointer->next;
		}
		rows = rows->next;
	}
	return (1);
}

void	assemble(char *filename, t_asm_content *content)
{
	t_strings		*rows;

	rows = NULL;
	if (content->fd_src = open(filename, O_RDONLY)) == -1)
		error();
	while (get_next_line((content)->fd_src, &content->line) > 0)
	{
		if (!content->line = check_valid(content, (content)->fd_src))){
			return ;
		}
		tokenizing((&content)->line, &rows, &content);
	}
	if (!content)->flag_pattern || !check_all_label(rows, content))
	{
		printf("not valid file\n");
		return ;
	}
	content->asm_size += content->memory_code_size;
	content->bytecode = (char *)ft_memalloc(content->asm_size * sizeof(char));
	ft_bzero(content->bytecode_header, content->asm_size);
	in_bytecode(content);
	if (!fill_file(rows, *content))
		return ;
	// clean_memory(rows);
}
