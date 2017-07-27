/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 18:53:48 by mameyer           #+#    #+#             */
/*   Updated: 2017/07/24 21:59:43 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int			check_commands(char *str)
{
	if (ft_strcmp(str, "ls") == 0
			|| ft_strcmp(str, "echo") == 0
			|| ft_strcmp(str, "pwd") == 0)
		return (1);
	else
		return (0);
}

int			check_env_commands(char **str)
{
	if (ft_strcmp(str[0], "unsetenv") == 0
			|| ft_strcmp(str[0], "setenv") == 0)
		return (1);
	else
		return (0);
}

void		fork_func(char **options, char **env, t_infos *infos)
{
	pid_t			father;

	(void)env;
	father = fork();
	if (father < 0)
	{
		ft_putendl("Fork error");
		exit(-1);
	}
	else if (father == 0)
		execute(options, env);
	else
	{
		wait(0);
		if (options)
			free_opt(options);
		ft_putendl("Going back in core func");		// test
		core(env, infos);
	}
}

int			my_commands(char **options, char **env, t_infos *infos)
{
	(void)infos;
	if (ft_strcmp(options[0], "clear") == 0)
	{
		clear_command();
		return (0);
	}
	else if (ft_strcmp(options[0], "exit") == 0)
		exit(0);
	else if (ft_strcmp(options[0], "env") == 0)
		print_env(env);
	else if (ft_strcmp(options[0], "cd") == 0)
		cd_command(options, env, infos);
	else
		return (1);
	return (0);
}

void		cd_command(char **options, char **env, t_infos *infos)
{
	char		**new_env;

	new_env = NULL;
	if (options)
	{
		if (!options[1]
				|| (options[1] && options[1][0] == '~' && (!options[1][1]
						|| options[1][1] == '/') && !options[2]))
		{
			if (chdir(infos->env_home) != -1)
				new_env = change_pwd(infos->env_home, env);
			else
				ft_putendl("No such file or directory");
		}
		else if (options && options[1] && !options[2])
		{
			if (chdir(options[1]) != -1)
				new_env = change_pwd(options[1], env);
			else
				ft_putendl("No such file or directory");
		}
		else if (options && options[1] && options[2])
		{
			ft_putstr("cd: string not in pwd: ");
			ft_putendl(options[1]);
		}
	}
	if (new_env)
		core(new_env, infos);
	else if (env)
		core(env, infos);
}
