/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 01:21:37 by niceguy           #+#    #+#             */
/*   Updated: 2023/03/27 17:19:52 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities.h"

void	*state_new(va_list args)
{
	t_c_state	*state;

	state = malloc(sizeof(t_c_state));
	if (!state)
		return (NULL);
	state->curr = va_arg(args, int32_t);
	state->last = state->curr;
	return (state);
}

void	state_free(void	*ptr)
{
	free(ptr);
}

void	comp_state_reg(void)
{
	ecs_comp_register(COMP_STATE, &state_new, &state_free);
}
