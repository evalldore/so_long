/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 21:20:54 by niceguy           #+#    #+#             */
/*   Updated: 2023/03/26 06:47:38 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "entities.h"
#include "assets.h"

static gamestate_t	g_gamestate;

void	sl_init(mlx_t *mlx, char *path)
{
	t_coord		coords;
	int32_t		asset;
	t_map		map;

	if (map_load(path))
	{
		map = map_get();
		coords.y = 0;
		assets_init(mlx);
		entities_init();
		while (map.data[coords.y])
		{
			coords.x = 0;
			while (map.data[coords.y][coords.x] && map.data[coords.y][coords.x] != '\n')
			{
				asset = 0;
				if (map.data[coords.y][coords.x] == '0' || map.data[coords.y][coords.x] == 'C')
					asset = ASSET_TILE_EMPTY;
				if (map.data[coords.y][coords.x] == '1')
					asset = ASSET_TILE_WALL;
				if (asset)
					mlx_image_to_window(mlx, assets_get(asset), coords.x * TILE_SIZE, coords.y * TILE_SIZE);
				coords.x++;
			}
			coords.y++;
		}
		g_gamestate.player = entities_player((map.start.x * TILE_SIZE) + (TILE_SIZE / 2), map.start.y * TILE_SIZE);
	}
}

void	sl_keys(mlx_key_data_t keydata, void *param)
{
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		exit(EXIT_SUCCESS);
	sys_controls(keydata, param);
}

void	sl_tick(void *param)
{
	mlx_t	*mlx;

	mlx = param;
	sys_controls_tick(mlx->delta_time);
	sys_collision(mlx->delta_time);
	sys_movement(mlx->delta_time);
	sys_state();
	sys_animation(mlx->delta_time);
	sys_sprites(mlx);
}

void	sl_draw(mlx_image_t *buffer, void *param)
{
	(void)buffer;
	(void)param;
	//ft_memset(buffer->pixels, 0, buffer->width * buffer->height * sizeof(int32_t));
}

void	sl_exit()
{
	
}