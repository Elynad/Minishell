/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 15:13:59 by mameyer           #+#    #+#             */
/*   Updated: 2017/07/26 21:08:32 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int			check_command(char **options)
{
	if (ft_strcmp(options[0], "ls") == 0
			|| ft_strcmp(options[0], "pwd") == 0
			|| ft_strcmp(options[0], "echo") == 0)
		return (1);
	return (0);
}

int			check_my_commands(char **options)
{
	if (ft_strcmp(options[0], "cd") == 0
			|| ft_strcmp(options[0], "clear") == 0)
		return (1);
	return (0);
}

int			check_env_commands(char **options, int type)
{
	if (ft_strcmp(options[0], "setenv") == 0)
	{
		if (!options[1] || !options[2] || !options[3] || options[4])
		{
			if (type == 0)
				env_usage(0);
			return (2);
		}
		return (1);
	}
	else if (ft_strcmp(options[0], "unsetenv") == 0)
	{
		if (!options[1] || options[2])
		{
			if (type == 0)
				env_usage(1);
			return (2);
		}
		return (1);
	}
	return (3);
}
