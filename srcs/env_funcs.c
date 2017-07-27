/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 16:24:13 by mameyer           #+#    #+#             */
/*   Updated: 2017/07/24 21:58:53 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char		**env_funcs(char **env, char **command)
{
	if (ft_strcmp(command[0], "setenv") == 0)
	{
		if (command[1] && command[2] && command[3])
			return (set_env(env, command));
		else if (!command[1] || !command[2] || !command[3])
			ft_putendl("To few arguments called for setenv.");
		return (env);
	}
	else if (ft_strcmp(command[0], "unsetenv") == 0)
	{
		if (command[1])
			return (unset_env(env, command));
		else
			ft_putendl("To few arguments called for unsetenv");
		return (env);
	}
	else
		return (env);
}

int			check_env(char **env, char **command)
{
	int		i;
	int		j;
	int		found;

	i = 0;
	found = -1;
	while (env[i])
	{
		j = 0;
		while (env[i][j] == command[1][j] && env[i][j] != '=')
			j++;
		if (j == (int)ft_strlen(command[1]))
			found = i;
		i++;
	}
	return (found);
}

char		**replace_env_var(char **env, char **command, int index)
{
	char		**new_env;
	int			size;
	int			j;
	int			k;

	size = 0;
	j = 0;
	k = 0;
	while (env[size])
		size++;
	if (!(new_env = (char **)malloc(sizeof(char *) * (size + 1))))
		exit(-1);
	size = 0;
	while (env[size] && size != index)
	{
		new_env[size] = copy_env_line(env, size);
		size++;
	}
	new_env[size] = sub_replace(command);
	while (env[++size])
		new_env[size] = copy_env_line(env, size);
	return (new_env);
}

char		*sub_replace(char **command)
{
	int			size;
	char		*str;
	int			i;
	int			k;

	i = 0;
	k = 0;
	size = ft_strlen(command[1]) + ft_strlen(command[2]) + 2;
	if (!(str = (char *)malloc(sizeof(char) * size)))
		exit(-1);
	while (command[1][i])
	{
		str[i] = command[1][i];
		i++;
	}
	str[i] = '=';
	i++;
	while (command[2][k])
	{
		str[i + k] = command[2][k];
		k++;
	}
	str[i + k] = '\0';
	return (str);
}

char		**set_env(char **env, char **command)
{
	if (check_env(env, command) != -1 && command[3][0] == '0')
		return (env);
	else if (check_env(env, command) != -1 && command[3][0] != '0')
		return (replace_env_var(env, command, check_env(env, command)));
	else
		return (create_new_var(env, command));
}

char		**create_new_var(char **env, char **command)
{
	int		i;
	char	**new_env;

	i = 0;
	while (env[i])
		i++;
	if (!(new_env = (char **)malloc(sizeof(char *) * (i + 2))))
		exit(-1);
	i = 0;
	while (env[i])
	{
		new_env[i] = copy_env_line(env, i);
		i++;
	}
	new_env[i] = set_new_env_var(command);
	i++;
	while (new_env[i++])
		new_env[i] = NULL;
	return (new_env);
}

char		*set_new_env_var(char **command)
{
	char		*new;
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (!(new = (char *)malloc(sizeof(char) * (ft_strlen(command[1])
						+ ft_strlen(command[2]) + 2))))
		exit(-1);
	while (new && command[1][i])
	{
		new[i] = command[1][i];
		i++;
	}
	new[i] = '=';
	i++;
	while (new && command[2][j])
	{
		new[i + j] = command[2][j];
		j++;
	}
	while (new[i + j++])
		new[i + j] = '\0';
	return (new);
}

char		*copy_env_line(char **env, int index)
{
	int		i;
	char	*str;

	i = 0;
	if (!(str = (char *)malloc(sizeof(char *) * (ft_strlen(env[index]) + 1))))
		exit(-1);
	while (env[index][i] != '\0')
	{
		str[i] = env[index][i];
		i++;
	}
	while (str[i])
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}
