/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 00:14:37 by mameyer           #+#    #+#             */
/*   Updated: 2017/07/26 14:39:08 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
# define BUFF_SIZE 1

# include <fcntl.h>
# include "libft.h"
# include <sys/syslimits.h>

int		get_next_line(const int fd, char **line);

#endif
