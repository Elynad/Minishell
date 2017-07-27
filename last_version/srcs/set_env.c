/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 20:11:08 by mameyer           #+#    #+#             */
/*   Updated: 2017/07/27 23:22:53 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void		set_env(t_env *env, char **command)
{
	if (command[1] && command[2] && (ft_strlen(command[3]) != 0))
		set_env_2(env, command);
	else
	{
		ft_putendl("Wrong arguments for setenv.");
		ft_putendl("setenv 'NAME' 'value' [overwrite]");
	}
}

void		set_env_2(t_env *env, char **command)
{
	if (env && env->name && ft_strcmp(env->name, command[1]) == 0)
	{
		if (command[3][0] != '0')
		{
			env->hidden = 0;
			free(env->value);
			env->value = NULL;
			env->value = ft_strdup(command[2]);
		}
		else if (command[3][0] == '0' && env->hidden == 1)
		{
			free(env->value);
			env->value = NULL;
			env->value = ft_strdup(command[2]);
			env->hidden = 0;
		}
	}
	else if (env && !(env->next))
	{
		if (!(env->next = malloc(sizeof(t_env))))
			exit(-1);
		env->next->next = NULL;
		env->next->name = ft_strdup(command[1]);
		env->next->value = ft_strdup(command[2]);
		env->next->hidden = 0;
	}
	else if (env && env->next)
		set_env(env->next, command);
}

void		modify_env_var(t_env *env, char *name, char *value)
{
	if (env && env->name && ft_strcmp(env->name, name) == 0)
	{
		free(env->value);
		env->value = NULL;
		env->value = ft_strdup(value);
	}
	else if (!(env->next))
	{
		if (!(env->next = malloc(sizeof(t_env))))
			exit(-1);
		env->next->next = NULL;
		env->next->name = ft_strdup(name);
		env->next->value = ft_strdup(value);
		env->next->hidden = 0;
	}
	else if (env->next)
		modify_env_var(env->next, name, value);
}

char		*get_env_value(t_env *env, char *name)
{
	char		*value;

	value = NULL;
	if (env && env->name && ft_strcmp(env->name, name) == 0)
	{
		value = ft_strdup(env->value);
		return (value);
	}
	else if (env->next)
		return (get_env_value(env->next, name));
	else
		return (value);
}
