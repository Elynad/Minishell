/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 18:21:52 by mameyer           #+#    #+#             */
/*   Updated: 2017/07/14 15:47:07 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H

# define MINISHELL_H

# include "../libft/libft.h"
# include <unistd.h>

typedef struct			s_infos
{
	int					env_changed;
}						t_infos;

int		check_commands(char *str);		// test
void	execute(char **command);

char	**get_options(char *str);
int		get_spaces(char *str);
char	*copy_until_nxt_sp(char *str, int *index);

void	print_test(char **options);

void	free_opt(char **options);

//	______________________________________________________________

int			check_env_commands(char **str);
char		**env_funcs(char **env, char **command);
char		*copy_env_line(char **env, int index);
char		*set_new_env_var(char **command);
int			check_env(char **env, char **command);
char		**replace_env_var(char **env, char **command, int index);
char		*sub_replace(char **command);
char		**create_new_var(char **env, char **command);

char		**delete_env_var(char **env, char **command);

void		core(char **env, t_infos *infos);
void		sub_core(char **env);
void		fork_func(char **options, char **env, t_infos *infos);
int			my_commands(char **options, char **env);
void		clear_command(void);

void		print_env(char **env);
char		**set_env(char **env, char **command);
char		**unset_env(char **env, char **command);

void		free_env(char **env);

#endif
