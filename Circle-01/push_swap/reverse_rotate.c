/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsimsek <ahsimsek@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 05:56:45 by ahsimsek          #+#    #+#             */
/*   Updated: 2026/09/12 01:30:00 by ahsimsek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*second_last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	last = *stack;
	second_last = NULL;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rra(t_stack **a, t_bench *bench)
{
	reverse_rotate(a);
	ft_putstr_fd("rra\n", 1);
	if (bench)
	{
		bench->counts[OP_RRA]++;
		bench->total++;
	}
}

void	rrb(t_stack **b, t_bench *bench)
{
	reverse_rotate(b);
	ft_putstr_fd("rrb\n", 1);
	if (bench)
	{
		bench->counts[OP_RRB]++;
		bench->total++;
	}
}

void	rrr(t_stack **a, t_stack **b, t_bench *bench)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_putstr_fd("rrr\n", 1);
	if (bench)
	{
		bench->counts[OP_RRR]++;
		bench->total++;
	}
}
