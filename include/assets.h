/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 05:07:51 by niceguy           #+#    #+#             */
/*   Updated: 2023/03/24 02:28:20 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSETS_H
# define ASSETS_H
# include <MLX42/MLX42.h>
# include <stdlib.h>

enum	e_asset
{
	ASSET_NONE,
	ASSET_SAM_IDLE,
	ASSET_SAM_WALK1,
	ASSET_SAM_WALK2,
	ASSET_SAM_WALK3,
	MAX_ASSETS
};

enum	e_anim
{
	ANIM_IDLE,
	ANIM_WALK,
	ANIM_JUMP,
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