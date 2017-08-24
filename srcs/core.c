/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 11:32:31 by mameyer           #+#    #+#             */
/*   Updated: 2017/08/24 15:14:23 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void		core(char **env)
{
	char		*str;
	char		**command;

	put_prompt(env);
	while (get_next_line(0, &str))
	{
		if (check(str) == -1)
		{
			secure_putstr(str);
			core(env);
		}
		else if (check(str) == 2)
		{
			ft_putendl(".: not enough arguments");
			core(env);
		}
		else if (str && ft_strlen(str) > 0 && check_spaces(str))
		{
			command = str_split(str, ' ', 1);
			check_command(command, env);
		}
		else
			core(env);
	}
	free_tab_exit(env);
}

int			check_spaces(char *str)
{
	int		a;
	int		b;

	a = 0;
	b = 0;
	while (str[a])
	{
		if (str[a] == ' ' || str[a] == '\t')
			b++;
		a++;
	}
	if (a == b)
		return (0);
	else
		return (1);
}

int			check(char *str)
{
	int		a;

	if (str && ft_strlen(str) == 1 && str[0] == '.')
		return (2);
	a = 0;
	while (str[a])
	{
		if (str[a] < 32 || str[a] > 126)
			return (-1);
		a++;
	}
	return (0);
}

void		secure_putstr(char *str)
{
	int		a;

	ft_putstr("minishell: command not found: ");
	a = 0;
	while (str[a])
	{
		if (str[a] >= 33 && str[a] <= 126)
			ft_putchar(str[a]);
		a++;
	}
	ft_putchar('\n');
}
