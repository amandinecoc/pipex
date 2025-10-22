/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amandine <amandine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 21:05:08 by amandine          #+#    #+#             */
/*   Updated: 2025/09/24 00:53:12 by amandine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static int	lenword(char *str, int i, char sep)
{
	int	len;

	len = 0;
	while (str[i] != sep && str[i] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}

int	count_words(char const *s, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && s[i] != '\0')
		{
			word++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		if (s[i] == c && s[i] != '\0')
		{
			while (s[i] == c && s[i] != '\0')
				i++;
		}
	}
	return (word);
}

char	**malloc_tab_remplir(char const *s, char **tab, int word, char c)
{
	int	i;
	int	j;
	int	k;

	j = 0;
	i = 0;
	while (s[i] != '\0' && j < word)
	{
		k = 0;
		while (s[i] == c && s[i] != '\0')
			i++;
		tab[j] = malloc(sizeof(char) * lenword((char *)s, i, c) + 1);
		if (!tab[j])
			return (ft_free_tab(tab));
		while (s[i] != c && s[i] != '\0')
		{
			tab[j][k] = s[i];
			k++;
			i++;
		}
		tab[j][k] = '\0';
		j++;
	}
	tab[j] = NULL;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	int		word;
	char	**tab;

	word = count_words(s, c);
	if (!s || s[0] == '\0')
	{
		tab = malloc(sizeof(char *) * 1);
		if (!tab)
			return (NULL);
		tab[0] = NULL;
		return (tab);
	}
	tab = malloc(sizeof(char *) * (word + 1));
	if (!tab)
		return (NULL);
	tab = malloc_tab_remplir(s, tab, word, c);
	return (tab);
}
