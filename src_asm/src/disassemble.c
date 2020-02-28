/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disassemble.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timuryakubov <timuryakubov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 19:06:42 by idunaver          #+#    #+#             */
/*   Updated: 2020/02/28 20:27:29 by timuryakubo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	disassemble(t_asm_content **content)
{
	if (!((*content)->buf = (char *)ft_memalloc((BUFF_SIZE_FOR_DIS) * \
	sizeof(char))))
		error(*content);
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
		if (!((*content)->fd_dst = open((*content)->new_filename, \
		O_TRUNC | O_CREAT | O_RDWR, 0644)))
			error(*content);
		write((*content)->fd_dst, (*content)->buf, (*content)->b_pos);
		print_output_str(content);
	}
	else
		error(*content);
	clean_memory(content);
}
