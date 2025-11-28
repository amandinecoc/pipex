/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amandine <amandine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 02:33:24 by amandine          #+#    #+#             */
/*   Updated: 2025/11/28 16:01:24 by amandine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex(t_pipex *data, char **envp)
{
    int		fd1;
    int		fd2;
    pid_t	pid;

    fd1 = open(data->file1, O_RDONLY);
    fd2 = open(data->file2, O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd1 == -1 || fd2 == -1)
        return (perror("open"), (void)0);
    pid = fork();
    if (pid < 0)
        return (perror("fork"), (void)0);
    if (pid == 0)
    {
        if (dup2(fd1, STDIN_FILENO) == -1 || dup2(fd2, STDOUT_FILENO) == -1)
            return (perror("dup2"), _exit(1));
        close(fd1);
        close(fd2);
        execve(data->cmd1, data->tab_cmd1, envp);
        perror("execve");
        _exit(1);
    }
    close(fd1);
    close(fd2);
    waitpid(pid, NULL, 0);
}
