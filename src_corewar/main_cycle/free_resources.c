/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_resources.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanton <astanton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 14:27:40 by astanton          #+#    #+#             */
/*   Updated: 2020/02/05 04:55:30 by astanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	free_carriages(t_carriage *carriages)
{
	t_carriage	*current;

	current = carriages;
	while (current)
	{
		carriages = carriages->next;
		free(current);
		current = carriages;
	}
}

static void	free_players(t_player *players)
{
	t_player	*tmp;

	tmp = players;
	while (tmp)
	{
		players = players->next;
		free(tmp->name);
		free(tmp->code);
		free(tmp->comment);
		free(tmp);
		tmp = players;
	}
}

void		free_resources(t_game game)
{
	if (game.carriages)
		free_carriages(game.carriages);
	if (game.players)
		free_players(game.players);
	free(game.field);
}
