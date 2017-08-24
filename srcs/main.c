/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 09:56:59 by mameyer           #+#    #+#             */
/*   Updated: 2017/08/24 17:54:50 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int			main(int argc, char **argv, char **env)
{
	char		**new_env;

	(void)argc;
	(void)argv;
	new_env = NULL;
	if (!(env[0]))
		new_env = set_default_env();
	else
		new_env = dup_env(env);
	core(new_env);
	return (0);
}
