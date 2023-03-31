/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 05:20:46 by niceguy           #+#    #+#             */
/*   Updated: 2023/03/31 05:27:11 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities.h"

void	sys_ai(uint32_t ent, va_list	args)
{
	t_c_ai	*ai;

	(void)args;
	ai = ecs_comp_get(ent, COMP_AI);
	if (!ai)
		return ;

}