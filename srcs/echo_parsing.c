/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 22:00:36 by mameyer           #+#    #+#             */
/*   Updated: 2017/07/24 22:05:01 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char		**echo_parsing(char **command)
{
	char	**new;
	int		len;

	len = 0;
	while (command[len])
		len++;
	if (!(new = (char **)malloc(sizeof(char *) * (len + 1))))
		exit(-1);
	len = 0;
	while (command[len])
	{
		new[len] = copy_without_quotes(command[len]);
		len++;
	}
	return (new);
}

char		*copy_without_quotes(char *str)
{
	// echo sometimes put the quotes when they are alone
}
