/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 02:30:19 by niceguy           #+#    #+#             */
/*   Updated: 2023/03/24 03:33:49 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "assets.h"
#include "entities.h"

void	sys_sprites(mlx_t *mlx)
{
	comp_pos_t		*pos;
	comp_sprite_t	*sprite;
	ent_id_t		ent;
	mlx_image_t		*img;
	int32_t			inst;

	ent = 0;
	while (ent < ecs_num())
	{
		pos = ecs_comp_get(ent, COMP_POS);
		sprite = ecs_comp_get(ent, COMP_SPRITE);
		if (pos && sprite)
		{
			if (sprite->last_asset != sprite->asset)
			{
				img = assets_get(sprite->last_asset);
				if (sprite->insts[sprite->last_asset] >= 0)
					img->instances[sprite->insts[sprite->last_asset]].enabled = false;
			}
			img = assets_get(sprite->asset);
			inst = sprite->insts[sprite->asset];
			if (inst < 0)
			{
				inst = mlx_image_to_window(mlx, img, pos->curr.x + sprite->offset.x, pos->curr.y + sprite->offset.y);
				sprite->insts[sprite->asset] = inst;
				continue ;
			}
			img->instances[inst].enabled = true;
			img->instances[inst].x = pos->curr.x + sprite->offset.x;
			img->instances[inst].y = pos->curr.y + sprite->offset.y;
			sprite->last_asset = sprite->asset;
		}
		ent++;
	}
}