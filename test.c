/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amandine <amandine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 02:37:36 by amandine          #+#    #+#             */
/*   Updated: 2025/11/24 02:37:41 by amandine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

access(path[i] + cmd1, X_OK)
// fullcmd
"ls -l -k -m -b"
execve(fullcmd, tab cmd, envp)

fork

pipe

close

dup2

// ex : cmd1 = ls -l -a
tab 0 ls
tab 1 -l
tab 2 -a
tab 3 NULL

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