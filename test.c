/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amandine <amandine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 02:37:36 by amandine          #+#    #+#             */
/*   Updated: 2025/11/28 12:51:53 by amandine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// pipe(int pipefd[2]) crée un tube anonyme : 
// pipefd[0] sert à lire, pipefd[1] à écrire. 
// Tant que le descripteur d’écriture reste ouvert, 
// les données écrites sont mises en tampon noyau et peuvent être lues depuis l’autre extrémité. 
// On ferme les extrémités inutiles dans chaque processus pour éviter les blocages.
// Exemple : le parent écrit un message, le fils le lit.
void pipe_exemple()
{
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

// fil1 existe = access(fil1, F_OK | R_OK);
// fil2 existe ou creer = access(fil2, F_OK);
// is OK = access(fl2, W_OK);
// is not ok = create fil2 et access(fil2, F_OK | W_OK);

// dup file1 pour executer la cmd1 sur le dup
// Si execve réussit, le processus se termine
// free(cmd) // si execve échoue, on libère la mémoire et on essaie un autre chemin
// } return (EXIT_FAILURE);
