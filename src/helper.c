/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 21:30:23 by idunaver          #+#    #+#             */
/*   Updated: 2020/01/18 19:20:21 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
* К функциональности проекта не относится.
*/

#include "asm.h"

void	what_are_tokens(t_token *token)
{
	while (token != NULL)
	{
		printf("token:%s\n", token->content);
		token = token->next;
	}
}
