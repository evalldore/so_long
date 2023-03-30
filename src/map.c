/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 05:11:34 by niceguy           #+#    #+#             */
/*   Updated: 2023/03/30 18:41:09 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_map	g_map;

static bool	check_line(t_mapcheck *check, char	*line)
{
	check->len = 0;
	while (line[check->len] && line[check->len] != '\n')
	{
		if (line[check->len] == 'P')
		{
			if (!check->has_start)
				check->has_start = true;
			else
				return (false);
		}
		if (line[check->len] == 'E')
		{
			if (!check->has_exit)
				check->has_exit = true;
			else
				return (false);
		}
		if (line[check->len] == 'C')
			check->collectibles++;
		check->len++;
	}
	return (true);
}

static void	set_points(size_t collumn, char *line, char c)
{
	char	*pos;

	pos = ft_strchr(line, c);
	if (!pos)
		return ;
	if (c == 'P')
	{
		g_map.start.x = pos - (char *)(line);
		g_map.start.y = collumn;
	}
	else if (c == 'E')
	{
		g_map.end.x = pos - (char *)(line);
		g_map.end.y = collumn;
	}
}

static bool	map_init(t_list *list)
{
	size_t	index;

	index = 0;
	g_map.dim_x = ft_strlen(list->content);
	g_map.dim_y = ft_lstsize(list);
	if (g_map.dim_x > g_map.dim_y)
	{
		g_map.data = malloc(sizeof(char *) * (ft_lstsize(list) + 1));
		while (list)
		{
			g_map.data[index] = list->content;
			set_points(index, (char *)(list->content), 'P');
			set_points(index, (char *)(list->content), 'E');
			list = list->next;
			index++;
		}
		g_map.data[index] = NULL;
		ft_lstclear(&list, NULL);
		return (true);
	}
	ft_lstclear(&list, NULL);
	return (false);
}

t_map	map_get(void)
{
	return (g_map);
}

bool	map_load(char *path)
{
	static t_mapcheck	check;
	t_list				*list;
	t_list				*curr;

	list = parse_file(path);
	if (!list)
		return (false);
	curr = list;
	g_map.num_coll = 0;
	while (curr)
	{
		check.collectibles = 0;
		if (check_line(&check, curr->content))
		{
			curr = curr->next;
			g_map.num_coll += check.collectibles;
			continue ;
		}
		ft_lstclear(&list, &free);
		break ;
	}
	if (list)
		return (map_init(list));
	return (false);
}
