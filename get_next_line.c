/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 13:13:57 by lbenard           #+#    #+#             */
/*   Updated: 2018/11/10 14:36:49 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(const int fd, char **line)
{
	static t_list	*fd_list = NULL;
	t_list			*find;

	if (!line)
		return (-1);
	if (!fd_list)
	{
		fd_list = ft_lstnew(&fd, sizeof(int));
		find = fd_list;
	}
	else if (!(find = ft_lstfind(fd_list, &fd, fd_cmp)))
		ft_lstadd(&fd_list, (find = ft_lstnew(&fd, sizeof(int))));
	
}

int	fd_cmp(const void *fd, const void *list)
{
	return (ft_memcmp(fd, list->content, sizeof(int)));
}
