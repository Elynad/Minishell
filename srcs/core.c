/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 15:14:55 by mameyer           #+#    #+#             */
/*   Updated: 2017/07/12 18:45:44 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void		core(char **env)
{
	char		*str;

	ft_putstr("minishell $> ");
	while (get_next_line(0, &str))
		sub_core(str, env);
}

void		sub_core(char *line, char **env)
{
	char		**options;
	char		**new_env;

	if (ft_strlen(line) != 0)
	{
		options = get_options(line);
		if (check_commands(options[0]) == 1)
			fork_func(options, env);
		else if (my_commands(options, env) != 1)
			core(env);
		else if (check_env_commands(options) == 1)
		{
			new_env = env_funcs(env, options);
			core(new_env);
		}
		else
		{
			ft_putstr("minishell: command not found: ");
			ft_putendl(options[0]);
			core(env);
		}
		if (options)
			free_opt(options);
	}
}
