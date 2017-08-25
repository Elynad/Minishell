/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 13:04:41 by mameyer           #+#    #+#             */
/*   Updated: 2017/08/25 01:27:41 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void		unsetenv_command(char **command, char **env)
{
	char		**new_env;
	int			line;

	if (check_unsetenv_syntax(command) == -1)
	{
		free_tab(command);
		core(env);
	}
	else
	{
		line = get_env_var_line(command, env);
		if (line != -1)
		{
			new_env = unset_env_var(env, line);
			free_tab(env);
			free_tab(command);
			core(new_env);
		}
		else
		{
			free_tab(command);
			core(env);
		}
	}
}

int			get_env_var_line(char **command, char **env)
{
	int		a;
	int		eq;

	a = 0;
	while (env[a])
	{
		eq = 0;
		while (env[a][eq] && env[a][eq] != '=')
			eq++;
		if (ft_strncmp(env[a], command[1], eq) == 0
				&& (int)ft_strlen(command[1]) == eq)
			return (a);
		a++;
	}
	return (-1);
}

char		**unset_env_var(char **env, int line)
{
	int		a;
	int		b;
	char	**new_env;

	a = 0;
	b = 0;
	while (env[a])
		a++;
	if (!(new_env = (char **)malloc(sizeof(char *) * (a + 1))))
		exit(EXIT_FAILURE);
	a = 0;
	while (env[a])
	{
		if (a == line)
			a++;
		else
		{
			new_env[b] = ft_strdup(env[a]);
			a++;
			b++;
		}
	}
	new_env[b] = NULL;
	return (new_env);
}

int			check_unsetenv_syntax(char **command)
{
	if (!(command[1]) || command[2])
	{
		ft_putendl("Wrong arguments for 'unsetenv'.\nUsage : 'unsetenv [VAR]'");
		return (-1);
	}
	return (0);
}
