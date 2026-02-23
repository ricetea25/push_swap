/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteoh <rteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:25:19 by rteoh             #+#    #+#             */
/*   Updated: 2024/03/06 17:25:19 by rteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//get the siz of stack
int	get_stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	if (!stack)
		return (0);
	while (stack != NULL)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	free_stack(t_stack **s)
{
	t_stack	*tmp;

	if (!s || !(*s))
		return ;
	while (*s)
	{
		tmp = (*s)->next;
		free(*s);
		*s = tmp;
	}
	*s = NULL;
}

void	exit_error(t_stack **stack_a, t_stack **stack_b)
{
	free_stack(stack_a);
	free_stack(stack_b);
	write(2, "Error\n", 6);
	exit (1);
}

void	free_arr(char **av)
{
	int	i;

	i = -1;
	if (!av)
		return ;
	while (av[++i])
		free (av[i]);
	free(av);
}
