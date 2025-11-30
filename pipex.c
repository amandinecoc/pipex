/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amandine <amandine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 03:03:28 by acocoual          #+#    #+#             */
/*   Updated: 2025/11/30 18:52:13 by amandine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int first_process(t_pipex *data, char **envp, int *pipefd)
{
    int infile_fd;
    
    if (access(data->file1, F_OK) != 0)
        return(perror("access"), EXIT_FAILURE);
    infile_fd = open(data->file1, O_RDONLY);
    if (infile_fd == -1)
        return (perror("open"), close(infile_fd), EXIT_FAILURE);
    close(pipefd[0]);
    dup2(infile_fd, STDIN_FILENO);
    dup2(pipefd[1], STDOUT_FILENO);
    close(pipefd[1]);
    close(infile_fd);
    execve(data->cmd1, data->tab_cmd1, envp);
    perror("execve");
    return(EXIT_FAILURE);
}

int second_process(t_pipex *data, char **envp, int *pipefd)
{
    int outfile_fd;
    
    outfile_fd = open(data->file2, O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (outfile_fd == -1)
        return (perror("open"), close(outfile_fd), EXIT_FAILURE);
    dup2(pipefd[0], STDIN_FILENO);
    dup2(outfile_fd, STDOUT_FILENO);
    close(pipefd[0]);
    close(outfile_fd);
    execve(data->cmd2, data->tab_cmd2, envp);
    perror("execve");
    return(EXIT_FAILURE);
}

int	pipex(t_pipex *data, char **envp)
{
    int pipefd[2];
    pid_t pid1;
    pid_t pid2;
    int status;

    if (pipe(pipefd) == -1)
        return (perror("pipe"), EXIT_FAILURE);
    pid1 = fork();
    if (pid1 == -1)
        return (perror("fork"), EXIT_FAILURE);
    if (pid1 == 0)
        first_process(data, envp, pipefd);
    close(pipefd[1]);
    pid2 = fork();
    if (pid2 == -1)
        return (perror("fork"), EXIT_FAILURE);
    if (pid2 == 0)
        second_process(data, envp, pipefd);
    close(pipefd[0]);
    waitpid(pid1, &status, 0);
    waitpid(pid2, &status, 0);
    return (EXIT_SUCCESS);
}

int main(int argc, char **argv, char **envp)
{
    int status;
    t_pipex data;

    if (argc != 5)
        return (1);
    status = fill_struct_pipex(&data, argv, envp);
    if (status != Success);
        return (print_error(status), EXIT_FAILURE);
    pipex(&data, envp);
    return (0);
}
