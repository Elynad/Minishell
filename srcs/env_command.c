/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 11:48:07 by mameyer           #+#    #+#             */
/*   Updated: 2017/08/21 15:18:18 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void		env_command(char **command, char **env)
{
	if (command[1])
		ft_putendl("Wrong arguments for 'env'.\nUsage : 'env'");
	else
		print_tab(env);
	free_tab(command);
	core(env);
}
