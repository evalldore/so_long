/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:47:27 by evallee-          #+#    #+#             */
/*   Updated: 2023/03/24 00:06:18 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities.h"

void	*animation_new(va_list args)
{
	comp_anim_t	*anim;

	anim = malloc(sizeof(comp_anim_t));
	if (!anim)
		return (NULL);
	anim->index = va_arg(args, int32_t);
	anim->frame = 0;
	anim->time = 0.0;
	return (anim);
}

void	animation_free(void	*ptr)
{
	free(ptr);
}

void	comp_anim_reg(void)
{
	ecs_comp_register(COMP_ANIM, &animation_new, &animation_free);
}
