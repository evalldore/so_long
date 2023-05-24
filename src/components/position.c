/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 21:16:41 by niceguy           #+#    #+#             */
/*   Updated: 2023/05/24 00:35:35 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities.h"

void	position_new(void *ptr, va_list args)
{
	t_c_pos	*pos;

	pos = ptr;
	pos->curr.x = va_arg(args, double);
	pos->curr.y = va_arg(args, double);
	pos->last.x = pos->curr.x;
	pos->last.y = pos->curr.y;
}

void	comp_pos_reg(void)
{
	size_t	size;

	size = sizeof(t_c_pos);
	ecs_comp_register(COMP_POS, size, &position_new, NULL);
}
