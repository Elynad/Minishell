/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shlvl_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 10:40:48 by mameyer           #+#    #+#             */
/*   Updated: 2017/08/23 19:49:56 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char		**increase_shlvl(char **env)
{
	char		*shlvl;
	char		**commands;
	char		**new_env;
	char		*level;

	shlvl = get_env_var(env, "SHLVL");
	if ((shlvl && ft_strlen(shlvl) == 0) || !(shlvl))
	{
		commands = get_setenv_commands("1", "SHLVL");
		new_env = add_env_var(commands, env);
	}
	else
	{
		level = ft_itoa(ft_atoi(shlvl) + 1);
		commands = get_setenv_commands(level, "SHLVL");
		new_env = replace_env_var(commands, env,
				get_env_var_line(commands, env));
		free(level);
		level = NULL;
	}
	free_tab(commands);
	free_tab(env);
	free(shlvl);
	shlvl = NULL;
	return (new_env);
}

char		**decrease_shlvl(char **env)
{
	char		**commands;
	char		*shlvl;
	char		*level;
	char		**new_env;

	shlvl = get_env_var(env, "SHLVL");
	if ((shlvl && ft_strlen(shlvl) == 0) || !(shlvl))
	{
		commands = get_setenv_commands("1", "SHLVL");
		new_env = add_env_var(commands, env);
	}
	else
	{
		level = ft_itoa(ft_atoi(shlvl) - 1);
		commands = get_setenv_commands(level, "SHLVL");
		new_env = replace_env_var(commands, env,
				get_env_var_line(commands, env));
		free(level);
		level = NULL;
	}
	free_tab(commands);
	free_tab(env);
	free(shlvl);
	shlvl = NULL;
	return (new_env);
}
