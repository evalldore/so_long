/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 02:30:19 by niceguy           #+#    #+#             */
/*   Updated: 2023/03/28 04:07:01 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "assets.h"
#include "entities.h"

static void	last_frame(t_c_sprt	*sprite)
{
	mlx_image_t		*img;

	if (sprite->last_asset == sprite->asset)
		return ;
	img = assets_get(sprite->last_asset);
	if (sprite->insts[sprite->last_asset] >= 0)
		img->instances[sprite->insts[sprite->last_asset]].enabled = false;
}

static int32_t	check_instance(mlx_t *mlx, mlx_image_t *img, t_c_sprt *sprite)
{
	int32_t			inst;

	inst = sprite->insts[sprite->asset];
	ft_printf("check %p/%p\n", img, mlx);
	if (inst >= 0)
		return (inst);
	inst = mlx_image_to_window(mlx, img, 0, 0);
	sprite->insts[sprite->asset] = inst;
	return (inst);
}

void	sys_sprites(uint32_t ent, va_list args)
{
	t_c_pos			*pos;
	t_c_sprt		*sprite;
	mlx_image_t		*img;
	int32_t			inst;
	mlx_t			*mlx;

	mlx = va_arg(args, void *);
	pos = ecs_comp_get(ent, COMP_POS);
	sprite = ecs_comp_get(ent, COMP_SPRITE);
	if (!pos || !sprite)
		return ;
	last_frame(sprite);
	img = assets_get(sprite->asset);
	inst = check_instance(mlx, img, sprite);
	img->instances[inst].enabled = true;
	img->instances[inst].x = pos->curr.x + sprite->offset.x;
	img->instances[inst].y = pos->curr.y + sprite->offset.y;
	sprite->last_asset = sprite->asset;
}
