/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 10:40:44 by mameyer           #+#    #+#             */
/*   Updated: 2017/08/24 17:53:02 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void		cd_errors(char **command, char **env, char *path)
{
	struct stat		sb;

	if (lstat(path, &sb) == -1)
	{
		ft_putstr("cd: no such file or directory: ");
		ft_putendl(path);
	}
	else if (!(sb.st_mode & S_IRUSR))
	{
		ft_putstr("cd: permission denied: ");
		ft_putendl(path);
	}
	free_tab(command);
	free(path);
	path = NULL;
	core(env);
}

void		execute_error(char **commands, char **env, int error)
{
	if (error == 0)
	{
		ft_putstr("minishell: command not found: ");
		if (commands[0])
			ft_putendl(commands[0]);
	}
	else if (error == 2)
	{
		ft_putstr("minishell: command '");
		ft_putstr(commands[0]);
		ft_putstr("' : Permission denied");
	}
	if (commands)
		free_tab(commands);
	exit(EXIT_FAILURE);
	core(env);
}
