/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 14:27:37 by mameyer           #+#    #+#             */
/*   Updated: 2017/07/27 18:05:09 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int			main(int argc, char **argv, char **env)
{
	t_infos		*infos;
	char		**new_env;

	(void)argc;
	(void)argv;
	if (!(infos = malloc(sizeof(t_infos))))
		exit(-1);
	get_infos(env, infos);
	new_env = duplicate_env(env, infos);
	core(new_env, infos);
	return (0);
}
