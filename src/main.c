/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 23:25:34 by niceguy           #+#    #+#             */
/*   Updated: 2023/03/17 02:18:31 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_gamestate	g_state;
static mlx_image_t	*g_framebuffer;

// Exit the program as failure.
static void ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

// Print the window width and height.
static void sl_tick(void* param)
{
	if (mlx_is_key_down(param, MLX_KEY_W))
		g_state.ply.pos.y -= 1;
	if (mlx_is_key_down(param, MLX_KEY_S))
		g_state.ply.pos.y += 1;
	if (mlx_is_key_down(param, MLX_KEY_A))
		g_state.ply.pos.x -= 1;
	if (mlx_is_key_down(param, MLX_KEY_D))
		g_state.ply.pos.x += 1;
}

static void sl_draw(void* param)
{
	const mlx_t* mlx = param;
	(void)mlx;
	mlx_put_pixel(g_framebuffer, g_state.ply.pos.x, g_state.ply.pos.y, 0xFF0000FF);
}

void	sl_keys(mlx_key_data_t keydata, void *param)
{
	(void)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		exit(EXIT_SUCCESS);
}

int32_t	main(void)
{
	g_state.NumColl = 0;
	g_state.ply.pos.x = 0;
	g_state.ply.pos.y = 0;
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "So Long", true);
	if (!mlx)
		ft_error();
	g_framebuffer = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!g_framebuffer || (mlx_image_to_window(mlx, g_framebuffer, 0, 0) < 0))
		ft_error();
	mlx_key_hook(mlx, &sl_keys, NULL);
	mlx_loop_hook(mlx, sl_tick, mlx);
	mlx_loop_hook(mlx, sl_draw, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}