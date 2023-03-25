/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 05:07:51 by niceguy           #+#    #+#             */
/*   Updated: 2023/03/24 17:44:32 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSETS_H
# define ASSETS_H
# include <MLX42/MLX42.h>
# include <stdlib.h>

enum	e_asset
{
	ASSET_NONE,
	ASSET_SAM_IDLE_R,
	ASSET_SAM_WALK_R_1,
	ASSET_SAM_WALK_R_2,
	ASSET_SAM_WALK_R_3,
	ASSET_SAM_IDLE_L,
	ASSET_SAM_WALK_L_1,
	ASSET_SAM_WALK_L_2,
	ASSET_SAM_WALK_L_3,
	MAX_ASSETS
};

enum	e_anim
{
	ANIM_IDLE_R,
	ANIM_WALK_R,
	ANIM_JUMP_R,
	ANIM_IDLE_L,
	ANIM_WALK_L,
	ANIM_JUMP_L,
	MAX_ANIM
};

typedef struct s_assets
{
	mlx_texture_t	*textures[MAX_ASSETS];
	mlx_image_t		*images[MAX_ASSETS];
}	t_assets;

mlx_image_t	*assets_get(int32_t	asset);
void		assets_init(mlx_t *mlx);

#endif