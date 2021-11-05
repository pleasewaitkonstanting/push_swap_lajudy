/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lajudy <lajudy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 20:06:31 by lajudy            #+#    #+#             */
/*   Updated: 2021/11/05 18:29:08 by lajudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_triple(t_stack_elem **head)
{
	int	size;
	int	first;
	int	second;
	int	third;

	size = stack_size(*head);
	if (size == 3)
	{
		first = (*head)->value;
		second = (*head)->next->value;
		third = (*head)->next->next->value;
		if (second > third && second > first && third > first)
			act_sa(head, 1);
		if (third > first && third > second && first > second)
			act_sa(head, 1);
		if (first > third && first > second && second > third)
			act_sa(head, 1);
	}
}

t_stack_elem	*fill_stack_b(t_stack_elem **head)
{
	t_stack_elem	*head_b;
	int				min;
	int				max;
	int				med;
	int				size;

	if (find_minmaxmed(head, &min, &max, &med) > 0)
		return (NULL);
	head_b = NULL;
	size = stack_size(*head);
	while (size > 3)
	{
		if ((*head)->value == min || (*head)->value == max
			|| (*head)->value == med)
			act_ra(head, 1);
		else
		{
			act_pb(head, &head_b, 1);
			size--;
		}
	}
	sort_triple(head);
	return (head_b);
}

t_stack_elem	*stack_sort(t_stack_elem **head)
{
	t_stack_elem	*head_b;

	if (is_not_sorted(*head))
	{
		head_b = fill_stack_b(head);
		while (head_b)
			transfer_to_a(head, &head_b);
	}
	final_sort_stack(head);
	return (NULL);
}