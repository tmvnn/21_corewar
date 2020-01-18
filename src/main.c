/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 19:17:35 by idunaver          #+#    #+#             */
/*   Updated: 2020/01/18 19:18:00 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	main(int argc, char **argv)
{
	if (argc == 0)
		error();
	if (valid_filename_asm(*(argv + 1)))
		assemble(*(argv + 1));
	else
		error();
	return (0);
}
