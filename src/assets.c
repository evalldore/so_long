/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 05:06:31 by niceguy           #+#    #+#             */
/*   Updated: 2023/03/23 00:52:30 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assets.h"

static t_assets	g_assets;

static void	assets_load(mlx_t *mlx, enum e_asset ID, const char *path)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(path);
	if (!texture)
		return ;
	g_assets.textures[ID] = texture;
	g_assets.images[ID] = mlx_texture_to_image(mlx, texture);
}

mlx_image_t	*assets_get(enum e_asset ID)
{
	return (g_assets.images[ID]);
}

void	assets_init(mlx_t *mlx)
{
	assets_load(mlx, ASSET_SAM_IDLE, "assets/idle.png");
	assets_load(mlx, ASSET_SAM_WALK1, "assets/walk_1.png");
	assets_load(mlx, ASSET_SAM_WALK2, "assets/walk_2.png");
	assets_load(mlx, ASSET_SAM_WALK3, "assets/walk_3.png");
}
