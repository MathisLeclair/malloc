/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleclair <mleclair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 16:07:01 by mleclair          #+#    #+#             */
/*   Updated: 2018/02/15 11:40:49 by mleclair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*saf_dst;
	unsigned char	*saf_src;

	saf_dst = (unsigned char*)dst;
	saf_src = (unsigned char*)src;
	i = 0;
	while (i < n)
	{
		saf_dst[i] = saf_src[i];
		i++;
	}
	return (dst);
}
