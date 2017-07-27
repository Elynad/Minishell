/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 19:02:39 by mameyer           #+#    #+#             */
/*   Updated: 2017/07/27 19:39:50 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void		free_env(t_env *env)
{
	t_env		*tmp;

	tmp = NULL;
	if (env && env->next)
		tmp = env->next;
	if (env)
	{
		free(env->name);
		free(env->value);
		free(env);
	}
	if (tmp)
		free_env(tmp);
}

void		free_command(char **command)
{
	int		i;

	i = 0;
	while (command[i])
	{
		free(command[i]);
		command[i] = NULL;
		i++;
	}
}
