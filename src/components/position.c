/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 21:16:41 by niceguy           #+#    #+#             */
/*   Updated: 2023/03/19 06:39:33 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities.h"

void	*position_new(ent_id_t ent_id)
{
	comp_pos_t	*comp;

	if (ent_id >= MAX_ENTS)
		return (NULL);
	comp = malloc(sizeof(comp_pos_t));
	if (!comp)
		return (NULL);
	return (comp);
}

void	position_free(ent_id_t ent_id)
{
	if (ent_id >= MAX_ENTS)
		return ;
	free(ecs_comp_get(COMP_POS, ent_id));
}

void	comp_pos_reg()
{
	ecs_comp_register(COMP_POS, &position_new, &position_free);
}
