/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 21:16:41 by niceguy           #+#    #+#             */
/*   Updated: 2023/03/27 17:18:31 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities.h"

void	*control_new(va_list args)
{
	t_c_ctrl	*ctrl;

	(void)args;
	ctrl = malloc(sizeof(t_c_ctrl));
	if (!ctrl)
		return (NULL);
	ctrl->jump = false;
	ctrl->left = false;
	ctrl->right = false;
	ctrl->shoot = false;
	return (ctrl);
}

void	control_free(void	*ptr)
{
	free(ptr);
}

void	comp_ctrl_reg(void)
{
	ecs_comp_register(COMP_CTRL, &control_new, &control_free);
}
