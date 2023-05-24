/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 05:17:57 by niceguy           #+#    #+#             */
/*   Updated: 2023/05/24 00:30:54 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities.h"

void	ai_new(void *ptr, va_list args)
{
	t_c_ai	*ai;

	(void)args;
	ai = ptr;
	ai->attacking = false;
}

void	comp_ai_reg(void)
{
	size_t	size;

	size = sizeof(t_c_ai);
	ecs_comp_register(COMP_AI, size, &ai_new, NULL);
}
