/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_chmp_exec_code.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timuryakubov <timuryakubov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:08:16 by timuryakubo       #+#    #+#             */
/*   Updated: 2020/02/13 19:16:44 by timuryakubo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"



void	parse_chmp_exec_code(char *buff, int *b_pos, t_asm_content **content)
{
	/*unsigned char	rbyte;
	int 			i;
	
	i = -1;
	while (++i < (*content)->exec_code_size)
	{
		if (read((*content)->fd_src, &rbyte, 1) < 0)
			error();
		printf("%s\n", "op_tab[]");
	}*/
	(*content)->fd_src += 0;
	buff[*b_pos] = 0;
}