/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 00:53:17 by niceguy           #+#    #+#             */
/*   Updated: 2023/05/24 00:31:38 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assets.h"
#include "entities.h"
#include <libft.h>

void	sprite_new(void *ptr, va_list args)
{
	t_c_sprt	*sprite;
	int32_t		inst;

	inst = 0;
	sprite = ptr;
	sprite->asset = va_arg(args, int32_t);
	sprite->last_asset = sprite->asset;
	sprite->offset.x = va_arg(args, double);
	sprite->offset.y = va_arg(args, double);
	while (inst < MAX_ASSETS)
		sprite->insts[inst++] = -1;
}

void	sprite_free(void	*ptr)
{
	t_c_sprt	*sprt;
	mlx_image_t	*img;
	int32_t		inst;

	sprt = ptr;
	if (sprt->asset > 0 && sprt->asset < MAX_ASSETS)
	{
		img = assets_get(sprt->asset);
		inst = sprt->insts[sprt->asset];
		if (inst > -1)
			img->instances[inst].enabled = false;
	}
}

void	comp_sprite_reg(void)
{
	size_t	size;

	size = sizeof(t_c_sprt);
	ecs_comp_register(COMP_SPRITE, size, &sprite_new, sprite_free);
}
