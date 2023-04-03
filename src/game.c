/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 22:46:09 by niceguy           #+#    #+#             */
/*   Updated: 2023/04/03 18:18:47 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static t_gamestate	g_gamestate;

t_gamestate	game_get(void)
{
	return (g_gamestate);
}

void	game_add_player(t_uvec start)
{
	t_dvec	pos;

	pos.x = (start.x * TILE_SIZE) + (TILE_SIZE / 2);
	pos.y = (start.y + 1) * TILE_SIZE;
	g_gamestate.player = entities_player(pos.x, pos.y);
}

void	game_add_collectible(void)
{
	t_map	map;

	map = map_get();
	g_gamestate.collected++;
	ft_printf("%d/%d\n", g_gamestate.collected, map.num_coll);
}
