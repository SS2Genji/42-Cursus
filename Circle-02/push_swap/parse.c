/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsimsek <ahsimsek@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 01:50:29 by ahsimsek          #+#    #+#             */
/*   Updated: 2026/09/12 01:30:00 by ahsimsek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_syntax(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

long	ft_atol(const char *nptr)
{
	int		sign;
	long	result;

	sign = 1;
	result = 0;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = result * 10 + (*nptr - '0');
		nptr++;
	}
	return (sign * result);
}

int	is_valid_nbr(char *str)
{
	long	num;

	if (!check_syntax(str))
		return (0);
	num = ft_atol(str);
	if (num > INT_MAX || num < INT_MIN)
		return (0);
	return (1);
}

static int	process_token(t_stack **a, char *token, t_flags *flags)
{
	long	num;
	t_stack	*node;

	if (token[0] == '-' && token[1] == '-')
	{
		if (ft_strncmp(token, "--simple", 9) == 0)
			flags->strategy = STRAT_SIMPLE;
		else if (ft_strncmp(token, "--medium", 9) == 0)
			flags->strategy = STRAT_MEDIUM;
		else if (ft_strncmp(token, "--complex", 10) == 0)
			flags->strategy = STRAT_COMPLEX;
		else if (ft_strncmp(token, "--adaptive", 11) == 0)
			flags->strategy = STRAT_ADAPTIVE;
		else if (ft_strncmp(token, "--bench", 8) == 0)
			flags->bench = 1;
		else
			return (0);
		return (1);
	}
	if (!is_valid_nbr(token))
		return (0);
	num = ft_atol(token);
	if (check_duplicate(*a, (int)num))
		return (0);
	node = stack_new((int)num);
	if (!node)
		return (0);
	stack_add_back(a, node);
	return (1);
}

int	parse_args(t_stack **a, char **argv, t_flags *flags)
{
	int		i;
	int		j;
	char	**args;

	i = 1;
	while (argv[i])
	{
		args = ft_split(argv[i], ' ');
		if (!args || !args[0])
		{
			if (args)
				free_matrix(args);
			free_stack(a);
			return (0);
		}
		j = 0;
		while (args[j])
		{
			if (!process_token(a, args[j], flags))
			{
				free_matrix(args);
				free_stack(a);
				return (0);
			}
			j++;
		}
		free_matrix(args);
		i++;
	}
	return (1);
}
