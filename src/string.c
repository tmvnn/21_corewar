/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 21:13:59 by idunaver          #+#    #+#             */
/*   Updated: 2020/02/16 19:20:21 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void    add_string(t_token *tokens, t_strings *row, t_asm_content *content)
{
	t_strings *new;

	if (!row)
	{
		if (!(row = (t_strings *)ft_memalloc(sizeof(t_strings))))
			error(content);
		row->string = tokens;
		row->next = NULL;
		content->tokens = row;
	}
	else
	{
		if (!(new = (t_strings *)ft_memalloc(sizeof(t_strings))))
			error(content);
		new->string = tokens;
		new->next = NULL;
		while (row->next)
			row = row->next;
		row->next = new;
	}
}