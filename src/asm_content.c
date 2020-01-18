/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_content.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 19:01:11 by idunaver          #+#    #+#             */
/*   Updated: 2020/01/18 19:01:12 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_asm_content	*init_content(int fd)
{
	t_asm_content	*content;

	content = (t_asm_content *)ft_memalloc(sizeof(t_asm_content));
	content->fd = fd;
	content->line = NULL;
	content->tokens = NULL;
	content->name = NULL;
	content->comment = NULL;
	return (content);
}
