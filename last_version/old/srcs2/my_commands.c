/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_commands.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 17:31:59 by mameyer           #+#    #+#             */
/*   Updated: 2017/07/27 18:05:09 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void		my_commands(char **options, char **env, t_infos *infos)
{
	if (ft_strcmp(options[0], "clear") == 0)
		clear_command();
	else if (ft_strcmp(options[0], "cd") == 0)
		change_directory(options, env, infos);
}

void		clear_command(void)
{
	int		i;

	i = 76;
	while (i >= 0)
	{
		ft_putchar('\n');
		i--;
	}
}

void		change_directory(char **option, char **env, t_infos *infos)
{
	char		**new_env;
	char		test[1024];

	ft_putendl("// Entering change_directory func");
	new_env = NULL;
	if (option)
	{
		if (!option[1]
				|| (option[1] && option[1][0] == '~' && (!option[1][1]
						|| option[1][1] == '/') && !option[2]))
		{
			if (chdir(infos->env_home) != -1)
			{
				new_env = replace_env_line(env, "PWD", infos->env_home);
				free_opt(env);
				free_opt(option);
				core(new_env, infos);
			}
			else
				ft_putendl("No such file or directory");
		}
		else if (option && option[1] && !option[2])
		{
			if (chdir(option[1]) != -1)
			{
				new_env = replace_env_line(env, "OLDPWD", infos->env_pwd);
				getcwd(test, 1024);
				free(infos->env_oldpwd);
				infos->env_oldpwd = NULL;
				infos->env_oldpwd = ft_strdup(infos->env_pwd);
				free(infos->env_pwd);
				infos->env_pwd = NULL;
				infos->env_pwd = ft_strdup(test);
				new_env = replace_env_line(env, "PWD", test);
				free_opt(env);
				core(new_env, infos);
			}
			else
				ft_putendl("No such file or directory");
		}
		else if (option && option[1] && option[2])
		{
			ft_putstr("cd: string not in pwd: ");
			ft_putendl(option[1]);
		}
		free_opt(option);
	}
	core(env, infos);
}

char		**replace_env_line(char **env, char *env_var, char *value)
{
	char		**new_env;
	char		**command;

	if (!(command = (char **)malloc(sizeof(char *) * 5)))
		exit(-1);
	command[0] = ft_strdup("setenv");
	command[1] = ft_strdup(env_var);
	command[2] = ft_strdup(value);
	command[3] = ft_strdup("1");
	command[4] = NULL;
	ft_putendl("In replace_env_line, COMMAND = ");
	print_test(command);
	ft_putendl("In replace_env_line, ENV = ");
	print_test(env);
	new_env = set_env(env, command);
	free_opt(command);
	return (new_env);
}
