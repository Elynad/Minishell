/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 21:33:51 by mameyer           #+#    #+#             */
/*   Updated: 2017/07/27 21:50:07 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void		unset_env(t_env *env, char **command)
{
	if (command[1] && ft_strlen(command[1]) != 0
			&& (!command[2] || ft_strlen(command[2]) == 0))
		unset_env_2(env, command);
	else if ((command[1] && ft_strlen(command[1]) == 0) || command[2])
	{
		ft_putendl("Wrong arguments for unsetenv");
		ft_putendl("unsetenv 'NAME'");
	}
}

void		unset_env_2(t_env *env, char **command)
{
	if (env && env->name && ft_strcmp(env->name, command[1]) == 0)
		env->hidden = 1;
	else if (env && env->next)
		unset_env_2(env->next, command);
}
