/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 14:48:47 by mameyer           #+#    #+#             */
/*   Updated: 2017/07/26 17:28:13 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void		free_opt(char **options)
{
	int		i;

	i = 0;
	while (options[i])
	{
		free(options[i]);
		options[i] = NULL;
		i++;
	}
	ft_putendl("// FREE SUCCESSFUL");
}
