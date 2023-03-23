/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 00:53:17 by niceguy           #+#    #+#             */
/*   Updated: 2023/03/23 02:27:59 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities.h"

void	*sprite_new(va_list args)
{
	comp_sprite_t	*sprite;

	sprite = malloc(sizeof(comp_sprite_t));
	if (!sprite)
		return (NULL);
	sprite->asset = va_arg(args, int32_t);
	sprite->inst = va_arg(args, int32_t);
	sprite->offset.x = va_arg(args, double);
	sprite->offset.y = va_arg(args, double);
	return (sprite);
}

void	sprite_free(void	*ptr)
{
	free(ptr);
}

void	comp_sprite_reg()
{
	ecs_comp_register(COMP_SPRITE, &sprite_new, &sprite_free);
}