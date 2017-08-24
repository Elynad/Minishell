/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_default_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 18:25:36 by mameyer           #+#    #+#             */
/*   Updated: 2017/08/23 19:46:31 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char		**set_default_env(void)
{
	char		**new_env;
	char		*buffer;

	if (!(new_env = (char **)malloc(sizeof(char *) * 5)))
		exit(EXIT_FAILURE);
	buffer = dup_and_cat("PATH=", DEFAULT_PATH_1);
	new_env[0] = dup_and_cat(buffer, DEFAULT_PATH_2);
	free(buffer);
	buffer = NULL;
	new_env[1] = dup_and_cat("HOME=", DEFAULT_HOME);
	new_env[2] = dup_and_cat("TERM=", DEFAULT_TERM);
	new_env[3] = dup_and_cat("SHLVL=", DEFAULT_SHLVL);
	new_env[4] = NULL;
	return (new_env);
}
