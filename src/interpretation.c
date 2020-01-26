/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpretation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 13:35:43 by idunaver          #+#    #+#             */
/*   Updated: 2020/01/26 15:35:31 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	check_label(t_token **tokens)
{
	char	*copy;

	copy = (*tokens)->content;
	ft_right_trim(copy);
	if (*(copy + ft_strlen(copy) - 1) == ':')
		(*tokens)->type = ft_strdup(LABEL);
}

void	interpretation(t_token **tokens)
{
	check_label(tokens);
}
