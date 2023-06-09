/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 02:55:37 by niceguy           #+#    #+#             */
/*   Updated: 2023/04/06 08:07:58 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities.h"

void	sys_movement(uint32_t ent, va_list args)
{
	t_c_pos		*pos;
	t_c_vel		*vel;
	mlx_t		*mlx;

	mlx = va_arg(args, void *);
	pos = ecs_comp_get(ent, COMP_POS);
	vel = ecs_comp_get(ent, COMP_VEL);
	if (!pos || !vel)
		return ;
	pos->curr.x += vel->curr.x * mlx->delta_time;
	pos->curr.y += vel->curr.y * mlx->delta_time;
}
