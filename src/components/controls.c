/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 21:16:41 by niceguy           #+#    #+#             */
/*   Updated: 2023/03/19 06:39:35 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities.h"

void	*control_new(ent_id_t ent_id)
{
	comp_ctrl_t	*comp;

	if (ent_id >= MAX_ENTS)
		return (NULL);
	comp = malloc(sizeof(comp_ctrl_t));
	if (!comp)
		return (NULL);
	return (comp);
}

void	control_free(ent_id_t ent_id)
{
	if (ent_id >= MAX_ENTS)
		return ;
	free(ecs_comp_get(COMP_CTRL, ent_id));
}

void	comp_ctrl_reg()
{
	ecs_comp_register(COMP_CTRL, &control_new, &control_free);
}
