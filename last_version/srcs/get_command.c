/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 19:13:03 by mameyer           #+#    #+#             */
/*   Updated: 2017/07/27 21:05:23 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char		**get_command(char *str)
{
	char		**command;
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (!(command = (char **)malloc(sizeof(char *) * (get_spaces(str) + 2))))
		exit(-1);
	while (str[j] && str[j] == ' ')
		j++;
	while (i < (get_spaces(str) + 1))
	{
		command[i] = get_until_next_sp(str, &j);
		i++;
	}
	while (command[i])
	{
		command[i] = NULL;
		i++;
	}
	return (command);
}

char		*get_until_next_sp(char *str, int *index)
{
	int		i;
	char	*command;

	i = *index;
	while (str && str[i] && str[i] != ' ')
		i++;
	if (!(command = (char *)malloc(sizeof(char) * i + 1)))
		exit(-1);
	i = 0;
	while (str && str[*index] && str[*index] != ' ')
	{
		command[i] = str[*index];
		i++;
		(*index)++;
	}
	while (command[i])
	{
		command[i] = '\0';
		i++;
	}
	while (str && str[*index] && str[*index] == ' ')
		(*index)++;
	return (command);
}

int			get_spaces(char *str)
{
	int		i;
	int		sp;

	i = 0;
	sp = 1;
	while (str[i] && str[i] == ' ')
		i++;
	while (str[i])
	{
		if (str[i] == ' ')
			sp++;
		i++;
	}
	return (sp);
}
