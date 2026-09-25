/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsimsek <ahsimsek@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 13:09:20 by ahsimsek          #+#    #+#             */
/*   Updated: 2026/09/12 01:30:00 by ahsimsek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_stack **a, t_stack **b, t_bench *bench)
{
	int	max_bits;
	int	i;
	int	j;
	int	size;

	if (!a || !*a || is_sorted(*a))
		return ;
	max_bits = get_max_bits(stack_size(*a) - 1);
	i = 0;
	while (i < max_bits)
	{
		size = stack_size(*a);
		j = 0;
		while (j < size)
		{
			if ((((*a)->index >> i) & 1) == 1)
				ra(a, bench);
			else
				pb(a, b, bench);
			j++;
		}
		while (*b)
			pa(a, b, bench);
		i++;
	}
}
