/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   research_new_notion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acocoual <acocoual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 02:31:12 by acocoual          #+#    #+#             */
/*   Updated: 2025/10/22 02:56:47 by acocoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// perror : void perror(const char *s)
// La fonction perror() affiche un message sur la sortie d'erreur standard,
// décrivant la dernière erreur rencontrée durant un appel système ou une fonction de bibliothèque.
// D'abord, (si s n'est pas NULL et si *s n'est pas un octet nul),
// la chaîne de caractère s est imprimée, suivie d'un deux points (« : ») ou d'un blanc,
// puis le message, suivi d'un saut de ligne. 

// strerror : char *strerror(int errnum)
// La fonction strerror() renvoie une chaîne décrivant le code d'erreur passé en argument errnum,
// en utilisant éventuellement la catégorie LC_MESSAGES de la localisation pour sélectionner la langue appropriée. 
// Cette chaîne ne doit pas être modifiée par l'application,
// mais peut être écrasée par un appel ultérieur à perror(3) ou strerror().
//  Aucune autre fonction de bibliothèque ne modifie cette chaîne.

// access : int access(const char *pathname, int mode)
// access() vérifie si le processus appelant peut accéder au fichier pathname.
// Si pathname est un lien symbolique, il est déréférencé. 
// Le mode indique la (les) vérification(s) d'accessibilité à effectuer
// et est soit la valeur F_OK, soit un masque constitué par un OU binaire « | »
// entre les valeurs R_OK, W_OK et X_OK. F_OK R_OK, W_OK et X_OK 
// servent à tester respectivement, si le fichier existe, la lecture,
// l'écriture et l'exécution du fichier.
// lien possible avec open 

// dup : int dup(int oldfd)
// dup2 : int dup2(int oldfd, int newfd)
// dup() et dup2() créent une copie du descripteur de fichier oldfd.
// dup() utilise le plus petit numéro inutilisé pour le nouveau descripteur.
// dup2() transforme newfd en une copie de oldfd, fermant auparavant newfd si besoin est
// pour dup 2 : 
// - Si oldfd n'est pas un descripteur de fichier valide, l'appel échoue et newfd n'est pas fermé. 
// - Si oldfd est un descripteur de fichier valide et si newfd a la même valeur que oldfd, dup2() ne fait rien et renvoie newfd. 
// Après un appel réussi à dup() ou dup2(), l'ancien et le nouveau descripteurs peuvent être utilisés de manière interchangeable. 
//  Ils font référence à la même description de fichier ouvert (voir open(2)) et ainsi partagent les pointeurs de position et les attributs.
// Par exemple, si le pointeur de position est modifié en utilisant lseek (2) sur l'un des descripteurs, la position est également changée pour l'autre. 

// execve : int execve(const char *fichier, char *const argv[], char *const envp[])
// execve() exécute le programme correspondant au fichier. 
// Celui-ci doit être un exécutable binaire ou bien un script commençant par une ligne du type : 
// revoir pqs compris

// exit : void exit(int status)
// La fonction exit() termine normalement le processus 
// et la valeur status & 0377 est renvoyée au processus parent.

// fork : pid_t fork(void)
// fork() crée un nouveau processus en dupliquant le processus appelant. 
// Le nouveau processus, que l'on appelle processus fils,
// est la copie exacte du processus appelant, que l'on appelle processus père ou parent,
// avec les exceptions suivantes : 
// revoir man 
// important : a son propre PID 

// pipe : int pipe(int pipefd[2])
// pipe() crée un tube, un canal unidirectionnel de données qui peut être utilisé pour la communication entre processus. 
// Le tableau pipefd est utilisé pour renvoyé deux descripteurs de fichier faisant référence aux extrémités du tube.
// pipefd[0] fait référence à l'extrémité de lecture du tube. pipefd[1] fait référence à l'extrémité d'écriture du tube. 
// Les données écrites sur l'extrémité d'écriture du tube sont mises en mémoire tampon
// par le noyau jusqu'à ce qu'elles soient lues sur l'extrémité de lecture du tube. 

// unlink : int unlink(const char *pathname)
// unlink() détruit un nom dans le système de fichiers.
// Si ce nom était le dernier lien sur un fichier, et si aucun processus n'a ouvert ce fichier, ce dernier est effacé,
// et l'espace qu'il utilisait est rendu disponible. 
// Si le nom était le dernier lien sur un fichier, mais qu'un processus conserve encore le fichier ouvert,
// celui-ci continue d'exister jusqu'à ce que le dernier descripteur le référençant soit fermé. 
// Si le nom correspond à un lien symbolique, le lien est supprimé. 
// Si le nom correspond à une socket, une FIFO, ou un périphérique, le nom est supprimé 
// mais les processus qui ont ouvert l'objet peuvent continuer à l'utiliser.

// wait : pid_t wait(int *status)
// waitpid :  pid_t waitpid(pid_t pid, int *status, int options)
// Tous ces appels système sont utilisés pour attendre le changement d'état du fils d'un processus appelant,
// et pour obtenir des informations sur le fils dont l'état a changé. 
// Un changement d'état peut être : le fils est terminé ;
// le fils a été interrompu par un signal ; ou le fils a été relancé par un signal.
// Dans le cas de la fin d'un processus, la réalisation d'un wait() permet au système de libérer les ressources associées au fils ;
// si un wait() n'est pas effectué, le fils qui s'est terminé reste dans l'état de « zombie »
// Si le fils a déjà changé d'état, ces appels reviennent immédiatement.
// Autrement, ils bloquent jusqu'à ce que soit un fils change d'état, soit un gestionnaire de signaux interrompe l'appel