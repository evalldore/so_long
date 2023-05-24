/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 21:16:41 by niceguy           #+#    #+#             */
/*   Updated: 2023/05/24 00:31:14 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities.h"

void	control_new(void *ptr, va_list args)
{
	t_c_ctrl	*ctrl;

	(void)args;
	ctrl = ptr;
	ctrl->jump = false;
	ctrl->left = false;
	ctrl->right = false;
	ctrl->shoot = false;
	ctrl->lastshoot = false;
}

void	comp_ctrl_reg(void)
{
	size_t	size;

	size = sizeof(t_c_ctrl);
	ecs_comp_register(COMP_CTRL, size, &control_new, NULL);
}
