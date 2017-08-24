/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 19:02:00 by mameyer           #+#    #+#             */
/*   Updated: 2017/08/24 17:54:26 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char		*get_binary_path(char *path, char *command)
{
	char		*buffer;
	char		*binary_path;

	buffer = dup_and_cat(path, "/");
	binary_path = dup_and_cat(buffer, command);
	if (buffer)
		free(buffer);
	buffer = NULL;
	return (binary_path);
}

void		free_tab_exit(char **env)
{
	free_tab(env);
	exit(EXIT_SUCCESS);
}
