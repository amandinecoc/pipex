/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amandine <amandine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 02:37:36 by amandine          #+#    #+#             */
/*   Updated: 2025/11/28 11:48:28 by amandine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void reflexion()
{
    int fd = open("out.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd == -1) { perror("open"); exit(1); }
    if (dup2(fd, STDOUT_FILENO) == -1) { perror("dup2"); exit(1); }
    close(fd);
    printf("Cette ligne ira dans out.txt\n");
    pid_t pid = fork();
    if (pid == -1)
        perror("fork");
    else if (pid == 0)
    {
        char *argv[] = { "ls", "-l", NULL };
        char *envp[] = { NULL };
        execve("/bin/ls", argv, envp);
        if (execve("/bin/ls", argv, envp) == -1)
            perror("execve");
        _exit(EXIT_FAILURE);
    }
    else
    {
        int status;
        if (waitpid(pid, &status, 0) == -1)
            perror("waitpid");
    }
    int pipefd[2];
    if (pipe(pipefd) == -1)
        perror("pipe");
    else if (fork() == 0)
    {
        close(pipefd[1]);
        char buf[32];
        ssize_t n = read(pipefd[0], buf, sizeof(buf) - 1);
        if (n >= 0)
        {
            buf[n] = '\0';
            write(STDOUT_FILENO, buf, n);
        }
        _exit(0);
    }
    else
    {
        close(pipefd[0]);
        write(pipefd[1], "Hello via pipe\n", 15);
        close(pipefd[1]);
        wait(NULL);
    }
}

int main(void)
{
    FILE *f = fopen("data.txt", "r");
    if (!f)
    {
        perror("fopen");
        exit(EXIT_FAILURE);
    }
    puts("Lecture réussie");
    fclose(f);
    exit(EXIT_SUCCESS);
}

int main(void)
{
    int fd = open("temp.txt", O_CREAT | O_WRONLY, 0644);
    if (fd == -1)
        return perror("open"), 1;
    write(fd, "data\n", 5);
    close(fd);
    if (unlink("temp.txt") == -1)
        return perror("unlink"), 1;
    puts("temp.txt supprimé");
    return 0;
}

int main(void)
{
    pid_t pid = fork();
    if (pid == -1)
        return perror("fork"), EXIT_FAILURE;
    if (pid == 0)
        _exit(42);                      // fils se termine
    int status;
    if (wait(&status) == -1)
        return perror("wait"), EXIT_FAILURE;
    if (WIFEXITED(status))
        printf("fils terminé avec %d\n", WEXITSTATUS(status));
    return 0;
}

// fil1 existe = access(fil1, F_OK | R_OK);
// fil2 existe ou creer = access(fil2, F_OK);
// is OK = access(fl2, W_OK);
// is not ok = create fil2 et access(fil2, F_OK | W_OK);
// create variable PATH = PATH = (ft_strcmp("PATH =", **envp))
// suppr "PATH =" in PATH et split PATH :

// chercher cmd1[0] dans PATH 
// access(PATH[i] + cmd1[j], X_OK);

// dup file1 pour executer la cmd1 sur le dup
// execve(cmd, mycmdargs, envp); // Si execve réussit, le processus se termine
// // perror("Erreur"); <- ajouter perror pour le débogage
// free(cmd) // si execve échoue, on libère la mémoire et on essaie un autre chemin
// } return (EXIT_FAILURE);