/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:18:04 by marvin            #+#    #+#             */
/*   Updated: 2023/06/13 15:18:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <signal.h>
# include "libft/libft.h"

typedef struct pipe{
	int		fd[2];
	int		in_fd;
	int		out_fd;
	int		pid1;
	int		pid2;
	char	**temp2_matrix;
	char	**temp3_matrix;
	char	**argv2;
	char	**argv3;
	char	*temp2;
	char	*temp3;
	char	**tacos;
	int		count;
	int		flag;
	char	*burritos;
	char	*slash;
	int		i;
}	t_pipex;

char	**moving_matrix(t_pipex *pipex, char **final_matrix,
			char **temp_matrix, char **envp);
int		main(int argc, char **argv, char **envp);
void	checking_argv(t_pipex *pipex, char **argv, char **envp);
int		sex(t_pipex *pipex);
void	cancel(t_pipex *pipex);
void	cleaner2(t_pipex *pipex);
void	cleaner1_1(char ***matrix);
void	cleaner1(char **matrix);
char	*remover(char *temp);
char	*remover(char *temp);
char	*ranger(t_pipex *pipex, char *temp, char **envp);
char	*ft_pathfinder(char *dst, char *src);
int		checazzoneso(char **temp_matrix);
void	cleaner(char **argv);
char	*finder(t_pipex *pipex, char *temp, char *path);
void	print_matrix(char **matrix);
char	*command_finder(char **tacos, char *temp);
void	free_tacos(char **tacos, int i);
void	iteration(t_pipex *pipex, int i, char *temp);
void	error(char *str);

#endif
