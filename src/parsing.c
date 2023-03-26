/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 04:56:16 by niceguy           #+#    #+#             */
/*   Updated: 2023/03/26 04:58:24 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.c"

t_list  *parse_file(char	*path)
{
	int			fd;
	t_list		*list;
	t_list		*new;

	if (!path)
		return (NULL);
	fd = open(path, O_RDONLY);
	list = NULL;
	if (fd < 0)
		return (NULL);
	while (1)
	{
		line = ft_get_next_line(fd);
		if (!line)
			break ;
		if (check_line(&check, line))
		{
			new = ft_lstnew(line);
			if (new)
			{
				ft_lstadd_back(&list, new);
				continue ;
			}
		}
		free(line);
		ft_lstclear(&list, &free);
		break;
	}
	close(fd);
	if (list)
		return (map_init(map_data, list));
	return (false);
}