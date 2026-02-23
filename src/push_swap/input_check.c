/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteoh <rteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:48:44 by rteoh             #+#    #+#             */
/*   Updated: 2024/03/01 16:48:44 by rteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sign(char c)
{
	return (c >= '+' && c <= '-');
}

//check if its a number or just some random chars/signs
static int	arg_is_number(char *av)
{
	int	i;

	i = 0;
	if (is_sign(av[i]) && av[i + 1] != '\0')
		i++;
	while (av[i] && ft_isdigit(av[i]))
		i++;
	return (av[i] != '\0');
}

static int	arg_is_zero(char *av)
{
	int	i;

	i = 0;
	if (is_sign(av[i]))
		i++;
	while (av[i] && av[i] == '0')
		i++;
	return (av[i] == '\0');
}

static int	have_duplicates(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

//checks if input is valid, valid: 0 invalid: -1
//alo recording how many zeroes there are, important cause we can check if the stack is sorted later
int	is_correct_input(char **av)
{
	int			i;
	long int	nb;
	int			nb_zeros;

	nb_zeros = 0;
	i = 1;
	while (av[i])
	{
		if (arg_is_number(av[i]))
			return (-1);
		nb_zeros += arg_is_zero(av[i]);
		nb = ft_atol(av[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			return (-1);
		i++;
	}
	if (nb_zeros > 1 || have_duplicates(av))
		return (-1);
	return (0);
}
