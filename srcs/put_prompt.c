/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_prompt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 12:35:09 by mameyer           #+#    #+#             */
/*   Updated: 2017/08/24 13:33:44 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void		put_prompt(char **env)
{
	int		save;
	int		a;
	int		b;

	ft_putstr("Minishell -> ");
	save = get_rep(env);
	a = 1;
	while (a < save)
	{
		b = a + 1;
		ft_putchar('\n');
		while (b > 1)
		{
			ft_putstr("|-----> ");
			b--;
		}
		ft_putstr("Minishell -> ");
		a++;
	}
}

int			get_rep(char **env)
{
	int		rep;
	char	*shlvl;

	shlvl = get_env_var(env, "SHLVL");
	if (!(shlvl) || (shlvl && ft_strlen(shlvl) == 0))
		rep = 1;
	else
		rep = ft_atoi(shlvl);
	free(shlvl);
	shlvl = NULL;
	return (rep);
}
