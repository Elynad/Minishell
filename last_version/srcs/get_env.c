/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 18:31:16 by mameyer           #+#    #+#             */
/*   Updated: 2017/07/27 20:11:01 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

t_env		*get_env(char **environnement)
{
	int		i;
	t_env	*env;

	i = 0;
	if (!(env = malloc(sizeof(t_env))))
		exit(-1);
	env->name = get_until_eq(environnement[i]);
	env->value = get_after_eq(environnement[i]);
	env->hidden = 0;
	env->next = NULL;
	i++;
	while (environnement[i])
	{
		get_elem(env, environnement[i]);
		i++;
	}
	return (env);
}

void		get_elem(t_env *env, char *str)
{
	if (env && env->next)
		get_elem(env->next, str);
	else if (env && !(env->next))
	{
		if (!(env->next = malloc(sizeof(t_env))))
			exit(-1);
		env->next->next = NULL;
		env->next->name = get_until_eq(str);
		env->next->value = get_after_eq(str);
		env->hidden = 0;
	}
}

char		*get_after_eq(char *str)
{
	int		i;
	int		j;
	char	*value;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	if (!(value = (char *)malloc(sizeof(char) * (ft_strlen(str) - i + 1))))
		exit(-1);
	i++;
	j = 0;
	while (str[i + j])
	{
		value[j] = str[i + j];
		j++;
	}
	while (value[j])
	{
		value[j] = '\0';
		j++;
	}
	return (value);
}

char		*get_until_eq(char *str)
{
	int		i;
	char	*name;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	if (!(name = (char *)malloc(sizeof(char) * (i + 1))))
		exit(-1);
	i = 0;
	while (str[i] && str[i] != '=')
	{
		name[i] = str[i];
		i++;
	}
	while (name[i])
	{
		name[i] = '\0';
		i++;
	}
	return (name);
}
