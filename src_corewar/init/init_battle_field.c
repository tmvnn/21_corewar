/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_battle_field.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanton <astanton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 17:08:03 by astanton          #+#    #+#             */
/*   Updated: 2020/02/11 20:19:11 by astanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_game		init_game(void)
{
	t_game	game;

	game.field = (unsigned char *)malloc(sizeof(unsigned char) * (MEM_SIZE));
	if (!game.field)
		ft_print_error_message("Memory for field is not allocated.", NULL);
	ft_bzero(game.field, (MEM_SIZE));
	game.carriages = NULL;
	game.last_check_cycle = 0;
	game.last_survivor = 0;
	game.dump = 0;
	game.visualization = 0;
	game.current_cycle = 0;
	game.number_of_checks = 0;
	game.number_of_live_instructions = 0;
	game.cycles_to_die = CYCLE_TO_DIE;
	game.aff = 0;
	return (game);
}
