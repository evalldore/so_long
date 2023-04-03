/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 05:20:46 by niceguy           #+#    #+#             */
/*   Updated: 2023/04/03 18:18:05 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities.h"
#include "coordinates.h"
#include "map.h"
#include "utils.h"

bool	check_tile(uint32_t x, uint32_t y)
{
	return (map_get().data[y][x] != '1');
}

static bool	find_player(uint32_t ent, uint32_t player)
{
	t_c_pos	*entpos;
	t_c_pos	*playerpos;
	t_uvec	coords[2];

	entpos = ecs_comp_get(ent, COMP_POS);
	playerpos = ecs_comp_get(player, COMP_POS);
	if (!entpos || !playerpos)
		return (false);
	coords[0] = pos_to_coords(entpos->curr.x, entpos->curr.y);
	coords[1] = pos_to_coords(playerpos->curr.x, playerpos->curr.y - 24);
	return (line_coords(coords[0], coords[1], &check_tile));
}

static void	move_to_player(uint32_t ent, uint32_t player)
{
	t_c_pos	*pos;
	t_c_vel	*vel;
	t_c_pos	*pp;
	t_dvec	norm;

	pos = ecs_comp_get(ent, COMP_POS);
	vel = ecs_comp_get(ent, COMP_VEL);
	pp = ecs_comp_get(player, COMP_POS);
	if (!pos || !vel || !pp)
		return ;
	norm = normalize(pp->curr.x - pos->curr.x, (pp->curr.y - 24) - pos->curr.y);
	vel->curr.x += norm.x * 10.0;
	vel->curr.y += norm.y * 10.0;
	vel->curr.x = clamp(vel->curr.x, -90.0, 90.0);
	vel->curr.y = clamp(vel->curr.y, -90.0, 90.0);
}

void	sys_ai(uint32_t ent, va_list	args)
{
	t_c_ai		*ai;
	uint32_t	player;

	(void)args;
	ai = ecs_comp_get(ent, COMP_AI);
	if (!ai)
		return ;
	player = va_arg(args, uint32_t);
	if (!ai->attacking)
		ai->attacking = find_player(ent, player);
	else
		move_to_player(ent, player);
}
