/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleclair <mleclair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 17:08:30 by mleclair          #+#    #+#             */
/*   Updated: 2018/02/14 16:05:33 by mleclair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_struc *g_truc = NULL;

void	init(void)
{
	if (g_truc == NULL)
	{
		g_truc = mmap(NULL, sizeof(t_struc) + TNY * 100 + SML
		* 100 + sizeof(t_link) * 200, PRT, MAP, -1, 0);
		g_truc->large = (t_link *)(g_truc + 1);
		g_truc->tiny_max = TNY * 100;
		g_truc->small_max = SML * 100;
		g_truc->tiny = g_truc->large + 1;
		g_truc->tiny->next = NULL;
		g_truc->tiny->end = g_truc->tiny + 1;
		g_truc->small = (t_link *)((char *)g_truc->tiny + TNY * 101 +
		sizeof(t_link) * 100);
		g_truc->small->next = NULL;
		g_truc->small->end = g_truc->small + 1;
		g_truc->tinycurr = 0;
		g_truc->smallcurr = 0;
		g_truc->large->next = NULL;
	}
}
