/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 15:48:31 by mameyer           #+#    #+#             */
/*   Updated: 2017/07/24 22:00:24 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void		clear_command(void)
{
	int		i;

	i = 76;
	while (i >= 0)
	{
		ft_putchar('\n');
		i--;
	}
}

void		print_env(char **env)
{
	int		i;

	i = 0;
	while (env[i])
	{
		ft_putendl(env[i]);
		i++;
	}
}

void		execute(char **command, char **env)
{
	(void)env;
	ft_putendl("Executing command");
	if (ft_strcmp(command[0], "ls") == 0)
		execve("/bin/ls", command, NULL);
	else if (ft_strcmp(command[0], "echo") == 0)
	{
		// parse echo command
		execve("/bin/echo", command, NULL);
	}
	else if (ft_strcmp(command[0], "cd") == 0)
		execve("/bin/cd", command, NULL);
	else if (ft_strcmp(command[0], "pwd") == 0)
		execve("/bin/pwd", command, NULL);
}
