/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleclair <mleclair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 16:07:01 by mleclair          #+#    #+#             */
/*   Updated: 2017/06/08 17:14:28 by mleclair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*s1;

	s1 = dst;
	while (n != 0)
	{
		*s1 = *(unsigned char*)src;
		s1++;
		src++;
		n--;
	}
	return (dst);
}
