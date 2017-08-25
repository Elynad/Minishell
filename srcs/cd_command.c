/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 18:41:52 by mameyer           #+#    #+#             */
/*   Updated: 2017/08/24 20:32:05 by mameyer          ###   ########.fr       */
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
	char		**new_env;
	char		**new_env_buf;
	char		*tmp_pwd;
	char		**setenv;
	char		buf[PATH_MAX];

	getcwd(buf, PATH_MAX);
	tmp_pwd = get_env_var(env, "PWD");
	setenv = get_setenv_commands(buf, "PWD");
	new_env_buf = replace_env_var(setenv, env, (get_env_var_line(setenv, env)));
	free_tab(setenv);
	setenv = get_setenv_commands(tmp_pwd, "OLDPWD");
	new_env = replace_env_var(setenv, new_env_buf,
			(get_env_var_line(setenv, env)));
	free(tmp_pwd);
	tmp_pwd = NULL;
	free_tab(new_env_buf);
	free_tab(setenv);
	free_tab(env);
	free_tab(command);
	core(new_env);
}
