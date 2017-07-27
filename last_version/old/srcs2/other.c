/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 21:03:00 by mameyer           #+#    #+#             */
/*   Updated: 2017/07/27 16:25:20 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void		env_usage(int type)
{
	if (type == 0)
	{
		ft_putendl("Incorrect arguments.");
		ft_putendl("setenv 'ENV_VAR' 'value' [overwrite]");
	}
	else if (type == 1)
	{
		ft_putendl("Incorrect arguments.");
		ft_putendl("unsetenv 'ENV_VAR'");
	}
}

int			check_current_dir(char *str)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '.' && str[i + 1] == '/')
		{
			i++;
			j++;
		}
		i++;
	}
	if (j == (int)ft_strlen(str) / 2)
		return (1);
	return (0);
}
