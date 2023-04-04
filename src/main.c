/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 23:25:34 by niceguy           #+#    #+#             */
/*   Updated: 2023/04/04 03:55:00 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Exit the program as failure.
static void	ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

int32_t	main(int argc, char	**argv)
{
	mlx_t	*mlx;
	t_map	map;
	t_uvec	dim;

	if (argc < 2)
		ft_error();
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	if (!map_load(argv[1]))
		ft_error();
	map = map_get();
	dim.x = map.dim_x * TILE_SIZE;
	dim.y = map.dim_y * TILE_SIZE;
	mlx = mlx_init(dim.x, dim.y, "So Long", true);
	if (!mlx)
		ft_error();
	mlx_set_window_size(mlx, mlx->width * 2, mlx->height * 2);
	mlx_key_hook(mlx, sl_keys, NULL);
	mlx_loop_hook(mlx, &sl_tick, mlx);
	sl_init(mlx);
	mlx_loop(mlx);
	sl_exit(mlx);
	return (EXIT_SUCCESS);
}
