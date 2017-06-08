/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleclair <mleclair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 13:45:06 by mleclair          #+#    #+#             */
/*   Updated: 2017/06/08 17:14:01 by mleclair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int		check_node(void *ptr, t_link *node)
{
	while (node->next)
	{
		if (ptr == node->next + 1)
		{
			truc->tinycurr -= (char *)node->next->end - (char *)node->next;
			node->next = node->next->next;
			return (1);
		}
		node = node->next;
	}
	return (0);
}

void	free(void *ptr)
{
	t_link *node;
	t_link *nxt;

	if (!ptr)
		return ;
	if (check_node(ptr, truc->tiny) == 1)
		return ;
	if (check_node(ptr, truc->small) == 1)
		return ;
	node = truc->large;
	while (node)
	{
		nxt = node->next;
		if (node + 1 == ptr)
		{
			munmap(node, (char *)node->next->end - (char *)node->next);
			node = nxt;
		}
		node = node->next;
	}
	return ;
}
