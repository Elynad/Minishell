/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 11:45:02 by mameyer           #+#    #+#             */
/*   Updated: 2017/08/23 18:08:27 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void		free_tab(char **tab)
{
	int		a;

	a = 0;
	while (tab[a])
	{
		free(tab[a]);
		tab[a] = NULL;
		a++;
	}
	free(tab);
	tab = NULL;
}
