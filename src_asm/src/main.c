/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperra-f <yperra-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 19:26:39 by idunaver          #+#    #+#             */
/*   Updated: 2020/02/20 19:44:05 by yperra-f         ###   ########.fr       */
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
	{
		if (content->asm_dsm_flag == ASSEMBLE)
			assemble(&content);
		else
			disassemble(&content);
	}
	else
		error(content);
	return (0);
}
