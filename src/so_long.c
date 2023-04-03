/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 21:20:54 by niceguy           #+#    #+#             */
/*   Updated: 2023/04/02 06:47:50 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	sl_init(mlx_t *mlx)
{
	t_uvec			co;
	int32_t			asset;
	t_map			map;

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
			if (map.data[co.y][co.x] == '\n')
				break;
			if (map.data[co.y][co.x] == '1')
				asset = ASSET_TILE_WALL;
			if (map.data[co.y][co.x] == 'C')
				entities_enemy((co.x * TILE_SIZE) + (TILE_SIZE / 2), (co.y * TILE_SIZE) + (TILE_SIZE / 2));
			if (asset)
				mlx_image_to_window(mlx, assets_get(asset), co.x * TILE_SIZE, co.y * TILE_SIZE);
			co.x++;
		}
		co.y++;
	}
	game_add_player(map.start);
	return (true);
}

void	sl_keys(mlx_key_data_t keydata, void *param)
{
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		exit(EXIT_SUCCESS);
	sys_controls(keydata, param);
}

void	sl_tick(void *param)
{
	mlx_t		*mlx;
	double		dt;
	t_gamestate	game;

	game = game_get();
	mlx = param;
	dt = mlx->delta_time;
	if (dt > 0.03)
		dt = 0.016;
	ecs_iterate(&sys_controls_tick, dt);
	ecs_iterate(&sys_projectiles, dt);
	ecs_iterate(&sys_collectible, dt, game.player);
	ecs_iterate(&sys_ai, dt, game.player);
	ecs_iterate(&sys_gravity, dt);
	ecs_iterate(&sys_collision, dt);
	ecs_iterate(&sys_movement, dt);
	ecs_iterate(&sys_state);
	ecs_iterate(&sys_animation, dt);
	ecs_iterate(&sys_sprites, mlx);
}

void	sl_exit(void)
{
	ecs_clear();
	map_clear();
}