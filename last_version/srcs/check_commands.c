/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 19:11:41 by mameyer           #+#    #+#             */
/*   Updated: 2017/07/27 19:46:33 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int			check_builtins(char **str)
{
	if (ft_strcmp(str[0], "cd") == 0
			|| ft_strcmp(str[0], "echo") == 0
			|| ft_strcmp(str[0], "setenv") == 0
			|| ft_strcmp(str[0], "unsetenv") == 0
			|| ft_strcmp(str[0], "env") == 0
			|| ft_strcmp(str[0], "exit") == 0)
		return (1);
	return (0);
}
