/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 15:14:55 by mameyer           #+#    #+#             */
/*   Updated: 2017/07/24 19:13:16 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void		core(char **env, t_infos *infos)
{
	char		**options;
	char		**new_env;
	char		*str;

	ft_putstr("minishell $> ");
	while (get_next_line(0, &str))
	{
		if (ft_strlen(str) != 0)
		{
			options = get_options(str);
			if (check_commands(options[0]) == 1)
				fork_func(options, env, infos);
			else if (my_commands(options, env, infos) != 1)
				core(env, infos);
			else if (check_env_commands(options) == 1)
			{
				new_env = env_funcs(env, options);
				if (infos->env_changed == 1)
					free_env(env);
				infos->env_changed = 1;
				core(new_env, infos);
			}
			else
			{
				ft_putstr("minishell: command not found: ");
				ft_putendl(options[0]);
				core(env, infos);
			}
			if (options)
				free_opt(options);
		}
	}
}
