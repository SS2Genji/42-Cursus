/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsimsek <ahsimsek@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 05:27:18 by ahsimsek          #+#    #+#             */
/*   Updated: 2026/09/12 01:30:00 by ahsimsek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **dest, t_stack **src)
{
	t_stack	*top_src;

	if (!src || !*src)
		return ;
	top_src = *src;
	*src = (*src)->next;
	top_src->next = *dest;
	*dest = top_src;
}

void	pa(t_stack **a, t_stack **b, t_bench *bench)
{
	push(a, b);
	ft_putstr_fd("pa\n", 1);
	if (bench)
	{
		bench->counts[OP_PA]++;
		bench->total++;
	}
}

void	pb(t_stack **a, t_stack **b, t_bench *bench)
{
	push(b, a);
	ft_putstr_fd("pb\n", 1);
	if (bench)
	{
		bench->counts[OP_PB]++;
		bench->total++;
	}
}
