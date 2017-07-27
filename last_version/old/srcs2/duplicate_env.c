/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicate_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 19:16:03 by mameyer           #+#    #+#             */
/*   Updated: 2017/07/26 19:19:42 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char		**duplicate_env(char **env, t_infos *infos)
{
	char		**new_env;
	int			i;

	i = 0;
	while (env[i])
		i++;
	if (!(new_env = (char **)malloc(sizeof(char *) * (i + 1))))
		exit(-1);
	i = 0;
	while (env[i])
	{
		new_env[i] = ft_strdup(env[i]);
		i++;
	}
	while (new_env[i])
	{
		new_env[i] = NULL;
		i++;
	}
	infos->env_changed = 1;
	return (new_env);
}
