/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 18:58:22 by mameyer           #+#    #+#             */
/*   Updated: 2017/07/11 19:42:10 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void			core(char **argv)
{
	pid_t		father;
	char		*str;

	ft_putstr("$> ");
	while (get_next_line(0, &str))
	{
		if (ft_strcmp(str, "exit") == 0)
			exit(0);
		if (check_commands(str) == 1)
		{
			father = fork();
			if (father == 0)
			{
				execute(str, argv);
				ft_putstr("execute command\n");
			}
			else
			{
				wait(0);
				ft_putstr("Going back in core func\n");
				core(argv);
			}
		}
		ft_putstr("$> ");
	}
}

void			execute(char *str, char **argv)
{
	if (ft_strcmp(str, "ls") == 0)
		execve("/bin/ls", argv, NULL);
	else if (ft_strcmp(str, "echo") == 0)
		execve("/bin/echo", argv, NULL);
	else if (ft_strcmp(str, "cd") == 0)
		execve("/bin/cd", argv, NULL);
	else if (ft_strcmp(str, "setenv") == 0)
		execve("/bin/setenv", argv, NULL);
}
