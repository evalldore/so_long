/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 23:25:34 by niceguy           #+#    #+#             */
/*   Updated: 2023/03/20 21:36:10 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static mlx_image_t	*g_framebuffer;

// Exit the program as failure.
static void	ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

void	keys(mlx_key_data_t keydata, void *param)
{
	sl_keys(keydata, param);
}

void	tick(void *param)
{
	sl_tick(param);
}

void	draw(void *param)
{
	sl_draw(g_framebuffer, param);
}

int32_t	main(void)
{
	mlx_t	*mlx;

	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	mlx = mlx_init(WIDTH, HEIGHT, "So Long", true);
	if (!mlx)
		ft_error();
	g_framebuffer = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!g_framebuffer || (mlx_image_to_window(mlx, g_framebuffer, 0, 0) < 0))
		ft_error();
	mlx_key_hook(mlx, &keys, NULL);
	mlx_loop_hook(mlx, tick, mlx);
	mlx_loop_hook(mlx, draw, mlx);
	sl_init();
	mlx_loop(mlx);
	mlx_terminate(mlx);
	sl_exit();
	return (EXIT_SUCCESS);
}
