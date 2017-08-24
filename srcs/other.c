/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 10:33:58 by mameyer           #+#    #+#             */
/*   Updated: 2017/08/24 17:52:57 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void		print_tab(char **tab)
{
	int		a;

	a = 0;
	while (tab[a])
	{
		ft_putendl(tab[a]);
		a++;
	}
}

char		*dup_and_cat(char *s1, char *s2)
{
	char		*final;
	size_t		size;
	int			j;

	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(final = (char *)malloc(sizeof(char) * size)))
		exit(EXIT_FAILURE);
	j = 0;
	size = 0;
	while (s1[size])
	{
		final[size] = s1[size];
		size++;
	}
	while (s2[j])
	{
		final[size + j] = s2[j];
		j++;
	}
	while (final[size + j])
	{
		final[size + j] = '\0';
		j++;
	}
	return (final);
}

char		*get_env_var(char **env, char *name)
{
	int		a;
	int		eq;
	int		i;
	char	*var;

	a = 0;
	i = 0;
	while (env[a])
	{
		eq = 0;
		while (env[a][eq] && env[a][eq] != '=')
			eq++;
		if (ft_strncmp(env[a], name, eq) == 0 && (int)ft_strlen(name) == eq)
			break ;
		a++;
	}
	eq++;
	while (env[a] && env[a][eq + i])
		i++;
	var = get_env_var_2(env, a, eq, i);
	return (var);
}

char		*get_env_var_2(char **env, int a, int eq, int i)
{
	char	*var;

	if (!(var = (char *)malloc(sizeof(char) * (i + 1))))
		exit(EXIT_FAILURE);
	i = 0;
	while (env[a] && env[a][eq + i])
	{
		var[i] = env[a][eq + i];
		i++;
	}
	while (var[i])
	{
		var[i] = '\0';
		i++;
	}
	return (var);
}

char		**get_setenv_commands(char *buf, char *var)
{
	char		**setenv;

	if (!(setenv = (char **)malloc(sizeof(char *) * 5)))
		exit(EXIT_FAILURE);
	setenv[0] = ft_strdup("setenv");
	setenv[1] = ft_strdup(var);
	setenv[2] = ft_strdup(buf);
	setenv[3] = ft_strdup("1");
	setenv[4] = NULL;
	return (setenv);
}
