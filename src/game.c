/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 22:46:09 by niceguy           #+#    #+#             */
/*   Updated: 2023/04/03 19:16:19 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static t_gamestate	g_gamestate;

t_gamestate	game_get(void)
{
	return (g_gamestate);
}

void	game_add_player(t_uvec start)
{
	t_dvec	pos;

	pos.x = (start.x * TILE_SIZE) + (TILE_SIZE / 2);
	pos.y = (start.y + 1) * TILE_SIZE;
	g_gamestate.player = entities_player(pos.x, pos.y);
}

void	game_add_collectible(void)
{
	t_map	map;

	map = map_get();
	g_gamestate.collected++;
	ft_printf("%d/%d\n", g_gamestate.collected, map.num_coll);
}

void	game_set_tile(uint32_t x, uint32_t y, char c, va_list args)
{
	int32_t			asset;
	t_dvec			pos;
	mlx_t			*mlx;
	mlx_image_t		*tile_img;

	mlx = va_arg(args, void *);
	pos.x = (x * TILE_SIZE);
	pos.y = (y * TILE_SIZE);
	asset = ASSET_TILE_EMPTY;
	if (c == '1')
		asset = ASSET_TILE_WALL;
	if (c == 'C')
		entities_enemy(pos.x + (TILE_SIZE / 2), pos.y + (TILE_SIZE / 2));
	if (asset)
	{
		tile_img = assets_get(asset);
		mlx_image_to_window(mlx, tile_img, x * TILE_SIZE, y * TILE_SIZE);
	}
}

void	game_tick(void)
{
	t_map	map;
	t_c_pos	*pos;
	t_uvec	coords;

	map = map_get();
	pos = ecs_comp_get(g_gamestate.player, COMP_POS);
	if (!pos)
		return ;
	coords = pos_to_coords(pos->curr.x, pos->curr.y);
	if (g_gamestate.collected != map.num_coll)
		return ;
	if (coords.x == map.end.x && coords.y == map.end.y)
	{
		ecs_clear();
		map_clear();
		exit(EXIT_SUCCESS);
	}
}
