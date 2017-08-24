/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_0.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 10:00:02 by mameyer           #+#    #+#             */
/*   Updated: 2017/08/23 21:49:10 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char		**dup_env(char **env)
{
	char		**new_env;
	int			a;

	a = 0;
	while (env[a])
		a++;
	if (!(new_env = (char **)malloc(sizeof(char *) * (a + 1))))
		exit(EXIT_FAILURE);
	a = 0;
	while (env[a])
	{
		new_env[a] = ft_strdup(env[a]);
		a++;
	}
	new_env[a] = NULL;
	return (new_env);
}
