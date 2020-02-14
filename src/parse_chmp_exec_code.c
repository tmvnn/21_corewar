/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_chmp_exec_code.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timuryakubov <timuryakubov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:08:16 by timuryakubo       #+#    #+#             */
/*   Updated: 2020/02/14 15:24:12 by timuryakubo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

u_int8_t			get_num_from_1byte(t_asm_content **content, int *i)
{
	unsigned char 	rbyte;
	
	if (read((*content)->fd_src, &rbyte, 1) < 0)
			error();
	(*i)++;
	return ((u_int8_t)rbyte);
}

int			get_num_from_nbyte(t_asm_content **content,
							int *i, u_int8_t t_dir_size)
{
	int 			tmp;
	int 			rez;
	int 			j;
	unsigned char	rbyte;
	
	j = -1;
	tmp = 0;
	rez = 0;
	while (++j < t_dir_size)
	{
		if (read((*content)->fd_src, &rbyte, 1) <= 0)
			error();
		(*i)++;
		if ((tmp = rbyte) > 0)
			tmp <<= 8 * (t_dir_size - j - 1);
		rez += tmp;
	}
	return (rez);
}


void				get_args_types(t_asm_content **content, int *i,
														u_int8_t cur_op)
{
	int 			j;
	unsigned char	rbyte;
	
	if (read((*content)->fd_src, &rbyte, 1) < 0)
			error();
	(*i)++;
	j = ARGS_TYPES_COUNT;
	while (j-- > 0)
	{
		rbyte >>= 2;
		op_tab[cur_op].args_types[j] = 3 & rbyte;
		//printf("arg%d = %d ", j, op_tab[cur_op].args_types[j]);
	}
}

void				write_curr_op(t_asm_content **content, int *i,
														u_int8_t cur_op)
{
	int				j;
	char			*num;

	j = 0;
	ft_strcpy((*content)->buf + (*content)->b_pos, op_tab[cur_op].op_name);
	(*content)->b_pos += op_tab[cur_op].oname_size;
	(*content)->buf[(*content)->b_pos++] = ' ';
	while (op_tab[cur_op].args_types[j])
	{
		num = 0;
		if (op_tab[cur_op].args_types[j] == REG_CODE)
		{
			(*content)->buf[(*content)->b_pos++] = 'r';
			num = ft_itoa(get_num_from_1byte(content, i));
			ft_strcpy((*content)->buf + (*content)->b_pos, num);
			(*content)->b_pos += ft_strlen(num);
			j + 1 != op_tab[cur_op].args_num ?
								(*content)->buf[(*content)->b_pos++] = ',' : 0;
			(*content)->buf[(*content)->b_pos++] = ' ';
			free(num);
		}
		else if (op_tab[cur_op].args_types[j] == DIR_CODE)
		{
			(*content)->buf[(*content)->b_pos++] = '%';
			num = ft_itoa(get_num_from_nbyte(content, i,
												op_tab[cur_op].t_dir_size));
			ft_strcpy((*content)->buf + (*content)->b_pos, num);
			(*content)->b_pos += ft_strlen(num);
			j + 1 != op_tab[cur_op].args_num ?
								(*content)->buf[(*content)->b_pos++] = ',' : 0;
			(*content)->buf[(*content)->b_pos++] = ' ';
			free(num);
		}
		else if (op_tab[cur_op].args_types[j] == IND_CODE)
		{
			num = ft_itoa(get_num_from_nbyte(content, i, IND_SIZE));
			ft_strcpy((*content)->buf + (*content)->b_pos, num);
			(*content)->b_pos += ft_strlen(num);
			j + 1 != op_tab[cur_op].args_num ?
								(*content)->buf[(*content)->b_pos++] = ',' : 0;
			(*content)->buf[(*content)->b_pos++] = ' ';
			free(num);
		}
		j++;
	}
	(*content)->buf[(*content)->b_pos++] = '\n';
}

void				parse_chmp_exec_code(t_asm_content **content)
{
	int 			i;
	u_int8_t		cur_op;				
	
	i = 0;
	while (i < (int)(*content)->exec_code_size)
	{
		cur_op = get_num_from_1byte(content, &i);
		if (op_tab[cur_op].args_types_code)
			get_args_types(content, &i, cur_op);
		write_curr_op(content, &i, cur_op);
		//(*content)->buf[((*content)->b_pos)] = 0;
		//printf("\n\n%s\n\n", (*content)->buf);
	}
}
