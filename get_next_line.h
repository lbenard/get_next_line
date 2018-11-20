/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 13:16:15 by lbenard           #+#    #+#             */
/*   Updated: 2018/11/20 15:02:59 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 2048

# define ERROR -1
# define READ_FINISH 0
# define LINE_READ 1

# include "libft.h"

typedef struct	s_fd
{
	int		fd;
	char	buffer[BUFF_SIZE + 1];
}				t_fd;

int				get_next_line(const int fd, char **line);

#endif
