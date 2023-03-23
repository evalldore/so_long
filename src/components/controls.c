/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 21:16:41 by niceguy           #+#    #+#             */
/*   Updated: 2023/03/23 01:35:46 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities.h"

void	*control_new(va_list args)
{
	(void)args;
	return (malloc(sizeof(comp_ctrl_t)));
}

void	control_free(void	*ptr)
{
	free(ptr);
}

void	comp_ctrl_reg()
{
	ecs_comp_register(COMP_CTRL, &control_new, &control_free);
}
