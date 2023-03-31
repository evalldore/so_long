/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 00:53:17 by niceguy           #+#    #+#             */
/*   Updated: 2023/03/31 05:55:10 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assets.h"
#include "entities.h"

void	*sprite_new(va_list args)
{
	t_c_sprt	*sprite;
	int32_t		inst;

	sprite = malloc(sizeof(t_c_sprt));
	if (!sprite)
		return (NULL);
	inst = 0;
	sprite->asset = va_arg(args, int32_t);
	sprite->last_asset = sprite->asset;
	sprite->offset.x = va_arg(args, double);
	sprite->offset.y = va_arg(args, double);
	sprite->insts = malloc(MAX_ASSETS * sizeof(int32_t));
	while (inst < MAX_ASSETS)
		sprite->insts[inst++] = -1;
	return (sprite);
}

void	sprite_free(void	*ptr)
{
	t_c_sprt	*sprt;
	mlx_image_t	*img;

	sprt = ptr;
	img = assets_get(sprt->asset);
	img->instances[sprt->insts[sprt->asset]].enabled = false;
	free(sprt->insts);
	free(sprt);
}

void	comp_sprite_reg(void)
{
	ecs_comp_register(COMP_SPRITE, &sprite_new, &sprite_free);
}
