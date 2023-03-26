/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 21:20:54 by niceguy           #+#    #+#             */
/*   Updated: 2023/03/24 20:03:23 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "entities.h"
#include "assets.h"

static gamestate_t	g_gamestate;

void	sl_init(mlx_t *mlx)
{
	if (map_load(&g_gamestate.map, "maps/test.ber"))
	{
		assets_init(mlx);
		entities_init();
		g_gamestate.player = entities_player(256.0, 256.0);
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