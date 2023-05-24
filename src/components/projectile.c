/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projectile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 04:37:45 by niceguy           #+#    #+#             */
/*   Updated: 2023/05/24 00:31:32 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities.h"
#include "libft.h"

void	projectile_new(void *ptr, va_list args)
{
	t_c_project	*project;

	(void)args;
	project = ptr;
	project->time = 0.0;
}

void	comp_project_reg(void)
{
	size_t	size;

	size = sizeof(t_c_project);
	ecs_comp_register(COMP_PROJECTILE, size, &projectile_new, NULL);
}
