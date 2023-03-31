/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectible.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 18:22:51 by niceguy           #+#    #+#             */
/*   Updated: 2023/03/31 18:42:33 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities.h"

void	*collectible_new(va_list args)
{
	t_c_collect	*collect;

	collect = malloc(sizeof(t_c_collect));
	if (!collect)
		return (NULL);
	collect->type = va_arg(args, int32_t);
	return (collect);
}

void	collectible_free(void	*ptr)
{
	free(ptr);
}

void	comp_collect_reg(void)
{
	ecs_comp_register(COMP_COLLECTIBLE, &collectible_new, &collectible_free);
}
