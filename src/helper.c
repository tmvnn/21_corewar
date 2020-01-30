/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 21:30:23 by idunaver          #+#    #+#             */
/*   Updated: 2020/01/26 13:33:32 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
* К функциональности проекта не относится.
*/

#include "asm.h"

static void	what_are_tokens(t_token *token)
{

	while (token != NULL)
	{
		printf("%s [%s]", token->content, token->type);
		token = token->next;
		if (token)
			printf(", ");
	}
}

void		what_are_strings(t_strings *rows)
{
	while (rows != NULL)
	{
		printf("row: ");
		what_are_tokens(rows->string);
		printf(";\n");
		rows = rows->next;
	}
}
