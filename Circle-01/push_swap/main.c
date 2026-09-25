/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsimsek <ahsimsek@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 04:37:50 by ahsimsek          #+#    #+#             */
/*   Updated: 2026/09/12 01:30:00 by ahsimsek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_structures(t_flags *flags, t_bench *bench)
{
	ft_bzero(flags, sizeof(t_flags));
	ft_bzero(bench, sizeof(t_bench));
	flags->strategy = STRAT_ADAPTIVE;
	bench->strategy_name = "Adaptive";
	bench->complexity = "O(n log n)";
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_flags	flags;
	t_bench	bench;

	if (argc < 2)
		return (0);
	a = NULL;
	b = NULL;
	init_structures(&flags, &bench);
	if (!parse_args(&a, argv, &flags))
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	if (!a)
		return (0);
	bench.enabled = flags.bench;
	assign_index(a);
	bench.disorder = compute_disorder(a);
	sort_stack(&a, &b, &flags, &bench);
	if (flags.bench)
		print_benchmark(&bench);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
