/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 18:41:52 by mameyer           #+#    #+#             */
/*   Updated: 2017/08/24 17:54:51 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void		cd_command(char **command, char **env)
{
	char		*path;

	if ((command[1] && command[1][0] && command[1][0] == '~')
			|| (!(command[1])))
		cd_home(command, env);
	else if (command[1] && command[1][0] && command[1][0] == '-'
			&& !(command[1][1]))
		cd_previous(command, env);
	else if (command[1])
	{
		path = ft_strdup(command[1]);
		cd_command_2(command, env, path, 0);
	}
}

void		cd_home(char **command, char **env)
{
	char		*path;
	char		*full_path;

	path = get_env_var(env, "HOME");
	if (command[1] && command[1][1])
	{
		full_path = dup_and_cat(path, &command[1][1]);
		free(path);
		path = NULL;
		cd_command_2(command, env, full_path, 0);
	}
	else
		cd_command_2(command, env, path, 0);
}

void		cd_previous(char **command, char **env)
{
	char		*path;

	path = get_env_var(env, "OLDPWD");
	if (ft_strlen(path) == 0)
	{
		ft_putendl("Unable to find OLDPWD env var.");
		ft_putendl("OLDPWD env var may not exist or be wrong");
		free_tab(command);
		free(path);
		path = NULL;
		core(env);
	}
	else
		cd_command_2(command, env, path, 1);
}

void		cd_command_2(char **command, char **env, char *path, int isprev)
{
	if (chdir(path) != -1)
	{
		if (isprev == 1)
			ft_putendl(path);
		cd_success(env, command);
	}
	else
		cd_errors(command, env, path);
}

void		cd_success(char **env, char **command)
{
	char		**setenv;
	char		**setenv_2;
	char		**new_env;
	char		**new_env_2;
	char		*line;

	line = get_env_var(env, "PWD");
	setenv = get_setenv_commands(line, "OLDPWD");
	new_env = replace_env_var(setenv, env, (get_env_var_line(setenv, env)));
	free(line);
	line = NULL;
	line = get_env_var(env, "OLDPWD");
	setenv_2 = get_setenv_commands(line, "PWD");
	new_env_2 = replace_env_var(setenv_2, new_env,
			(get_env_var_line(setenv_2, new_env)));
	free(line);
	line = NULL;
	free_tab(setenv);
	free_tab(setenv_2);
	free_tab(new_env);
	free_tab(command);
	free_tab(env);
	core(new_env_2);

}
