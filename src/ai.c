/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 05:20:46 by niceguy           #+#    #+#             */
/*   Updated: 2023/03/31 19:28:11 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities.h"

static bool find_player(uint32_t ent, uint32_t player)
{
	(void)ent;
	(void)player;
	return (false);
}

void	sys_ai(uint32_t ent, va_list	args)
{
	t_c_ai	*ai;

	(void)args;
	ai = ecs_comp_get(ent, COMP_AI);
	if (!ai)
		return ;
	if (!ai->attacking)
		ai->attacking = find_player(ent, va_arg(args, uint32_t));
}