/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 19:42:30 by mameyer           #+#    #+#             */
/*   Updated: 2017/07/27 23:24:10 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void		builtins(char **command, t_env *env)
{
	if (ft_strcmp(command[0], "env") == 0)
		print_env(env);
	else if (ft_strcmp(command[0], "setenv") == 0)
		set_env(env, command);
	else if (ft_strcmp(command[0], "unsetenv") == 0)
		unset_env(env, command);
	else if (ft_strcmp(command[0], "cd") == 0)
		change_directory(env, command);
	else if (ft_strcmp(command[0], "echo") == 0)
	{
		
	}
	else if (ft_strcmp(command[0], "exit") == 0)
	{
		if (command)
			free_command(command);
		if (env)
			free_env(env);
		exit(0);
	}
	core(env);
}
