/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:10:30 by evallee-          #+#    #+#             */
/*   Updated: 2023/05/24 00:31:18 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities.h"

void	direction_new(void *ptr, va_list args)
{
	t_c_dir	*dir;

	dir = ptr;
	dir->curr = va_arg(args, int);
}

void	comp_dir_reg(void)
{
	size_t	size;

	size = sizeof(t_c_dir);
	ecs_comp_register(COMP_DIRECTION, size, &direction_new, NULL);
}
