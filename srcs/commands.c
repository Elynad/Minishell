/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 18:53:48 by mameyer           #+#    #+#             */
/*   Updated: 2017/07/11 19:42:36 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int			check_commands(char *str)
{
	if (ft_strcmp(str, "ls") == 0
			|| ft_strcmp(str, "echo") == 0
			|| ft_strcmp(str, "cd") == 0
			|| ft_strcmp(str, "setenv") == 0)
		return (1);
	else
		return (0);
}
