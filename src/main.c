/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 19:17:35 by idunaver          #+#    #+#             */
/*   Updated: 2020/02/16 16:57:50 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	main(int argc, char **argv)
{
	t_asm_content	*content;

	content = NULL;
	if (argc == 0)
		error(content);
	if (file(*(argv + 1), &content))
		assemble(&content);
	else
		error(content);
	return (0);
}
