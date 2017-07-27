/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 14:40:57 by mameyer           #+#    #+#             */
/*   Updated: 2017/07/27 18:05:09 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void		core(char **env, t_infos *infos)
{
	char		*str;
	char		**options;
	char		**new_env;

	ft_putendl(infos->env_home);
	ft_putendl(infos->env_pwd);
	ft_putendl(infos->env_oldpwd);
	new_env = NULL;
	ft_putstr("minishell $> ");
	while (get_next_line(0, &str))
	{
		if (ft_strlen(str) != 0)
		{
			options = get_options(str);
			if (check_command(options) == 1)
				fork_func(options, env, infos);
			else if (ft_strcmp(options[0], "env") == 0)
				print_test(env);
			else if (check_my_commands(options) == 1)
				my_commands(options, env, infos);
			else if (check_env_commands(options, 0) == 1)
			{
				new_env = env_funcs(env, options, infos);
				free_opt(env);
				core(new_env, infos);
			}
			else if (ft_strcmp(options[0], "exit") == 0)
			{
				free_opt(env);
				free(infos->env_home);
				free(infos->env_pwd);
				free(infos->env_oldpwd);
				exit(0);
			}
			else if (check_command(options) == 3
					|| check_my_commands(options) == 3
					|| check_env_commands(options, 1) == 3)
			{
				ft_putstr("minishell: command not found: ");
				ft_putendl(options[0]);
				ft_putendl("Type 'help' for more informations.");
			}
			if (options)
				free_opt(options);
		}
		ft_putendl("// Going back in core func //");
		core(env, infos);
	}
}
