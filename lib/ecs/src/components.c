/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   components.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 00:14:52 by niceguy           #+#    #+#             */
/*   Updated: 2023/03/27 17:21:13 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ecs.h"

static component_t	G_COMPONENTS[MAX_COMP];

void	*ecs_comp_add(uint32_t ent_id, int comp, int argc, ...)
{
	void	*ptr;
	va_list	args;

	if (ent_id > ecs_num() || ent_id >= MAX_ENTS || comp >= MAX_COMP)
		return (NULL);
	va_start(args, argc);
	ptr = G_COMPONENTS[comp].new(args);
	va_end(args);
	G_COMPONENTS[comp].ptrs[ent_id] = ptr;
	return (ptr);
}

void	ecs_comp_remove(uint32_t ent_id, int comp)
{
	if (ent_id > ecs_num() || ent_id >= MAX_ENTS || comp >= MAX_COMP)
		return ;
	G_COMPONENTS[comp].dest(G_COMPONENTS[comp].ptrs[ent_id]);
	G_COMPONENTS[comp].ptrs[ent_id] = NULL;
}

void	*ecs_comp_get(uint32_t ent_id, int comp)
{
	if (ent_id > ecs_num() || ent_id >= MAX_ENTS || comp >= MAX_COMP)
		return (NULL);
	return (G_COMPONENTS[comp].ptrs[ent_id]);
}

void	ecs_comp_register(int comp, constructor_t c, destructor_t d)
{
	if (comp >= MAX_COMP || !c || ! d)
		return ;
	G_COMPONENTS[comp].new = c;
	G_COMPONENTS[comp].dest = d;
}
