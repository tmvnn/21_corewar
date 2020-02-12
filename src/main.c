/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timuryakubov <timuryakubov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 19:17:35 by idunaver          #+#    #+#             */
/*   Updated: 2020/02/11 17:53:10 by timuryakubo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	main(int argc, char **argv)
{
	t_asm_content	*content;
	
	if (argc == 0)
		error();
	if (file(*(argv + 1), &content))
		if (content->asm_dsm_flag == ASSEMBLE)
			assemble(*(argv + 1), &content);
		else
			disassemble(*(argv + 1), &content);
	else
		error();
	return (0);
}
