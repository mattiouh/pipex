/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 10:18:41 by marvin            #+#    #+#             */
/*   Updated: 2023/06/08 10:18:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;

	pipex = malloc(sizeof(t_pipex));
	if (argc < 5)
		error("not enough arguments\n");
	if (pipe(pipex->fd) == -1)
		error("pipe didn't work properly\n");
	pipex->in_fd = open(argv[1], O_RDONLY);
	if (pipex->in_fd == -1)
		error("reading error\n");
	pipex->out_fd = open(argv[4], O_TRUNC | O_CREAT | O_RDWR, 0777);
	if (pipex->out_fd == -1)
		error("reading error\n");
	checking_argv(pipex, argv, envp);
	if (sex(pipex) < 0)
		return (1);
	close(pipex->fd[0]);
	close(pipex->fd[1]);
	waitpid(pipex->pid1, NULL, 0);
	waitpid(pipex->pid2, NULL, 0);
	cancel(pipex);
	return (0);
}

void	checking_argv(t_pipex *pipex, char **argv, char **envp)
{
	int	x;
	int	y;

	pipex->temp2 = remover(argv[2]);
	pipex->temp2_matrix = ft_split(pipex->temp2, ' ');
	x = checazzoneso(pipex->temp2_matrix);
	pipex->argv2 = ft_calloc((x + 1), sizeof(char *));
	pipex->argv2 = moving_matrix(pipex, pipex->argv2,
			pipex->temp2_matrix, envp);
	pipex->temp3 = remover(argv[3]);
	pipex->temp3_matrix = ft_split(pipex->temp3, ' ');
	y = checazzoneso(pipex->temp3_matrix);
	pipex->argv3 = ft_calloc((y + 1), sizeof(char *));
	pipex->argv3 = moving_matrix(pipex, pipex->argv3,
			pipex->temp3_matrix, envp);
}

char	**moving_matrix(t_pipex *pipex, char **final_matrix,
	char **temp_matrix, char **envp)
{
	int		x;
	int		j;
	int		k;
	char	*path;

	x = 1;
	j = 1;
	path = ranger(pipex, temp_matrix[0], envp);
	final_matrix[0] = ft_calloc((ft_strlen(path) + 1), sizeof(char));
	final_matrix[0] = ft_memmove(final_matrix[0], path, ft_strlen(path));
	while (temp_matrix[j])
	{
		k = ft_strlen(temp_matrix[j]);
		final_matrix[x] = ft_calloc((ft_strlen(temp_matrix[j])), sizeof(char));
		final_matrix[x] = ft_memmove(final_matrix[x], temp_matrix[j], k);
		x++;
		j++;
	}
	final_matrix[j] = NULL;
	cleaner1(temp_matrix);
	return (final_matrix);
}

char	*remover(char *temp)
{
	int	i;

	i = 0;
	while (temp[i++])
	{
		if (temp[i] == '\'' || temp[i] == '\"')
			temp[i] = ' ';
	}
	return (temp);
}

int	checazzoneso(char **temp_matrix)
{
	int	i;

	i = 0;
	while (temp_matrix[i])
		i++;
	return (i);
}
