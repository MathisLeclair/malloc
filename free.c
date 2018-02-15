/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleclair <mleclair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 13:45:06 by mleclair          #+#    #+#             */
/*   Updated: 2018/02/15 11:31:21 by mleclair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int		check_node(void *ptr, t_link *nod)
{
	while (nod->next)
	{
		if (ptr == nod->next + 1)
		{
			if ((char *)nod->next->end - (char *)nod->next <= TNY)
				g_truc->tinycurr -= (char *)nod->next->end - (char *)nod->next;
			else
				g_truc->smallcurr -= (char *)nod->next->end - (char *)nod->next;
			nod->next = nod->next->next;
			return (1);
		}
		nod = nod->next;
	}
	return (0);
}

void	free(void *ptr)
{
	t_link *node;
	t_link *nxt;

	if (!ptr)
		return ;
	if (check_node(ptr, g_truc->tiny) == 1)
		return ;
	if (check_node(ptr, g_truc->small) == 1)
		return ;
	node = g_truc->large;
	while (node->next)
	{
		nxt = node->next->next;
		if (node->next + 1 == ptr)
		{
			munmap(node->next, (char *)node->next->end - (char *)node->next);
			node->next = nxt;
			break ;
		}
		node = node->next;
	}
	return ;
}
