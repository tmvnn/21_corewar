/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_name_comt_cs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timuryakubov <timuryakubov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 18:44:59 by timuryakubo       #+#    #+#             */
/*   Updated: 2020/02/16 16:59:27 by timuryakubo      ###   ########.fr       */
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
	//printf("REZ = %d\n", rez);
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
		if (read(fd, &rbyte, 1) <= 0)
			error();
		if (rbyte)
			buff[(*b_pos)++] = rbyte;
		i++;
	}
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
			error();
		if (rbyte)
			buff[(*b_pos)++] = rbyte;
		i++;
	}
	buff[(*b_pos)++] = '"';
	buff[(*b_pos)++] = '\n';
	buff[(*b_pos)++] = '\n';
	return (1);
}

void	skip_NULL_bytes(t_asm_content **content)
{
	unsigned char	rbyte;
	int 			i;

	i = -1;
	while (++i < NULL_SIZE)
	{
		if (read((*content)->fd_src, &rbyte, 1) <= 0 || rbyte)
			error();
	}
}

void	parse_chmp_exec_code_size(t_asm_content **content)
{
	unsigned char	rbyte;
	int 			tmp;
	int 			rez;
	int 			i;
	
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
}
