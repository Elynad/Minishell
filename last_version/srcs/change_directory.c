/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_directory.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 21:55:19 by mameyer           #+#    #+#             */
/*   Updated: 2017/07/27 23:25:32 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void		change_directory(t_env *env, char **command)
{
	char		**paths;
	int			len;
	int			i;

	len = 1;
	i = 0;
	while (command[1] && command[1][i])
	{
		if (command[1][i] == '/')
			len++;
		i++;
	}
	if (!(paths = (char **)malloc(sizeof(char *) * (len + 2))))
		exit(-1);
	i = 0;
	len = 0;
	while (command[1][i])
	{
		paths[len] = get_until_next_sl(command[1], &i);
		i++;
		len++;
	}
	while (paths[len])
	{
		paths[len] = NULL;
		len++;
	}
	if (ft_strcmp(paths[0], "~") == 0)
	{
		free(paths[0]);
		paths[0] = NULL;
		paths[0] = get_env_value(env, "HOME");
		// LEAKS HERE
	}
	len = 0;
	while (paths[len])
	{
		change_directory_2(env, paths[len]);
		len++;
	}
}

char		*get_until_next_sl(char *str, int *i)
{
	int		j;
	int		len;
	char	*path;

	j = *i;
	len = 0;
	while (str[j] && str[j] != '/')
	{
		j++;
		len++;
	}
	if (!(path = (char *)malloc(sizeof(char) * (len + 1))))
		exit(-1);
	len = 0;
	while (str[*i] && str[*i] != '/')
	{
		path[len] = str[*i];
		len++;
		(*i)++;
	}
	while (path[len])
	{
		path[len] = '\0';
		len++;
	}
	return (path);
}

void		change_directory_2(t_env *env, char *path)
{
	char		buff[1024];

	getcwd(buff, 1024);
	if (chdir(path) != -1)
	{
		ft_putendl("CD SUCCESS");
		modify_env_var(env, "OLDPWD", buff);
		getcwd(buff, 1024);
		modify_env_var(env, "PWD", buff);
	}
	else
	{
		ft_putstr("cd: ");
		ft_putstr(path);
		ft_putendl(" No such file or directory");
	}
}
