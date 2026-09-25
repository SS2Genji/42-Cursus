/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsimsek <ahsimsek@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 05:20:41 by ahsimsek          #+#    #+#             */
/*   Updated: 2026/09/12 02:44:20 by ahsimsek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	sa(t_stack **a, t_bench *bench)
{
	swap(a);
	ft_putstr_fd("sa\n", 1);
	if (bench)
	{
		bench->counts[OP_SA]++;
		bench->total++;
	}
}

void	sb(t_stack **b, t_bench *bench)
{
	swap(b);
	ft_putstr_fd("sb\n", 1);
	if (bench)
	{
		bench->counts[OP_SB]++;
		bench->total++;
	}
}

void	ss(t_stack **a, t_stack **b, t_bench *bench)
{
	swap(a);
	swap(b);
	ft_putstr_fd("ss\n", 1);
	if (bench)
	{
		bench->counts[OP_SS]++;
		bench->total++;
	}
}
