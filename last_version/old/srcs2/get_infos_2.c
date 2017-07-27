/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_infos_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 22:29:22 by mameyer           #+#    #+#             */
/*   Updated: 2017/07/27 14:40:36 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char		**get_path(char *str)
{
	int			i;
	int			len;
	int			k;
	char		**paths;

	i = 0;
	len = 0;
	k = 0;
	while (str[i])
	{
		if (str[i] == ':')
			len++;
		i++;
	}
	len++;
	if (!(paths = (char **)malloc(sizeof(char *) * (len))))
		exit(-1);
	i = 0;
	while (str[i] != '=')
		i++;
	i++;
	while (str[i] && k < len)
	{
		paths[k] = get_until_next_colon(str, &i);
		i++;
		k++;
	}
	while (paths[len])
	{
		paths[len] = NULL;
		len++;
	}
	return (paths);
}

char		*get_until_next_colon(char *str, int *index)
{
	char		*path;
	int			len;
	int			i;

	len = 0;
	i = *index;
	while (str[i] && str[i] != ':')
	{
		len++;
		i++;
	}
	if (!(path = (char *)malloc(sizeof(char) * (len + 1))))
		exit(-1);
	i = 0;
	while (str[*index] && str[*index] != ':')
	{
		path[i] = str[*index];
		i++;
		(*index)++;
	}
	while (path[i])
	{
		path[i] = '\0';
		i++;
	}
	return (path);
}
