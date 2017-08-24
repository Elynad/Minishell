/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 13:19:43 by mameyer           #+#    #+#             */
/*   Updated: 2017/08/21 15:17:35 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void		echo_command(char **command, char **env)
{
	int		a;

	a = 1;
	if (!command[a])
		ft_putchar('\n');
	else
	{
		while (command[a])
		{
			ft_putstr(command[a]);
			a++;
			if (command[a])
				ft_putchar(' ');
			else
				ft_putchar('\n');
		}
	}
	free_tab(command);
	core(env);
}
