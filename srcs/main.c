/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 18:22:51 by mameyer           #+#    #+#             */
/*   Updated: 2017/07/14 15:45:19 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int		main(int argc, char **argv, char **env)
{
	t_infos		infos;

	(void)argc;
	(void)argv;
	infos.env_changed = 0;
	core(env, &infos);
	return (0);
}
