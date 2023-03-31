/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projectile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 04:37:45 by niceguy           #+#    #+#             */
/*   Updated: 2023/03/31 05:24:39 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities.h"
#include "libft.h"

void	*projectile_new(va_list args)
{
	t_c_project	*project;

	(void)args;
	project = malloc(sizeof(t_c_project));
	if (!project)
		return (NULL);
	project->time = 0.0;
	return (project);
}

void	projectile_free(void	*ptr)
{
	free(ptr);
}

void	comp_project_reg(void)
{
	ecs_comp_register(COMP_PROJECTILE, &projectile_new, &projectile_free);
}
