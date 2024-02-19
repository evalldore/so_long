/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 05:40:35 by evallee-          #+#    #+#             */
/*   Updated: 2024/02/19 15:13:06 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "moves.h"

static uint32_t		g_moves;
static mlx_image_t	*g_moves_img;
static char			*g_moves_text;

void	moves_add(void *param)
{
	char			*numtext;

	g_moves++;
	if (g_moves_text)
		free(g_moves_text);
	mlx_delete_image(param, g_moves_img);
	numtext = ft_itoa((int)g_moves);
	g_moves_text = ft_strjoin("Moves: ", numtext);
	g_moves_img = mlx_put_string(param, g_moves_text, 10, 10);
	free(numtext);
}

void	moves_init(void *param)
{
	g_moves_img = mlx_put_string(param, "Moves: 0", 10, 10);
}

void	moves_clear(void *param)
{
	if (g_moves_text)
	{
		free(g_moves_text);
		g_moves_text = NULL;
	}
	mlx_delete_image(param, g_moves_img);
	g_moves_img = NULL;
}
