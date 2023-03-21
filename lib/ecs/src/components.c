/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   components.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 00:14:52 by niceguy           #+#    #+#             */
/*   Updated: 2023/03/20 21:06:12 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ecs.h"

static component_t	G_COMPONENTS[MAX_COMP];

void	*ecs_comp_add(ent_id_t ent_id, int comp)
{
	void	*ptr;

	if (ent_id > ecs_num() || ent_id >= MAX_ENTS || comp >= MAX_COMP)
		return (NULL);
	ptr = G_COMPONENTS[comp].new(ent_id);
	G_COMPONENTS[comp].ptrs[ent_id] = ptr;
	return (ptr);
}

void	ecs_comp_remove(ent_id_t ent_id, int comp)
{
	if (ent_id > ecs_num() || ent_id >= MAX_ENTS || comp >= MAX_COMP)
		return ;
	G_COMPONENTS[comp].dest(ent_id);
	G_COMPONENTS[comp].ptrs[ent_id] = NULL;
}

void	*ecs_comp_get(ent_id_t ent_id, int comp)
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
