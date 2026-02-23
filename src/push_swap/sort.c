/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteoh <rteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 19:08:32 by rteoh             #+#    #+#             */
/*   Updated: 2024/03/18 19:08:32 by rteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//we are pushing all the numbers except 3 to stack b not randomly but based on the index (if it smaller than stack size / 2 which means smaller gets pushed first )
static void	push_rest(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_size;
	int	pushed;
	int	i;

	stack_size = get_stack_size(*stack_a);
	pushed = 0;
	i = 0;
	while (stack_size > 6 && i < stack_size && pushed < stack_size / 2)
	{
		if ((*stack_a)->index <= stack_size / 2)
		{
			do_pb(stack_a, stack_b);
			pushed++;
		}
		else
			do_ra(stack_a);
		i++;
	}
	while (stack_size - pushed > 3)
	{
		do_pb(stack_a, stack_b);
		pushed++;
	}
}

//gets a sorted stack

static void	arrange_stack(t_stack **stack_a)
{
	int	lowest_idx_pos;
	int	stack_size;

	stack_size = get_stack_size(*stack_a);
	lowest_idx_pos = get_lowest_index_pos(stack_a);
	if (lowest_idx_pos > stack_size / 2)
	{
		while (lowest_idx_pos < stack_size)
		{
			do_rra(stack_a);
			lowest_idx_pos++;
		}
	}
	else
	{
		while (lowest_idx_pos > 0)
		{
			do_ra(stack_a);
			lowest_idx_pos--;
		}
	}
}

// push first sort 3
// then we keep calculating the cost of moving each node to the top of stack a and stack b, then we move the one with the least cost, we repeat this until stack b is empty, 
// then we do some final rotations to make sure stack a is sorted

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	push_rest(stack_a, stack_b);
	tiny_sort(stack_a);
	while (*stack_b)
	{
		get_target_position(stack_a, stack_b);
		calculate_cost(stack_a, stack_b);
		do_optimal_move(stack_a, stack_b);
	}
	if (is_sorted(*stack_a))
		arrange_stack(stack_a);
}
