/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 02:30:19 by niceguy           #+#    #+#             */
/*   Updated: 2023/03/23 02:35:50 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assets.h"
#include "entities.h"

void	sys_sprites(double dt)
{
	comp_pos_t		*pos;
	comp_sprite_t	*sprite;
	ent_id_t		ent;
	mlx_image_t		*img;

	(void)dt;
	ent = 0;
	while (ent < ecs_num())
	{
		pos = ecs_comp_get(ent, COMP_POS);
		sprite = ecs_comp_get(ent, COMP_SPRITE);
		if (pos && sprite)
		{
			img = assets_get(sprite->asset);
			img->instances[sprite->inst].x = pos->curr.x + sprite->offset.x;
			img->instances[sprite->inst].y = pos->curr.y + sprite->offset.y;
		}
		ent++;
	}
}