/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 18:13:12 by mameyer           #+#    #+#             */
/*   Updated: 2017/07/27 23:25:26 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int		main(int argc, char **argv, char **env)
{
	t_env			*environnement;
	t_infos			*infos;

	(void)argc;
	(void)argv;
	environnement = get_env(env);
	if (!(infos = malloc(sizeof(t_infos))))
		exit(-1);
	infos->home = ft_strdup("/Users/mameyer/");
	core(environnement);
	free_env(environnement);
	return (0);
}
