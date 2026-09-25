/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsimsek <ahsimsek@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 05:55:20 by ahsimsek          #+#    #+#             */
/*   Updated: 2026/09/12 02:43:32 by ahsimsek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = stack_last(*stack);
	*stack = first->next;
	first->next = NULL;
	last->next = first;
}

void	ra(t_stack **a, t_bench *bench)
{
	rotate(a);
	ft_putstr_fd("ra\n", 1);
	if (bench)
	{
		bench->counts[OP_RA]++;
		bench->total++;
	}
}

void	rb(t_stack **b, t_bench *bench)
{
	rotate(b);
	ft_putstr_fd("rb\n", 1);
	if (bench)
	{
		bench->counts[OP_RB]++;
		bench->total++;
	}
}

void	rr(t_stack **a, t_stack **b, t_bench *bench)
{
	rotate(a);
	rotate(b);
	ft_putstr_fd("rr\n", 1);
	if (bench)
	{
		bench->counts[OP_RR]++;
		bench->total++;
	}
}
