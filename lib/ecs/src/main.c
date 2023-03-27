/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 21:47:33 by niceguy           #+#    #+#             */
/*   Updated: 2023/03/27 17:21:13 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ecs.h"

static uint32_t	G_ENTITIES;

uint32_t	ecs_num()
{
	return (G_ENTITIES);
}

uint32_t	ecs_create()
{
	if (G_ENTITIES >= MAX_ENTS)
		return (-1);
	return (G_ENTITIES++);
}

void	ecs_iterate(void (*f)(uint32_t))
{
	uint32_t	ent_id;

	if (!f)
		return ;
	ent_id = 0;
	while(ent_id < G_ENTITIES)
		f(ent_id++);
}
