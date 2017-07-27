/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 19:05:16 by mameyer           #+#    #+#             */
/*   Updated: 2017/07/27 21:38:55 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void		print_env(t_env *env)
{
	if (env && env->hidden == 0)
	{
		ft_putstr(env->name);
		ft_putchar('=');
		ft_putendl(env->value);
	}
	if (env->next)
		print_env(env->next);
}

void		print_array(char **array)
{
	int		i;

	i = 0;
	while (array[i])
	{
		ft_putendl(array[i]);
		i++;
	}
}
