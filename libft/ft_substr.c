/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acocoual <acocoual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 21:05:22 by amandine          #+#    #+#             */
/*   Updated: 2025/06/17 21:33:48 by acocoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*handle_start_over_size_exception(void)
{
	char	*newstr;

	newstr = malloc(sizeof(char) * 1);
	if (!newstr)
		return (NULL);
	newstr[0] = '\0';
	return (newstr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*newstr;
	size_t	i;
	size_t	size;

	i = 0;
	if (start >= ft_strlen(s))
		return (handle_start_over_size_exception());
	if (len > ft_strlen(&s[start]))
		size = ft_strlen(&s[start]);
	else
		size = len;
	newstr = malloc(sizeof(char) * size + 1);
	if (!newstr)
		return (NULL);
	while (len > i && s[start] != '\0')
	{
		newstr[i] = s[start];
		i++;
		start++;
	}
	newstr[i] = '\0';
	return (newstr);
}
