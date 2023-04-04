/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 05:11:34 by niceguy           #+#    #+#             */
/*   Updated: 2023/04/04 02:54:18 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static t_map	g_map;

static bool	check_line(uint32_t index, char	*line, char *start)
{
	if (row_len(line) != g_map.dim_x)
		return (false);
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
	return (true);
}

static bool	map_init(t_list *list)
{
	size_t	index;
	t_list	*temp;

	index = 0;
	if (map_is_valid(g_map, list))
	{
		g_map.data = malloc(sizeof(char *) * (ft_lstsize(list) + 1));
		temp = list;
		while (temp)
		{
			g_map.data[index++] = temp->content;
			temp = temp->next;
		}
		g_map.data[index] = NULL;
		ft_lstclear(&list, NULL);
		return (true);
	}
	ft_lstclear(&list, &free);
	return (false);
}

t_map	map_get(void)
{
	return (g_map);
}

void	map_clear(void)
{
	uint32_t	row;

	row = 0;
	while (g_map.data[row])
	{
		free(g_map.data[row]);
		g_map.data[row] = NULL;
		row++;
	}
	free(g_map.data);
	g_map.data = NULL;
}

bool	map_load(char *path)
{
	static uint32_t		index;
	t_list				*list;
	t_list				*curr;

	if (!ft_strnstr(path, ".ber", ft_strlen(path)))
		return (false);
	list = parse_file(path);
	if (!list)
		return (false);
	curr = list;
	g_map.dim_x = row_len(list->content);
	g_map.dim_y = ft_lstsize(list);
	while (curr)
	{
		if (check_line(index++, curr->content, curr->content))
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
