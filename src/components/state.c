/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 01:21:37 by niceguy           #+#    #+#             */
/*   Updated: 2023/03/24 01:56:16 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities.h"

void	*state_new(va_list args)
{
	comp_state_t	*state;

	state = malloc(sizeof(comp_state_t));
	if (!state)
		return (NULL);
	state->curr = va_arg(args, int32_t);
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
