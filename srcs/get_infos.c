/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_infos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 19:13:24 by mameyer           #+#    #+#             */
/*   Updated: 2017/07/26 18:55:02 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void		get_env_infos(char **env, t_infos *infos)
{
	int		i;

	i = 0;
	while (env[i])
	{
		if (ft_strstr(env[i], "PWD=") != NULL
				|| ft_strstr(env[i], "OLDPWD=") != NULL
				|| ft_strstr(env[i], "HOME=") != NULL)
			get_env_infos_2(env[i], infos);
		i++;
	}
}

void		get_env_infos_2(char *str, t_infos *infos)
{
	if (ft_strstr(str, "PWD=") != NULL)
		infos->env_pwd = get_after_equal(str);
	if (ft_strstr(str, "OLDPWD=") != NULL)
		infos->env_oldpwd = get_after_equal(str);
	if (ft_strstr(str, "HOME=") != NULL)
		infos->env_home = get_after_equal(str);
}

char		*get_after_equal(char *str)
{
	char		*new;
	int			i;
	int			j;

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
