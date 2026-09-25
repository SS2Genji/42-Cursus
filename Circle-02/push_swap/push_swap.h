/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsimsek <ahsimsek@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 01:43:33 by ahsimsek          #+#    #+#             */
/*   Updated: 2026/09/12 01:30:00 by ahsimsek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef enum e_op
{
	OP_SA = 0,
	OP_SB,
	OP_SS,
	OP_PA,
	OP_PB,
	OP_RA,
	OP_RB,
	OP_RR,
	OP_RRA,
	OP_RRB,
	OP_RRR,
	OP_TOTAL
}	t_op;

typedef enum e_strategy
{
	STRAT_ADAPTIVE = 0,
	STRAT_SIMPLE,
	STRAT_MEDIUM,
	STRAT_COMPLEX
}	t_strategy;

typedef struct s_flags
{
	t_strategy	strategy;
	int			bench;
}	t_flags;

typedef struct s_bench
{
	int			counts[11];
	int			total;
	int			enabled;
	const char	*strategy_name;
	const char	*complexity;
	double		disorder;
}	t_bench;

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

/* Parser & Validation */
int		check_syntax(char *str);
long	ft_atol(const char *nptr);
int		is_valid_nbr(char *str);
int		check_duplicate(t_stack *a, int n);
int		parse_args(t_stack **a, char **argv, t_flags *flags);

/* Stack Utilities */
t_stack	*stack_new(int value);
t_stack	*stack_last(t_stack *lst);
void	stack_add_back(t_stack **lst, t_stack *new_node);
int		stack_size(t_stack *lst);
void	free_stack(t_stack **stack);
void	free_matrix(char **str);

/* Operations */
void	sa(t_stack **a, t_bench *bench);
void	sb(t_stack **b, t_bench *bench);
void	ss(t_stack **a, t_stack **b, t_bench *bench);
void	pa(t_stack **a, t_stack **b, t_bench *bench);
void	pb(t_stack **a, t_stack **b, t_bench *bench);
void	ra(t_stack **a, t_bench *bench);
void	rb(t_stack **b, t_bench *bench);
void	rr(t_stack **a, t_stack **b, t_bench *bench);
void	rra(t_stack **a, t_bench *bench);
void	rrb(t_stack **b, t_bench *bench);
void	rrr(t_stack **a, t_stack **b, t_bench *bench);

/* Indexing & Disorder Metric */
void	assign_index(t_stack *a);
double	compute_disorder(t_stack *a);
int		is_sorted(t_stack *a);

/* Sort Utilities */
t_stack	*find_max_node(t_stack *stack);
t_stack	*find_min_node(t_stack *stack);
int		get_node_pos(t_stack *stack, t_stack *target);
int		get_max_bits(int max_val);
int		ft_isqrt(int n);

/* Sorting Strategies */
void	sort_three(t_stack **a, t_bench *bench);
void	sort_five(t_stack **a, t_stack **b, t_bench *bench);
void	simple_sort(t_stack **a, t_stack **b, t_bench *bench);
void	medium_sort(t_stack **a, t_stack **b, t_bench *bench);
void	radix_sort(t_stack **a, t_stack **b, t_bench *bench);
void	sort_stack(t_stack **a, t_stack **b, t_flags *flags, t_bench *bench);

/* Benchmark Output */
void	print_benchmark(t_bench *bench);

#endif
