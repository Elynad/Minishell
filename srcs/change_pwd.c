/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_pwd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 21:44:50 by mameyer           #+#    #+#             */
/*   Updated: 2017/07/24 21:57:20 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char		**change_pwd(char *str, char **env)
{
	char		**new_env;
	char		**command;
	char		*new_pwd;

	ft_putendl("Changing pwd env var");
	if (!(command = (char **)malloc(sizeof(char *) * 5)))
		exit(-1);
	command[0] = ft_strdup("setenv");
	command[1] = ft_strdup("PWD");
	command[2] = ft_strdup(str);
	command[3] = ft_strdup("1");
	command[4] = NULL;
	new_env = set_env(env, command);
	return (new_env);
}
