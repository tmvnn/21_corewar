/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellona <lbellona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 19:17:35 by idunaver          #+#    #+#             */
/*   Updated: 2020/02/16 19:18:03 by lbellona         ###   ########.fr       */
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
