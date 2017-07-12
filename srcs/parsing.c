/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 20:16:28 by mameyer           #+#    #+#             */
/*   Updated: 2017/07/12 15:14:47 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char		**get_options(char *str)
{
	char	**options;
	int		i;
	int		j;
	int		spaces;

	i = 0;
	j = 0;
	spaces = get_spaces(str);
	if (!(options = (char **)malloc(sizeof(char *) * (get_spaces(str) + 2))))
		exit(-1);
	while (str[i] && str[i] == ' ')
		i++;
	while (str[i] && str[i] == ' ')
		i++;
	while (j < get_spaces(str) + 1)
	{
		options[j] = copy_until_nxt_sp(str, &i);
		j++;
	}
	options[spaces + 1] = NULL;
	return (options);
}

char		*copy_until_nxt_sp(char *str, int *index)
{
	char		*opt;
	int			i;
	int			j;

	i = *index;
	j = 0;
	while (str[i] && str[i] == ' ')
		i++;
	while (str[i] && str[i] != ' ')
		i++;
	if (!(opt = (char *)malloc(sizeof(char) * (i - *index + 1))))
		exit(-1);
	i = *index;
	while (str[i] && str[i] != ' ')
	{
		opt[j] = str[i];
		j++;
		i++;
	}
	while (opt[j])
	{
		opt[j] = '\0';
		j++;
	}
	*index = i;
	while (str[*index] == ' ')
		(*index)++;
	return (opt);
}

int			get_spaces(char *str)
{
	int		i;
	int		sp;

	i = 0;
	sp = 0;
	while (str && str[i])
	{
		if (str[i] == ' ')
			sp++;
		i++;
	}
	return (sp);
}

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
}

void		print_test(char **options)
{
	int		i;

	i = 0;
	while (options && options[i])
	{
		ft_putstr("\nOption ");
		ft_putnbr(i);
		ft_putstr(" = ");
		ft_putstr(options[i]);
		i++;
	}
	ft_putchar('\n');
}
