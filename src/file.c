/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellona <lbellona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 19:12:24 by idunaver          #+#    #+#             */
/*   Updated: 2020/02/16 19:07:32 by lbellona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	create_f(const char *filename, int only_name_len, char *file_type,
														t_asm_content **content)
{
	char	*new_filename;
	int		type_len;

	type_len = file_type[1] == 's' ? EXP_ASM_LEN : EXP_COR_LEN;
	*content = init_content(file_type[1]);
	new_filename = (char *)ft_memalloc((only_name_len + type_len + 1) *
																sizeof(char));
	ft_strcat(ft_memcpy(new_filename, filename, only_name_len), file_type);
	if (!((*content)->fd_dst = open(new_filename, O_CREAT | O_RDWR, 0644)))
		error();
	ft_strdel(&new_filename);
	return (1);
}

int	file(const char *filename, t_asm_content **content)
{
	int		filename_len;
	int		only_name_len;

	filename_len = 0;
	if (!filename || (filename_len = ft_strlen(filename)) == 0)
		error();
	only_name_len = filename_len - ft_strlen(ft_strchr(filename, '.'));
	if (!ft_strcmp((filename + only_name_len), EXP_ASM) && only_name_len > 0)
	{
		create_f(filename, only_name_len, EXP_COR, content);
	}
	else if (!ft_strcmp((filename + only_name_len), EXP_COR) &&
															only_name_len > 0)
	{
		create_f(filename, only_name_len, EXP_ASM, content);
	}
	else
		error();
	return (1);
}
