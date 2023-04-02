/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 22:46:09 by niceguy           #+#    #+#             */
/*   Updated: 2023/04/01 23:25:16 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static t_gamestate	g_gamestate;

t_gamestate	game_get(void)
{
	return (g_gamestate);
}

void	game_set_player(uint32_t ent)
{
	g_gamestate.player = ent;
}

void	game_add_collectible()
{
	g_gamestate.collected++;
}