/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsimsek <ahsimsek@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 13:27:45 by ahsimsek          #+#    #+#             */
/*   Updated: 2026/09/12 01:30:00 by ahsimsek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_chunk_size(int size)
{
	int	chunk;

	if (size <= 20)
		return (4);
	chunk = (ft_isqrt(size) * 145) / 100;
	if (chunk < 1)
		chunk = 1;
	return (chunk);
}

static void	push_chunks_to_b(t_stack **a, t_stack **b, int chunk,
		t_bench *bench)
{
	int	pushed;

	pushed = 0;
	while (*a)
	{
		if ((*a)->index <= pushed)
		{
			pb(a, b, bench);
			rb(b, bench);
			pushed++;
		}
		else if ((*a)->index <= pushed + chunk)
		{
			pb(a, b, bench);
			pushed++;
		}
		else
			ra(a, bench);
	}
}

static void	push_back_to_a(t_stack **a, t_stack **b, t_bench *bench)
{
	t_stack	*max_node;
	int		pos;
	int		size;

	while (*b)
	{
		max_node = find_max_node(*b);
		size = stack_size(*b);
		pos = get_node_pos(*b, max_node);
		while (*b != max_node)
		{
			if (pos <= size / 2)
				rb(b, bench);
			else
				rrb(b, bench);
		}
		pa(a, b, bench);
	}
}

void	medium_sort(t_stack **stack_a, t_stack **stack_b, t_bench *bench)
{
	int	chunk;

	chunk = get_chunk_size(stack_size(*stack_a));
	push_chunks_to_b(stack_a, stack_b, chunk, bench);
	push_back_to_a(stack_a, stack_b, bench);
}
