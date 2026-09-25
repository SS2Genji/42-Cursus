/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsimsek <ahsimsek@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 17:55:40 by ahsimsek          #+#    #+#             */
/*   Updated: 2026/09/12 02:43:52 by ahsimsek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **a, t_bench *bench)
{
	int	first;
	int	second;
	int	third;

	if (!a || !*a || !(*a)->next || !(*a)->next->next)
		return ;
	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first > second && second < third && first < third)
		sa(a, bench);
	else if (first > second && second > third)
	{
		sa(a, bench);
		rra(a, bench);
	}
	else if (first > second && second < third && first > third)
		ra(a, bench);
	else if (first < second && second > third && first < third)
	{
		sa(a, bench);
		ra(a, bench);
	}
	else if (first < second && second > third && first > third)
		rra(a, bench);
}

void	sort_five(t_stack **a, t_stack **b, t_bench *bench)
{
	t_stack	*min_node;
	int		pos;
	int		size;

	while (stack_size(*a) > 3)
	{
		min_node = find_min_node(*a);
		pos = get_node_pos(*a, min_node);
		size = stack_size(*a);
		while (*a != min_node)
		{
			if (pos <= size / 2)
				ra(a, bench);
			else
				rra(a, bench);
		}
		pb(a, b, bench);
	}
	sort_three(a, bench);
	while (*b)
		pa(a, b, bench);
}
