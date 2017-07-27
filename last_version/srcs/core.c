/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 19:08:07 by mameyer           #+#    #+#             */
/*   Updated: 2017/07/27 21:50:58 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void		core(t_env *env)
{
	char		*str;
	char		**command;

	ft_putstr("minishell $> ");
	while (get_next_line(0, &str))
	{
		if (ft_strlen(str) != 0)
		{
			command = get_command(str);
			if (check_builtins(command) == 1)
				builtins(command, env);
			else
				ft_putchar('9');
			free_command(command);
		}
		core(env);
	}
}
