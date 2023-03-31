/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 21:20:54 by niceguy           #+#    #+#             */
/*   Updated: 2023/03/31 18:44:11 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "entities.h"
#include "assets.h"

static t_gamestate	g_gamestate;

bool	sl_init(mlx_t *mlx, char *path)
{
	t_uvec			co;
	int32_t			asset;
	t_map			map;

	if (map_load(path))
	{
		map = map_get();
		assets_init(mlx);
		entities_init();
		co.y = 0;
		while (map.data[co.y])
		{
			co.x = 0;
			while (map.data[co.y][co.x])
			{
				asset = ASSET_TILE_EMPTY;
				if (map.data[co.y][co.x] == '1')
					asset = ASSET_TILE_WALL;
				if (map.data[co.y][co.x] == 'C')
					entities_enemy(co.x * TILE_SIZE, co.y * TILE_SIZE);
				if (asset)
					mlx_image_to_window(mlx, assets_get(asset), co.x * TILE_SIZE, co.y * TILE_SIZE);
				co.x++;
			}
			co.y++;
		}
		g_gamestate.player = entities_player((map.start.x * TILE_SIZE) + (TILE_SIZE / 2), (map.start.y + 1) * TILE_SIZE);
		return (true);
	}
	return (false);
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
	ecs_iterate(&sys_controls_tick, mlx->delta_time);
	ecs_iterate(&sys_projectiles, mlx->delta_time);
	ecs_iterate(&sys_collectible, mlx->delta_time, g_gamestate.player);
	ecs_iterate(&sys_ai, mlx->delta_time);
	ecs_iterate(&sys_gravity, mlx->delta_time);
	ecs_iterate(&sys_collision, mlx->delta_time);
	ecs_iterate(&sys_movement, mlx->delta_time);
	ecs_iterate(&sys_state);
	ecs_iterate(&sys_animation, mlx->delta_time);
	ecs_iterate(&sys_sprites, mlx);
}

void	sl_draw(mlx_image_t *buffer, void *param)
{
	(void)buffer;
	(void)param;
	//ft_memset(buffer->pixels, 0, buffer->width * buffer->height * sizeof(int32_t));
}

void	sl_exit(void)
{
	
}