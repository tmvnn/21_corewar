/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disassemble.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timuryakubov <timuryakubov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 19:06:42 by idunaver          #+#    #+#             */
/*   Updated: 2020/02/13 15:57:16 by timuryakubo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		file_is_binary(int fd)
{
	unsigned char	rbyte;
	int 			tmp;
	int 			rez;
	int 			i;
	
	i = -1;
	tmp = 0;
	rez = 0;
	while (++i < MAGIC_NUMBER_SIZE)
	{
		if (read(fd, &rbyte, 1) <= 0)
			error();
		if ((tmp = rbyte) > 0)
			tmp <<= 8 * (MAGIC_NUMBER_SIZE - i - 1);
		rez += tmp;
	}
	return (rez == COREWAR_EXEC_MAGIC ? 1 : 0);
}

int		parse_name(char *buff, int *b_pos, int fd)
{
	unsigned char	rbyte;
	int				i;

	ft_memcpy(buff, NAME_CMD_STRING, NAME_CMD_LEN);
	*b_pos = NAME_CMD_LEN;
	buff[(*b_pos)++] = ' ';
	buff[(*b_pos)++] = '"';
	i = *b_pos;
	while (i < NAME_CMD_LEN + 2 + PROG_NAME_LENGTH)
	{
		//printf("i = %d\n", i - NAME_CMD_LEN - 2);
		if (read(fd, &rbyte, 1) <= 0)
			error();
		if (rbyte)
			buff[(*b_pos)++] = rbyte;
		i++;
	}
	//printf("i = %d\n", i);
	buff[(*b_pos)++] = '"';
	buff[(*b_pos)++] = '\n';
	return (1);
}

int		parse_comment(char *buff, int *b_pos, int fd)
{
	unsigned char	rbyte;
	int				i;
	int				start_pos;

	ft_memcpy(buff + *b_pos, COMMENT_CMD_STRING, COMMENT_CMD_LEN);
	*b_pos += COMMENT_CMD_LEN;
	buff[(*b_pos)++] = ' ';
	buff[(*b_pos)++] = '"';
	i = *b_pos;
	start_pos = *b_pos;
	while (i < start_pos + COMMENT_LENGTH)
	{
		if (read(fd, &rbyte, 1) <= 0)
		{
			printf("%lu\n", ft_strlen(buff));
			printf("%d\n", i);
			printf("%s\n", buff);
			error();
		}
		if (rbyte)
			buff[(*b_pos)++] = rbyte;
		i++;
	}
	buff[(*b_pos)++] = '"';
	buff[(*b_pos)++] = '\n';
	return (1);
}

void	parse_chmp_code_size(t_asm_content **content)
{
	unsigned char	rbyte;
	int 			tmp;
	int 			rez;
	int 			i;
	
	i = -1;
	while (++i < NULL_SIZE)
	{
		if (read((*content)->fd_src, &rbyte, 1) <= 0 || rbyte)
			error();
	}
	i = -1;
	tmp = 0;
	rez = 0;
	while (++i < CHMP_CODE_VAR_SIZE)
	{
		if (read((*content)->fd_src, &rbyte, 1) <= 0)
			error();
		if ((tmp = rbyte) > 0)
			tmp <<= 8 * (CHMP_CODE_VAR_SIZE - i - 1);
		rez += tmp;
	}
	(*content)->exec_code_size = rez;
	printf("code_size = %d\n", rez);
}

void	disassemble(char *filename, t_asm_content **content)
{
	char			buff[NAME_CMD_LEN + PROG_NAME_LENGTH + COMMENT_CMD_LEN + COMMENT_LENGTH + 
						4 * D_QUOTE_LEN + 2 * SPACE_LEN + 2 * SLASH_N_LEN + 1];
	int				b_pos;
	
	if (((*content)->fd_src = open(filename, O_RDONLY)) == -1)
		error();
	if (file_is_binary((*content)->fd_src))
	{
		parse_name(buff, &b_pos, (*content)->fd_src);
		parse_chmp_code_size(content);
		parse_comment(buff, &b_pos, (*content)->fd_src);
		
		buff[b_pos] = 0;
		printf("output_len = %lu\n",ft_strlen(buff));
		printf("%s\n", buff);
	}
	else
		error();
	close((*content)->fd_src);
	// while (get_next_line((*content)->fd_src, &(*content)->line) > 0)
	// tokenizing(&(*content)->line, &rows, content);
	// printf("name: %s\ncomment: %s\n", (*content)->name, (*content)->comment);
	// what_are_strings(rows);
	// in_bytecode(content);
}
