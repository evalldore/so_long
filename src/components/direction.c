/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:10:30 by evallee-          #+#    #+#             */
/*   Updated: 2023/03/27 17:19:34 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities.h"

void	*direction_new(va_list args)
{
	t_c_dir	*dir;

	dir = malloc(sizeof(t_c_dir));
	if (!dir)
		return (NULL);
	dir->curr = va_arg(args, int);
	return (dir);
}

void	direction_free(void	*ptr)
{
	free(ptr);
}

void	comp_dir_reg(void)
{
	ecs_comp_register(COMP_DIRECTION, &direction_new, &direction_free);
}
