/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interaction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 12:37:07 by evallee-          #+#    #+#             */
/*   Updated: 2023/03/30 17:06:02 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities.h"
#include "assets.h"

void	collect(uint32_t ent)
{
	t_c_sprt	*sprt;
	mlx_image_t	*img;

	sprt = ecs_comp_get(ent, COMP_SPRITE);
	img = assets_get(sprt->asset);
	img->instances[sprt->insts[sprt->asset]].enabled = false;
	ecs_remove(ent);
}

void	interact(uint32_t ent1, uint32_t ent2)
{
	t_c_coll	*entcomp1;
	t_c_coll	*entcomp2;

	entcomp1 = ecs_comp_get(ent1, COMP_COLLISION);
	entcomp2 = ecs_comp_get(ent2, COMP_COLLISION);
	if ((entcomp1->flags & FLAG_PLAYER) && (entcomp2->flags & FLAG_COLLECTIBLE))
		collect(ent2);
}
