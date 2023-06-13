/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pip_cleaner.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:20:11 by marvin            #+#    #+#             */
/*   Updated: 2023/06/13 15:20:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "pipex.h"

void	cancel(t_pipex *pipex)
{
	close(pipex->out_fd);
	close(pipex->in_fd);
	cleaner1(pipex->argv2);
	cleaner1(pipex->argv3);
	free(pipex);
}

void	cleaner1(char **matrix)
{
	int	x;

	x = -1;
	while (matrix[++x])
		free (matrix[x]);
	free(matrix);
}

void	error(char *str)
{
	ft_putstr_fd(str, 1);
	exit(1);
}
