/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_env_funcs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 22:01:17 by mameyer           #+#    #+#             */
/*   Updated: 2017/07/14 15:41:57 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char		**unset_env(char **env, char **command)
{
	if (check_env(env, command) != -1)
		return (delete_env_var(env, command));
	else
		return (env);
}

char		**delete_env_var(char **env, char **command)
{
	char		**new_env;
	int			len;
	int			index;
	int			k;

	index = check_env(env, command);
	len = 0;
	k = 0;
	while (env[len])
		len++;
	if (!(new_env = (char **)malloc(sizeof(char *) * (len))))
		exit(-1);
	len = 0;
	while (env[len])
	{
		if (len == index)
			len++;
		if (env[len])
		{
			new_env[k] = copy_env_line(env, len);
			len++;
		}
		else
		{
			new_env[k] = NULL;
			break;
		}
		k++;
	}
	new_env[k] = NULL;
	return (new_env);
}
