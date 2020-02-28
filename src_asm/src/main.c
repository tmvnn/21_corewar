/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timuryakubov <timuryakubov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 19:26:39 by idunaver          #+#    #+#             */
/*   Updated: 2020/02/28 22:20:26 by timuryakubo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	main(int argc, char **argv)
{
	t_asm_content	*content;

	content = NULL;
	if (argc != 2)
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
