/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 00:53:17 by niceguy           #+#    #+#             */
/*   Updated: 2023/03/23 20:38:59 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assets.h"
#include "entities.h"

void	*sprite_new(va_list args)
{
	comp_sprite_t	*sprite;

	sprite = malloc(sizeof(comp_sprite_t));
	if (!sprite)
		return (NULL);
	sprite->asset = va_arg(args, int32_t);
	sprite->offset.x = va_arg(args, double);
	sprite->offset.y = va_arg(args, double);
	sprite->insts = malloc((MAX_ASSETS - 1) * sizeof(int32_t));
	return (sprite);
}

void	sprite_free(void	*ptr)
{
	comp_sprite_t	*sprite;

	sprite = (comp_sprite_t *)ptr;
	free(sprite->insts);
	free(sprite);
}

void	comp_sprite_reg(void)
{
	ecs_comp_register(COMP_SPRITE, &sprite_new, &sprite_free);
}
