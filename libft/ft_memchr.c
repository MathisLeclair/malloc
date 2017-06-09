/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleclair <mleclair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 17:46:30 by mleclair          #+#    #+#             */
/*   Updated: 2016/11/05 18:21:31 by mleclair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*g_truc;

	g_truc = (unsigned char *)s;
	i = 0;
	while (n--)
	{
		if (g_truc[i] == (unsigned char)c)
			return (&g_truc[i]);
		i++;
	}
	return (NULL);
}
