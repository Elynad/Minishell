/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 11:37:33 by mameyer           #+#    #+#             */
/*   Updated: 2017/08/23 20:19:14 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void		check_command(char **command, char **env)
{
	char		**new_env;

	if (command && command[0] && ft_strcmp(command[0], "echo") == 0)
		echo_command(command, env);
	else if (command && command[0] && ft_strcmp(command[0], "env") == 0)
		env_command(command, env);
	else if (command && command[0] && ft_strcmp(command[0], "unsetenv") == 0)
		unsetenv_command(command, env);
	else if (command && command[0] && ft_strcmp(command[0], "setenv") == 0)
		setenv_command(command, env);
	else if (command && command[0] && ft_strcmp(command[0], "cd") == 0)
		cd_command(command, env);
	else if (command && command[0] && ft_strcmp(command[0], "exit") == 0)
		exit_command(command, env);
	else if (command && command[0] && ft_strcmp(command[0], "./minishell") == 0)
	{
		new_env = increase_shlvl(env);
		fork_func(command, new_env, 1);
	}
	else if (command)
		fork_func(command, env, 0);
}
