/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 21:47:33 by niceguy           #+#    #+#             */
/*   Updated: 2023/03/20 21:18:17 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ecs.h"

static ent_id_t	G_ENTITIES;

ent_id_t	ecs_num()
{
	return (G_ENTITIES);
}

ent_id_t	ecs_create()
{
	if (G_ENTITIES >= MAX_ENTS)
		return (-1);
	return (G_ENTITIES++);
}

void	ecs_iterate(void (*f)(ent_id_t))
{
	ent_id_t	ent_id;

	if (!f)
		return ;
	ent_id = 0;
	while(ent_id < G_ENTITIES)
		f(ent_id++);
}
