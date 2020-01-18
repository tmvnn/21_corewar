/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filename.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 19:12:24 by idunaver          #+#    #+#             */
/*   Updated: 2020/01/18 19:12:59 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	valid_filename_asm(const char *filename)
{
	int	filename_len;

	if (!filename || (filename_len = ft_strlen(filename)) == 0 ||
	ft_strcmp((filename + filename_len - EXP_ASM_LEN), EXP_ASM))
		error();
	return (1);
}
