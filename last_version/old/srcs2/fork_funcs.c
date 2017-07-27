/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 17:15:20 by mameyer           #+#    #+#             */
/*   Updated: 2017/07/26 22:28:23 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

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
		ft_putendl("// Going back in core func");
		core(env, infos);
	}
}

void		execute(char **command, char **env)
{
	(void)env;
	ft_putendl("// Executing command");
	if (ft_strcmp(command[0], "ls") == 0)
		execve("/bin/ls", command, NULL);
	else if (ft_strcmp(command[0], "pwd") == 0)
		execve("/bin/pwd", command, NULL);
	else if (ft_strcmp(command[0], "echo") == 0)
		execve("/bin/echo", command, NULL);
}
