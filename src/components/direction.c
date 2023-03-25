/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:10:30 by evallee-          #+#    #+#             */
/*   Updated: 2023/03/24 18:06:32 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities.h"

void	*direction_new(va_list args)
{
	comp_dir_t	*dir;

	dir = malloc(sizeof(comp_dir_t));
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
