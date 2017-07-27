/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_infos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 18:30:50 by mameyer           #+#    #+#             */
/*   Updated: 2017/07/27 14:39:14 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void		get_infos(char **env, t_infos *infos)
{
	int		i;

	infos->env_changed = 0;
	i = 0;
	while (env[i])
	{
		if (ft_strstr(env[i], "PWD") != NULL
				|| ft_strstr(env[i], "OLDPWD=") != NULL
				|| ft_strstr(env[i], "HOME=") != NULL
				|| ft_strstr(env[i], "PATH=") != NULL)
			get_infos_2(env[i], infos);
		i++;
	}
}

void		get_infos_2(char *str, t_infos *infos)
{
	if (ft_strstr(str, "PWD=") != NULL && ft_strstr(str, "OLDPWD=") == NULL)
		infos->env_pwd = get_after_equal(str);
	else if (ft_strstr(str, "OLDPWD=") != NULL)
		infos->env_oldpwd = get_after_equal(str);
	else if (ft_strstr(str, "HOME=") != NULL)
		infos->env_home = get_after_equal(str);
	else if (ft_strstr(str, "PATH=") != NULL)
		infos->env_path = get_path(str);
}

char		*get_after_equal(char *str)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] != '=')
		i++;
	i++;
	if (!(new = (char *)malloc(sizeof(char) * (ft_strlen(str) - i))))
		exit(-1);
	while (str[i + j])
	{
		new[j] = str[i + j];
		j++;
	}
	return (new);
}
