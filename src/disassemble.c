/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disassemble.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellona <lbellona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 19:06:42 by idunaver          #+#    #+#             */
/*   Updated: 2020/02/16 19:08:09 by lbellona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	disassemble(char *filename, t_asm_content **content)
{
	(*content)->buf = (char *)ft_memalloc((BUFF_SIZE_FOR_DIS) * sizeof(char));
	if (((*content)->fd_src = open(filename, O_RDONLY)) == -1)
		error();
	if (file_is_binary((*content)->fd_src))
	{
		parse_name((*content)->buf, &((*content)->b_pos), (*content)->fd_src);
		skip_null_bytes(content);
		parse_chmp_exec_code_size(content);
		parse_comment((*content)->buf, &((*content)->b_pos),
															(*content)->fd_src);
		skip_null_bytes(content);
		parse_chmp_exec_code(content);
		(*content)->buf[(*content)->b_pos] = 0;
		write((*content)->fd_dst, (*content)->buf, (*content)->b_pos);
		close((*content)->fd_dst);
	}
	else
		error();
	close((*content)->fd_src);
}
