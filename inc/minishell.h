/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 18:21:52 by mameyer           #+#    #+#             */
/*   Updated: 2017/07/11 20:54:09 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H

# define MINISHELL_H

# include "../libft/libft.h"
# include <unistd.h>

int		check_commands(char *str);		// test
void	core(char **argv);				// test
void	execute(char *str, char **argv);

char	*get_command(char *str);
char	**get_opt_flg(char *str);
void	get_opt_flg_2(char ***options, char *str);
void	get_opt_flg_3(char ***options, char *str);

void	print_test(char **options);

void	free_opt(char **options);

#endif
