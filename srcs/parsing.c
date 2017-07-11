/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 20:16:28 by mameyer           #+#    #+#             */
/*   Updated: 2017/07/11 21:11:18 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char		*get_command(char *str)
{
	char		*command;
	int			i;

	i = 0;
	while (str && str[i] && str[i] != ' ')
		i++;
	if (!(command = (char *)malloc(sizeof(char) * i)))
		exit(-1);
	i = 0;
	while (str && str[i] && str[i] != ' ')
	{
		command[i] = str[i];
		i++;
	}
	while (command[i])
	{
		command[i] = '\0';
		i++;
	}
	return (command);
}

char		**get_opt_flg(char *str)
{
	char		**options;
	int			i;
	int			sp;

	i = 0;
	sp = 0;
	options = NULL;
	if (str)
	{
		while (str && str[i])
		{
			if (str[i] == ' ')
				sp++;
			i++;
		}
		if (!(options = (char **)malloc(sizeof(char *) * sp)))
			exit(-1);
		get_opt_flg_2(&options, str);
		get_opt_flg_3(&options, str);
		print_test(options);
	}
	return (options);
}

void		get_opt_flg_2(char ***options, char *str)
{
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	while (str && str[i] && str[i] != ' ')
		i++;
	while (str && str[i] && str[i] == ' ')
		i++;
	while (str && str[i] && *options[j])
	{
		len = 0;
		while (str[i] && str[i + len] && str[i + len] != ' ')
			len++;
		i += len;
		if (!(*options[j] = (char *)malloc(sizeof(char) * len)))
			exit(-1);
		j++;
	}
}

void		get_opt_flg_3(char ***options, char *str)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (str && str[i] && str[i] != ' ')
		i++;
	while (str && str[i] && *options[j])
	{
		k = 0;
		while (str && str[i + k] && str[i + k] != ' ')
		{
			*options[j][k] = str[i + k];
			k++;
		}
		*options[j][k] = '\0';
		i += k;
		j++;
	}
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
		ft_putstr("Option ");
		ft_putnbr(i);
		ft_putstr(" = ");
		ft_putstr(options[i]);
		ft_putchar('\n');
		i++;
	}
}
