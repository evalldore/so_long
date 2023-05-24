/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectible.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 18:22:51 by niceguy           #+#    #+#             */
/*   Updated: 2023/05/24 00:31:02 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities.h"

void	collect_new(void *ptr, va_list args)
{
	t_c_collect	*collect;

	collect = ptr;
	collect->type = va_arg(args, int32_t);
}

void	comp_collect_reg(void)
{
	size_t	size;

	size = sizeof(t_c_collect);
	ecs_comp_register(COMP_COLLECTIBLE, size, &collect_new, NULL);
}
