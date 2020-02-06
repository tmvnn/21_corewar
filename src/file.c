/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 19:12:24 by idunaver          #+#    #+#             */
/*   Updated: 2020/02/06 21:57:09 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	file(const char *filename, t_asm_content **content)
{
	int	filename_len;

	if (!filename || (filename_len = ft_strlen(filename)) == 0 ||
	ft_strcmp((filename + filename_len - EXP_ASM_LEN), EXP_ASM))
		error();
	*content = init_content();
	printf("%s\n", filename);
	if (!((*content)->fd_dst = open(filename, O_CREAT | O_RDWR, 0644)))
		error();
	return (1);
}
