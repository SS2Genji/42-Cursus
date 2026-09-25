/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsimsek <ahsimsek@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 01:30:00 by ahsimsek          #+#    #+#             */
/*   Updated: 2026/09/12 02:40:31 by ahsimsek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_benchmark(t_bench *bench)
{
	int	int_part;
	int	dec_part;

	if (!bench || !bench->enabled)
		return ;
	int_part = (int)(bench->disorder * 100.0);
	dec_part = ((int)(bench->disorder * 10000.0 + 0.5)) % 100;
	if (dec_part < 10)
		ft_dprintf(2, "[bench] Disorder: %d.0%d%%\n", int_part, dec_part);
	else
		ft_dprintf(2, "[bench] Disorder: %d.%d%%\n", int_part, dec_part);
	ft_dprintf(2, "[bench] Strategy: %s (%s)\n",
		bench->strategy_name, bench->complexity);
	ft_dprintf(2, "[bench] Total operations: %d\n", bench->total);
	ft_dprintf(2, "[bench] sa: %d, sb: %d, ss: %d\n",
		bench->counts[OP_SA], bench->counts[OP_SB], bench->counts[OP_SS]);
	ft_dprintf(2, "[bench] pa: %d, pb: %d\n",
		bench->counts[OP_PA], bench->counts[OP_PB]);
	ft_dprintf(2, "[bench] ra: %d, rb: %d, rr: %d\n",
		bench->counts[OP_RA], bench->counts[OP_RB], bench->counts[OP_RR]);
	ft_dprintf(2, "[bench] rra: %d, rrb: %d, rrr: %d\n",
		bench->counts[OP_RRA], bench->counts[OP_RRB], bench->counts[OP_RRR]);
}
