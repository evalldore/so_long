/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 05:11:34 by niceguy           #+#    #+#             */
/*   Updated: 2023/03/31 01:59:47 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_map	g_map;

static bool	check_line(char	*line, char *start)
{
	static uint32_t index;

	while (*line && *line != '\n')
	{
		if (*line == 'P')
		{
			if (g_map.start.x > 0 || g_map.start.y > 0)
				return (false);
			g_map.start.x = line - start;
			g_map.start.y = index;
		}
		else if (*line == 'E')
		{
			if (g_map.end.x > 0 || g_map.end.y > 0)
				return (false);
			g_map.end.x = line - start;
			g_map.end.y = index;
		}
		else if (*line == 'C')
			g_map.num_coll++;
		line++;
	}
	index++;
	return (true);
}

static bool check_borders()
{
	t_uvec	coords;

	coords.x = 0;
	coords.y = 0;
	while (coords.x < (g_map.dim_x))
	{
		if (g_map.data[0][coords.x] != '1')
			return (false);
		if (g_map.data[g_map.dim_y - 1][coords.x] != '1')
			return (false);
		coords.x++;
	}
	while (coords.y < g_map.dim_y)
	{
		if (g_map.data[coords.y][0] != '1')
			return (false);
		if (g_map.data[coords.y][g_map.dim_x - 1] != '1')
			return (false);
		coords.y++;
	}
	return (true);
}

static bool is_valid(void)
{

	if (g_map.dim_x <= g_map.dim_y)
		return (false);
	if (g_map.start.x < 0 || g_map.end.x < 0)
		return (false);
	if (g_map.num_coll == 0)
		return (false);
	return (true);
}

static bool	map_init(t_list *list)
{
	size_t	index;

	index = 0;
	g_map.dim_x = ft_strlen(list->content) - 1;
	g_map.dim_y = ft_lstsize(list);
	if (is_valid())
	{
		g_map.data = malloc(sizeof(char *) * (ft_lstsize(list) + 1));
		while (list)
		{
			g_map.data[index++] = list->content;
			list = list->next;
		}
		g_map.data[index] = NULL;
		ft_lstclear(&list, NULL);
		return (check_borders());
	}
	ft_lstclear(&list, &free);
	return (false);
}

t_map	map_get(void)
{
	return (g_map);
}

bool	map_load(char *path)
{
	t_list				*list;
	t_list				*curr;

	list = parse_file(path);
	if (!list)
		return (false);
	curr = list;
	g_map.start.x = -1;
	g_map.start.y = -1;
	g_map.end.x = -1;
	g_map.end.y = -1;
	while (curr)
	{
		if (check_line(curr->content, curr->content))
		{
			curr = curr->next;
			continue ;
		}
		ft_lstclear(&list, &free);
		break ;
	}
	if (list)
		return (map_init(list));
	return (false);
}
