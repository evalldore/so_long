/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 21:20:54 by niceguy           #+#    #+#             */
/*   Updated: 2023/03/21 03:36:59 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "entities.h"

static gamestate_t	g_gamestate;

void	sl_init(void)
{
	entities_init();
	g_gamestate.player = entities_player(1, 1);
}

bool	sl_move(int x, int y)
{
	bool		can_move;
	comp_pos_t	*pos;

	pos = ecs_comp_get(g_gamestate.player, COMP_POS);
	can_move = true;
	if (can_move)
	{
		pos->curr.x += x;
		pos->curr.y += y;
	}
	return (true);
}

void	sl_keys(mlx_key_data_t keydata, void *param)
{
	(void)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		exit(EXIT_SUCCESS);
	if (keydata.key == MLX_KEY_W && keydata.action > 0)
		sl_move(0, -1);
	if (keydata.key == MLX_KEY_S && keydata.action > 0)
		sl_move(0, 1);
	if (keydata.key == MLX_KEY_A && keydata.action > 0)
		sl_move(-1, 0);
	if (keydata.key == MLX_KEY_D && keydata.action > 0)
		sl_move(1, 0);
}

void	sl_tick(void *param)
{
	(void)param;
}

void	sl_draw(mlx_image_t *buffer, void *param)
{
	comp_pos_t	*pos;

	(void)param;
	pos = ecs_comp_get(g_gamestate.player, COMP_POS);
	ft_memset(buffer->pixels, 0, buffer->width * buffer->height * sizeof(int32_t));
	mlx_put_pixel(buffer, pos->curr.x * (TILE_SIZE / 2), pos->curr.y * (TILE_SIZE / 2), 0xFF0000FF);
}

void	sl_exit()
{
	
}