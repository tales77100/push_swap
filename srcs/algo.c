/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 12:29:24 by jsantini          #+#    #+#             */
/*   Updated: 2026/01/13 19:51:47 by jsantini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	aff(t_list *a, t_list *b)
{
	ft_printf("----------a-----------\n");
	aff_lst(a);
	ft_printf("----------b-----------\n");
	aff_lst(b);

}

void	sort_three(t_list **h)
{
	int	top;
	int	mid;
	int	bas;

	top = (*h)->value;
	mid = (*h)->next->value;
	bas = (*h)->next->next->value;

	if (top > mid && top > bas)
		ra(h, 0);
	else if (mid > top && mid > bas)
		rra(h, 0);
	top = (*h)->value;
	mid = (*h)->next->value;
	if (top > mid)
		sa(h, 0);
	return ;
}

int	target_in_a(t_list *a, t_list *node)
{
	while (a)
	{
		if (a == node)
			return (1);
		a = a->next;
	}
	return (0);
}


t_list	*highest_in_stack(t_list *head)
{
	t_list	*temp;

	temp = head;
	while (head)
	{
		if (temp->value > head->value)
			temp = head;
		head = head->next;
	}
	return (temp);
}

void	sorting(t_list **a, t_list **b)
{
	t_list	*max;
	int	i;

	sort_three(a);
	get_price(*a);
	get_price(*b);
	//aff(*a, *b);
	while (ft_lstsize(*b) > 0)
	{
		max = highest_in_stack(*b);
		while (*b != max)
		{
			if (max->place > max->size / 2)
				rrb(b, 0);
			else
				rb(b, 0);
		}
		i = 0;
		pa(a, b);
		//aff(*a, *b);
		get_price(*b);
		get_price(*a);
	}
	return ;
}


void	smart_push(int size_l, t_list **a, t_list **b)
{
	t_list	*highest;

	while (size_l-- > 3)
	{
		highest = get_min(*a);
		if (highest->place >= highest->size / 2)
		{
			while (*a != highest)
				rra(a, 0);
		}
		else
		{
			while (*a != highest)
				ra(a, 0);
		}
		get_price(*a);
		pb(a, b);
		
	}
	return ;
}

void	algo(t_list *a)
{
	t_list *b[1];
	int	size_l;

	*b = NULL;
	get_target(a);
	size_l = ft_lstsize(a);
	if (size_l == 1)
		return ;
	if (size_l == 2 && a->value > a->next->value)
		return ((void)sa(&a, 0));
	else if (size_l == 2)
		return ;
	if (size_l == 3)
		return (sort_three(&a));
	smart_push(size_l, &a, b);
	sorting(&a, b);
	//aff(a, *b);
	ft_lstclear(&a, &free);
	return ;
}
