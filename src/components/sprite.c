/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 00:53:17 by niceguy           #+#    #+#             */
/*   Updated: 2023/04/02 21:48:45 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assets.h"
#include "entities.h"
#include <libft.h>

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
	while (inst < MAX_ASSETS)
		sprite->insts[inst++] = -1;
	return (sprite);
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
		ft_printf("sprite asset: %d sprite inst: %d\n", sprt->asset, inst);
		if (inst > -1)
			img->instances[inst].enabled = false;
	}
	free(sprt);
}

void	comp_sprite_reg(void)
{
	ecs_comp_register(COMP_SPRITE, &sprite_new, &sprite_free);
}
