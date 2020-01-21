/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 21:13:59 by idunaver          #+#    #+#             */
/*   Updated: 2020/01/21 21:28:33 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void    add_string(t_token **tokens, t_strings **row)
{
	t_strings *copy;
	t_strings *new;

	copy = *row;
	if (!copy)
	{
		if (!(*row = (t_strings *)ft_memalloc(sizeof(t_strings))))
			error();
		(*row)->string = *tokens;
		(*row)->next = NULL;
	}
	else
	{
		if (!(new = (t_strings *)ft_memalloc(sizeof(t_strings))))
			error();
		new->string = *tokens;
		new->next = NULL;
		while (copy->next)
			copy = copy->next;
		copy->next = new;
	}
}