/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 18:53:48 by mameyer           #+#    #+#             */
/*   Updated: 2017/07/12 18:41:05 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int			check_commands(char *str)
{
	if (ft_strcmp(str, "ls") == 0
			|| ft_strcmp(str, "echo") == 0
			|| ft_strcmp(str, "cd") == 0
			|| ft_strcmp(str, "pwd") == 0
			|| ft_strcmp(str, "unsetenv") == 0)
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

void		fork_func(char **options, char **env)
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
		execute(options);
	else
	{
		wait(0);
		if (options)
			free_opt(options);
		ft_putendl("Going back in core func");		// test
		core(env);
	}
}

int			my_commands(char **options, char **env)
{
	(void)env;
	if (ft_strcmp(options[0], "clear") == 0)
	{
		clear_command();
		return (0);
	}
	else if (ft_strcmp(options[0], "exit") == 0)
		exit(0);
	else if (ft_strcmp(options[0], "unsetenv") == 0)
		env = unset_env(env);
	else if (ft_strcmp(options[0], "env") == 0)
		print_env(env);
	else
		return (1);
	return (0);
}
