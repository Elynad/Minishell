/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 11:44:34 by mameyer           #+#    #+#             */
/*   Updated: 2017/08/22 12:56:42 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void		exit_command(char **command, char **env)
{
	if (command)
		free_tab(command);
	if (env)
		free_tab(env);
	exit(EXIT_SUCCESS);
}
