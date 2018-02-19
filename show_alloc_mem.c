/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleclair <mleclair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 19:12:26 by mleclair          #+#    #+#             */
/*   Updated: 2018/02/19 13:29:10 by mleclair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	print_adress(long addr, int i)
{
	int u;

	if (i == 0)
		write(1, "0x", 2);
	if (addr >= 16)
		print_adress(addr / 16, 1);
	u = addr % 16;
	if (u >= 10)
		ft_putchar(u - 10 + 'a');
	else
		ft_putchar(u + '0');
}

int		print_block(t_link *node)
{
	int i;
	int total;

	total = 0;
	while (node->next != NULL)
	{
		node = node->next;
		print_adress((long)node + 1, 0);
		write(1, " - ", 3);
		print_adress((long)node->end, 0);
		i = (char *)node->end - (char *)node - sizeof(t_link);
		write(1, " : ", 3);
		ft_putnbr(i);
		ft_putstr(" octets\n");
		total += i;
	}
	return (total);
}

void	print_name(char *str, int i, t_link *node)
{
	write(1, str, i);
	print_adress((long)node, 0);
	ft_putchar('\n');
}

void	show_alloc_mem2(void)
{
	int total;

	if (!g_truc)
		return ;
	total = 0;
	print_name("TINY : ", 7, g_truc->tiny);
	total += print_block(g_truc->tiny);
	print_name("SMALL : ", 8, g_truc->small);
	total += print_block(g_truc->small);
	print_name("LARGE : ", 8, g_truc->large);
	total += print_block(g_truc->large);
	ft_putstr("Total : ");
	ft_putnbr(total);
	ft_putstr(" octets\n");
}

void	show_alloc_mem(void)
{
	pthread_mutex_t	lock;
	
	pthread_mutex_lock(&lock);
	show_alloc_mem2();
	pthread_mutex_unlock(&lock);
}
