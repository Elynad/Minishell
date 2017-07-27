/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 15:05:50 by mameyer           #+#    #+#             */
/*   Updated: 2017/07/26 15:07:29 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void		print_test(char **double_string)
{
	int		i;

	i = 0;
	while (double_string[i])
	{
		ft_putendl(double_string[i]);
		i++;
	}
	ft_putchar('\n');
}
