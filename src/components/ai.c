/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 05:17:57 by niceguy           #+#    #+#             */
/*   Updated: 2023/04/03 18:20:10 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities.h"

void	*ai_new(va_list args)
{
	t_c_ai	*ai;

	(void)args;
	ai = malloc(sizeof(t_c_ai));
	if (!ai)
		return (NULL);
	ai->attacking = false;
	return (ai);
}

void	ai_free(void	*ptr)
{
	free(ptr);
}

void	comp_ai_reg(void)
{
	ecs_comp_register(COMP_AI, &ai_new, &ai_free);
}
