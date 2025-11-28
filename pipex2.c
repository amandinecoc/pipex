/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amandine <amandine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 02:33:24 by amandine          #+#    #+#             */
/*   Updated: 2025/11/28 12:52:40 by amandine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// dup fil1 !!!
int process_child1(int f1, t_pipex *data)
{
    char *argv[] = { "ls", "-l", NULL };
    char *envp[] = { NULL };
    execve(data->cmd1, data->tab_cmd1, envp);
    if (execve(data->cmd1, data->tab_cmd1, envp) == -1)
        perror("execve");
    return(Success);
}

int execute_fonction(int f1, int f2, t_pipex *data, char **envp)
{
    int   end[2];
    int   status;
    pid_t child1;
    pid_t child2;
    pid_t parent;
    
    child1 = fork();
    if (child1 < 0)
         return (perror("Fork: "), fork_failure);
    else if (child1 == 0)
        process_child1(f1, data->cmd1);
    else
    {
        int status;
        if (waitpid(child1, &status, 0) == -1)
            perror("waitpid");
    }
    child2 = fork();
    if (child2 < 0)
         return (perror("Fork: "), fork_failure);
    if (child2 == 0)
        process_child2(f2, data->cmd2);
    // parent = fork();
    // if (parent < 0)
    //      return (perror("Fork: "), fork_failure);
    // if (!parent)
    //     child_process(f1, data->cmd1);
    // else
    //     parent_process(f2, data->cmd2);
    close(end[0]);
    close(end[1]);
    waitpid(child1, &status, 0);
    waitpid(child2, &status, 0);
    // if (wait(&status) == -1)
    //     return perror("wait"), EXIT_FAILURE;
}

int open_file(t_pipex *data, char **envp, int *f1, int *f2)
{
    if (f1 == -1) 
    {
        perror("open"); 
        exit(open_failure); 
    }
    if (dup2(f1, STDOUT_FILENO) == -1) 
    { 
        perror("dup2"); 
        exit(dup_failure); 
    }
    if (f2 == -1) 
    {
        perror("open"); 
        exit(open_failure); 
    }
    // pipex(f1, f2, data, envp);
    return (0);
}

int pipex(t_pipex *data, char *envp)
{
    int f1;
    int f2;

    f1 = open(data->file1, O_RDONLY);
    f2 = open(data->file2, O_CREAT | O_RDWR | O_TRUNC, 0644);
    open_file(data, envp, &f1, &f2);
}
