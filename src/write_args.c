/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timuryakubov <timuryakubov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 17:39:49 by timuryakubo       #+#    #+#             */
/*   Updated: 2020/02/16 17:32:54 by timuryakubo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		write_reg(t_asm_content **content, u_int8_t cur_op, int *i, int j)
{
	char	*num;

	num = 0;
	i +=0;
	(*content)->buf[(*content)->b_pos++] = 'r';
	num = ft_itoa(get_num_from_1byte(content, i));
	ft_strcpy((*content)->buf + (*content)->b_pos, num);
	(*content)->b_pos += ft_strlen(num);
	j + 1 != op_tab[cur_op].args_num ?
						(*content)->buf[(*content)->b_pos++] = ',' : 0;
	(*content)->buf[(*content)->b_pos++] = ' ';
	free(num);
}

void		write_dir(t_asm_content **content, u_int8_t cur_op, int *i, int j)
{
	char	*num;
	
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

void		write_ind(t_asm_content **content, u_int8_t cur_op, int *i, int j)
{
	char	*num;

	num = ft_itoa(get_num_from_nbyte(content, i, IND_SIZE));
	ft_strcpy((*content)->buf + (*content)->b_pos, num);
	(*content)->b_pos += ft_strlen(num);
	j + 1 != op_tab[cur_op].args_num ?
						(*content)->buf[(*content)->b_pos++] = ',' : 0;
	(*content)->buf[(*content)->b_pos++] = ' ';
	free(num);
}
