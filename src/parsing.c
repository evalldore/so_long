/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 04:56:16 by niceguy           #+#    #+#             */
/*   Updated: 2023/03/31 20:08:25 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_list	*parse_file(char	*path)
{
	int			fd;
	t_list		*list;
	t_list		*new;
	char		*line;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	list = NULL;
	while (1)
	{
		line = ft_get_next_line(fd);
		if (!line)
			break ;
		new = ft_lstnew(line);
		if (new)
		{
			ft_lstadd_back(&list, new);
			continue ;
		}
		free(line);
		ft_lstclear(&list, &free);
		break ;
	}
	close(fd);
	return (list);
}
