/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 16:59:33 by mameyer           #+#    #+#             */
/*   Updated: 2017/08/23 14:01:25 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void		setenv_command(char **command, char **env)
{
	if (check_setenv_syntax(command) == -1)
	{
		ft_putendl("Wrong arguments for setenv.");
		ft_putendl("Usage : setenv 'ENV_VAR' 'value' [overwrite]");
		free_tab(command);
		core(env);
	}
	else if (ft_strchr(command[1], '=') != NULL)
	{
		ft_putendl("Warning : 'ENV_VAR_NAME' should not contain '=' char.");
		free_tab(command);
		core(env);
	}
	else
		setenv_command_2(command, env);
}

void		setenv_command_2(char **command, char **env)
{
	char		**new_env;
	int			line;

	line = get_env_var_line(command, env);
	if (line != -1 && command[3][0] == '0')
	{
		free_tab(command);
		core(env);
	}
	else if (line == -1)
	{
		new_env = add_env_var(command, env);
		free_tab(command);
		free_tab(env);
		core(new_env);
	}
	else if (line != -1 && command[3][0] != '0')
	{
		new_env = replace_env_var(command, env, line);
		free_tab(env);
		free_tab(command);
		core(new_env);
	}
}

char		**add_env_var(char **command, char **env)
{
	char		**new_env;
	char		*buffer;
	int			a;

	a = 0;
	buffer = dup_and_cat(command[1], "=");
	while (env[a])
		a++;
	if (!(new_env = (char **)malloc(sizeof(char *) * (a + 2))))
		exit(EXIT_FAILURE);
	a = 0;
	while (env[a])
	{
		new_env[a] = ft_strdup(env[a]);
		a++;
	}
	new_env[a] = dup_and_cat(buffer, command[2]);
	a++;
	new_env[a] = NULL;
	free(buffer);
	buffer = NULL;
	return (new_env);
}

char		**replace_env_var(char **command, char **env, int line)
{
	char		**new_env;
	char		*buffer;
	int			a;

	buffer = dup_and_cat(command[1], "=");
	a = 0;
	while (env[a])
		a++;
	if (!(new_env = (char **)malloc(sizeof(char *) * (a + 1))))
		exit(EXIT_FAILURE);
	a = 0;
	while (env[a])
	{
		if (a == line)
			new_env[a] = dup_and_cat(buffer, command[2]);
		else
			new_env[a] = ft_strdup(env[a]);
		a++;
	}
	new_env[a] = NULL;
	free(buffer);
	buffer = NULL;
	return (new_env);
}

int			check_setenv_syntax(char **command)
{
	if (!(command[1]) || !(command[2]) || !(command[3])
			|| (command[3] && command[3][0] < 48)
			|| (command[3] && command[3][0] > 57))
		return (-1);
	else
		return (0);
}
