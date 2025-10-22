/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acocoual <acocoual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 20:24:53 by amandine          #+#    #+#             */
/*   Updated: 2025/06/17 21:32:39 by acocoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*tmp_s;

	tmp_s = (char *)s;
	while (n > 0)
	{
		*tmp_s = (char)c;
		tmp_s++;
		n--;
	}
	return (s);
}

// int main(int argc, char *argv)
// {
//     if (argc != 3)
//         return(1);
//     ft_memset(argv[1], argv[2], argv[3]);
//     return(0);
// }
