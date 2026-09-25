/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_dispatcher.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsimsek <ahsimsek@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 18:15:20 by ahsimsek          #+#    #+#             */
/*   Updated: 2026/09/12 02:43:58 by ahsimsek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	apply_forced_strategy(t_stack **a, t_stack **b, t_flags *flags,
		t_bench *bench)
{
	if (flags->strategy == STRAT_SIMPLE)
	{
		bench->strategy_name = "Simple Sort";
		bench->complexity = "O(n^2)";
		simple_sort(a, b, bench);
	}
	else if (flags->strategy == STRAT_MEDIUM)
	{
		bench->strategy_name = "Medium Sort (Chunk / Butterfly)";
		bench->complexity = "O(n*sqrt(n))";
		medium_sort(a, b, bench);
	}
	else if (flags->strategy == STRAT_COMPLEX)
	{
		bench->strategy_name = "Complex Sort (Bitwise Radix)";
		bench->complexity = "O(n log n)";
		radix_sort(a, b, bench);
	}
}

static void	apply_adaptive(t_stack **a, t_stack **b, t_bench *bench)
{
	int	size;

	size = stack_size(*a);
	if (size <= 5)
	{
		bench->strategy_name = "Adaptive -> Small Sort";
		bench->complexity = "O(1)";
		sort_five(a, b, bench);
		return ;
	}
	if (bench->disorder < 0.2)
	{
		bench->strategy_name = "Adaptive -> Simple Sort";
		bench->complexity = "O(n^2)";
		simple_sort(a, b, bench);
	}
	else if (bench->disorder < 0.5)
	{
		bench->strategy_name = "Adaptive -> Medium Sort";
		bench->complexity = "O(n*sqrt(n))";
		medium_sort(a, b, bench);
	}
	else
	{
		bench->strategy_name = "Adaptive -> Complex Sort";
		bench->complexity = "O(n log n)";
		radix_sort(a, b, bench);
	}
}

void	sort_stack(t_stack **a, t_stack **b, t_flags *flags, t_bench *bench)
{
	int	size;

	if (!a || !*a || is_sorted(*a))
		return ;
	size = stack_size(*a);
	if (size == 2)
	{
		bench->strategy_name = "Small Sort";
		bench->complexity = "O(1)";
		if ((*a)->value > (*a)->next->value)
			sa(a, bench);
		return ;
	}
	if (size == 3)
	{
		bench->strategy_name = "Small Sort";
		bench->complexity = "O(1)";
		sort_three(a, bench);
		return ;
	}
	if (flags->strategy != STRAT_ADAPTIVE)
		apply_forced_strategy(a, b, flags, bench);
	else
		apply_adaptive(a, b, bench);
}
