/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projectiles.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 04:43:38 by niceguy           #+#    #+#             */
/*   Updated: 2023/03/31 05:13:04 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assets.h"
#include "entities.h"

void	sys_projectiles(uint32_t ent, va_list args)
{
	t_c_project		*project;
	t_c_sprt		*sprt;
	mlx_image_t		*img;

	project = ecs_comp_get(ent, COMP_PROJECTILE);
	if (!project)
		return ;
	project->time += va_arg(args, double);
	if (project->time > 0.3)
	{
		sprt = ecs_comp_get(ent, COMP_SPRITE);
		img = assets_get(sprt->asset);
		img->instances[sprt->insts[sprt->asset]].enabled = false;
		ecs_remove(ent);
	}
}

void	shoot(uint32_t	player)
{
	t_c_pos		*pos;
	t_c_dir		*dir;

	pos = ecs_comp_get(player, COMP_POS);
	dir	= ecs_comp_get(player, COMP_DIRECTION);
	if (!pos || !dir)
		return ;
	entities_projectile(pos->curr.x, pos->curr.y - 24.0, dir->curr);
}