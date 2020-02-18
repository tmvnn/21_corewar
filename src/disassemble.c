/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disassemble.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timuryakubov <timuryakubov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 19:06:42 by idunaver          #+#    #+#             */
/*   Updated: 2020/02/18 15:26:21 by timuryakubo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	disassemble(t_asm_content **content)
{
	(*content)->buf = (char *)ft_memalloc((BUFF_SIZE_FOR_DIS) * sizeof(char));
	if (file_is_binary((*content)->fd_src, content))
	{
		parse_name((*content)->buf, &((*content)->b_pos), (*content)->fd_src,
																	content);
		skip_null_bytes(content);
		parse_chmp_exec_code_size(content);
		parse_comment((*content)->buf, &((*content)->b_pos),
												(*content)->fd_src, content);
		skip_null_bytes(content);
		parse_chmp_exec_code(content);
		(*content)->buf[(*content)->b_pos] = 0;
		//ATTENTION!!!
		//ADD HERE OPEN & CREATE FILE FD_DST STRING FROM create_f FUNCTION!!!
		write((*content)->fd_dst, (*content)->buf, (*content)->b_pos);
		close((*content)->fd_dst);
	}
	else
		error(*content);
	free((*content)->buf);
	close((*content)->fd_src);
}
