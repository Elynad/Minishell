/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 14:15:46 by mameyer           #+#    #+#             */
/*   Updated: 2017/08/23 21:25:57 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void		fork_func(char **commands, char **env, int type)
{
	pid_t			father;
	char			**new_env;

	father = fork();
	if (father < 0)
	{
		ft_putendl("Fork error");
		exit(EXIT_FAILURE);
	}
	else if (father == 0)
		execute(commands, env);
	else
	{
		wait(&father);
		free_tab(commands);
		if (type == 1)
		{
			new_env = decrease_shlvl(env);
			core(new_env);
		}
		else
			core(env);
	}
}

void		execute(char **commands, char **env)
{
	char		**paths;
	char		*binary_path;
	int			a;
	int			error;

	if (commands && commands[0] && commands[0][0]
			&& (commands[0][0] == '.' || commands[0][0] == '/'))
		execute_current(commands, env);
	paths = get_paths(env);
	a = 0;
	while (paths[a])
	{
		if (paths[a][ft_strlen(paths[a]) - 1] != '/')
			binary_path = get_binary_path(paths[a], commands[0]);
		else
			binary_path = dup_and_cat(paths[a], commands[0]);
		error = test_access(binary_path);
		if (error == 1)
			break ;
		a++;
	}
	if (!(paths[a]))
		execute_error(commands, env, error);
	else
		execve(binary_path, commands, env);
}

void		execute_current(char **commands, char **env)
{
	char		*path;
	char		*path_2;
	char		buf[PATH_MAX];

	getcwd(buf, PATH_MAX);
	if (buf[ft_strlen(buf) - 1] != '/'
			&& commands[0] && commands[0][0] && commands[0][0] != '/')
	{
		path_2 = dup_and_cat(buf, "/");
		path = dup_and_cat(path_2, commands[0]);
	}
	else if (commands && commands[0] && commands[0][0] && commands[0][0] == '/')
		path = ft_strdup(commands[0]);
	else
		path = dup_and_cat(buf, commands[0]);
	execve(path, commands, env);
}

int			test_access(char *path)
{
	if (access(path, F_OK) == 0)
	{
		if (access(path, X_OK) == 0)
			return (1);
		else
			return (2);
	}
	else
		return (0);
}

char		**get_paths(char **env)
{
	char		**paths;
	char		*buffer;
	char		*buffer_2;

	buffer = get_env_var(env, "PATH");
	if (ft_strlen(buffer) != 0)
	{
		paths = str_split(buffer, ':', 0);
		free(buffer);
		buffer = NULL;
	}
	else
	{
		buffer_2 = dup_and_cat(DEFAULT_PATH_1, DEFAULT_PATH_2);
		paths = str_split(buffer_2, ':', 0);
		free(buffer_2);
		buffer_2 = NULL;
	}
	return (paths);
}
