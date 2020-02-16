/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 19:12:24 by idunaver          #+#    #+#             */
/*   Updated: 2020/02/16 16:52:21 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	file(const char *filename, t_asm_content **content)
{
	int		filename_len;
	char	*filename_dot_cor;

	filename_len = 0;
	if (!filename || (filename_len = ft_strlen(filename)) == 0 ||
	ft_strcmp((filename + filename_len - EXP_ASM_LEN), EXP_ASM))
		error(*content);
	*content = init_content();
	filename_dot_cor = (char *)ft_memalloc((filename_len + 3) * sizeof(char));
	ft_strcat(ft_memcpy(filename_dot_cor, filename, filename_len - 2), EXP_COR);
	if (!((*content)->fd_dst = open(filename_dot_cor, O_CREAT | O_RDWR, 0644)))
		error(*content);
	if (((*content)->fd_src = open(filename, O_RDONLY)) == -1)
		error(*content);
	ft_strdel(&filename_dot_cor);
	return (1);
}
