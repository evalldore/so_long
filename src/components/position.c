/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 21:16:41 by niceguy           #+#    #+#             */
/*   Updated: 2023/03/27 17:15:14 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities.h"

void	*position_new(va_list args)
{
	t_c_pos	*pos;

	pos = malloc(sizeof(t_c_pos));
	if (!pos)
		return (NULL);
	pos->curr.x = va_arg(args, double);
	pos->curr.y = va_arg(args, double);
	pos->last.x = pos->curr.x;
	pos->last.y = pos->curr.y;
	return (pos);
}

void	position_free(void	*ptr)
{
	free(ptr);
}

void	comp_pos_reg(void)
{
	ecs_comp_register(COMP_POS, &position_new, &position_free);
}
