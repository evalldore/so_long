/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 01:21:37 by niceguy           #+#    #+#             */
/*   Updated: 2023/05/24 00:31:43 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities.h"

void	state_new(void *ptr, va_list args)
{
	t_c_state	*state;

	state = ptr;
	state->curr = va_arg(args, int32_t);
	state->last = state->curr;
}

void	comp_state_reg(void)
{
	size_t	size;

	size = sizeof(t_c_state);
	ecs_comp_register(COMP_STATE, size, &state_new, NULL);
}
