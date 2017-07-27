/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 18:22:51 by mameyer           #+#    #+#             */
/*   Updated: 2017/07/24 20:21:49 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int		main(int argc, char **argv, char **env)
{
	t_infos		*infos;

	if (!(infos = malloc(sizeof(t_infos))))
		exit(-1);
	(void)argc;
	(void)argv;
	get_env_infos(env, infos);
	infos->env_changed = 0;
	core(env, infos);
	return (0);
}
