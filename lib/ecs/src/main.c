/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 21:47:33 by niceguy           #+#    #+#             */
/*   Updated: 2023/03/28 02:37:42 by niceguy          ###   ########.fr       */
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

void	ecs_iterate(void (*f)(uint32_t, va_list), ...)
{
	uint32_t	ent_id;
	va_list		args;

	if (!f)
		return ;
	ent_id = 0;
	va_start(args, f);
	while(ent_id < G_ENTITIES)
		f(ent_id++, args);
	va_end(args);
}
