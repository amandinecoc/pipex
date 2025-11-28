/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amandine <amandine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 02:33:24 by amandine          #+#    #+#             */
/*   Updated: 2025/11/28 15:42:08 by amandine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// // dup fil1 !!!
// int process_child1(int f1, t_pipex *data, char **envp)
// {
//     execve(data->cmd1, data->tab_cmd1, envp);
//     if (execve(data->cmd1, data->tab_cmd1, envp) == -1)
//         perror("execve");
//     return(Success);
// }

// int process_child2(int f2, t_pipex *data, char **envp)
// {

// }

// int execute_fonction(int f1, int f2, t_pipex *data, char **envp)
// {
//     int   end[2];
//     int   status;
//     pid_t child1;
//     pid_t child2;
//     pid_t parent;

//     pipe(end);
//     child1 = fork();
//     if (child1 < 0)
//          return (perror("Fork: "), fork_failure);
//     else if (child1 == 0)
//         process_child1(f1, data, envp);
//     else
//     {
//         int status;
//         if (waitpid(child1, &status, 0) == -1)
//             perror("waitpid");
//     }
//     child2 = fork();
//     if (child2 < 0)
//          return (perror("Fork: "), fork_failure);
//     if (child2 == 0)
//         process_child2(f2, data, envp);
//     // parent = fork();
//     // if (parent < 0)
//     //      return (perror("Fork: "), fork_failure);
//     // if (!parent)
//     //     child_process(f1, data->cmd1);
//     // else
//     //     parent_process(f2, data->cmd2);
//     close(end[0]);
//     close(end[1]);
//     waitpid(child1, &status, 0);
//     waitpid(child2, &status, 0);
//     // if (wait(&status) == -1)
//     //     return (perror("wait"), EXIT_FAILURE);
// }

// int open_file(t_pipex *data, char **envp, int *f1, int *f2)
// {
//     if (f1 == -1)
//     {
//         perror("open");
//         exit(open_failure);
//     }
//     if (dup2(f1, STDOUT_FILENO) == -1)
//     {
//         perror("dup2");
//         exit(dup_failure);
//     }
//     if (f2 == -1)
//     {
//         perror("open");
//         exit(open_failure);
//     }
//     return (Success);
// }

// int pipex(t_pipex *data, char *envp)
// {
//     int f1;
//     int f2;

//     f1 = open(data->file1, O_RDONLY);
//     f2 = open(data->file2, O_CREAT | O_RDWR | O_TRUNC, 0644);
//     if (open_file(data, envp, &f1, &f2) != Success)
//         return (open_failure);
//     if(execute_fonction(f1, f2, data, envp) != Success)
//         return (fork_failure);
//     return (Success);
// }

// void	pipex(t_pipex *data, char **envp)
// {
// 	int fd1;
// 	int end[2];
// 	int status;
// 	pid_t pid1;

//     pipe(end);
// 	fd1 = open(data->file1, O_RDONLY);
// 	if (fd1 == -1)
// 	{
// 		perror("open");
// 		return ;
// 	}
//     pid1 = fork();
//     if (pid1 < 0)
//          return (perror("Fork: "), fork_failure);
//     else if (pid1 == 0)
//     {
//         execve(data->cmd1, data->tab_cmd1, envp);
//         perror("execve");
//     }
//     else
//     {
//         if (waitpid(pid1, &status, 0) == -1)
//             perror("waitpid");
//     }
//     close(fd1);
// }

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
