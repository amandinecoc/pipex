/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acocoual <acocoual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 03:03:28 by acocoual          #+#    #+#             */
/*   Updated: 2025/12/01 17:36:33 by acocoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void first_process(t_pipex *data, char **envp, int *pipefd)
{
    int infile_fd;
    
    if (data->cmd1 == NULL)
        return(print_error(command_not_found), exit(EXIT_FAILURE));
    if (access(data->file1, R_OK) != 0)
        return(perror("access"), exit(EXIT_FAILURE));
    infile_fd = open(data->file1, O_RDONLY);
    if (infile_fd == -1)
        return (perror("open"), close(infile_fd), exit(EXIT_FAILURE));
    close(pipefd[0]);
    dup2(infile_fd, STDIN_FILENO);
    dup2(pipefd[1], STDOUT_FILENO);
    close(pipefd[1]);
    close(infile_fd);
    execve(data->cmd1, data->tab_cmd1, envp);
    perror("execve");
    return(exit(EXIT_FAILURE));
}

void second_process(t_pipex *data, char **envp, int *pipefd)
{
    int outfile_fd;
    
    if (data->cmd2 == NULL)
        return(print_error(command_not_found), exit(EXIT_FAILURE)); //command not found
    if (access(data->file2, F_OK) == 0 && access(data->file2, W_OK) != 0)
        return(perror("access"), exit(EXIT_FAILURE));
    outfile_fd = open(data->file2, O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (outfile_fd == -1)
        return (perror("open"), close(outfile_fd), exit(EXIT_FAILURE));
    dup2(pipefd[0], STDIN_FILENO);
    dup2(outfile_fd, STDOUT_FILENO);
    close(pipefd[0]);
    close(outfile_fd);
    execve(data->cmd2, data->tab_cmd2, envp);
    perror("execve");
    return(exit(EXIT_FAILURE));
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
        return (ft_putendl_fd("ERROR : invalid number of arguments", 2), EXIT_FAILURE);
    status = fill_struct_pipex(&data, argv, envp);
    if (status != Success)
        return (print_error(status), EXIT_FAILURE);
    pipex(&data, envp);
    free_pipex(&data);
    return (0);
}
