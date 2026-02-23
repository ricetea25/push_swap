/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteoh <rteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:28:46 by rteoh             #+#    #+#             */
/*   Updated: 2024/03/01 16:28:46 by rteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// if lesser than 3 we just swap both value
// if 3 we just hardcode the solution
// if more than 3 we do our greedy algorithm, we calculate the cost of moving each node to the top of stack a and stack b, then we move the one with the least cost, we repeat this until stack b is empty, then we do some final rotations to make sure stack a is sorted
static void	push_swap(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	if (stack_size == 2 && is_sorted(*stack_a))
		do_sa(stack_a);
	else if (stack_size == 3)
		tiny_sort(stack_a);
	else if (stack_size > 3 && is_sorted(*stack_a))
		sort(stack_a, stack_b);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_size;

	stack_b = NULL;
	if (ac < 2)
		return (0);
	if ((av[1] == NULL) || av[1][0] == '\0')
		exit_error(NULL, NULL);
	if (ac == 2)
		av = make_input(av);
	if (is_correct_input(av) == -1)
		exit_error(NULL, NULL);
	stack_a = fill_stack_values(ac, av);
	stack_size = get_stack_size(stack_a);
	assign_index(stack_a, stack_size);
	push_swap(&stack_a, &stack_b, stack_size);
	free_stack(&stack_a);
	return (0);
}
