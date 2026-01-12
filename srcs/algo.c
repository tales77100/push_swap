/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 12:29:24 by jsantini          #+#    #+#             */
/*   Updated: 2026/01/12 11:53:01 by jsantini         ###   ########.fr       */
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

void	sorting(t_list **a, t_list **b)
{
	sort_three(a);
	get_price(*a);
	get_price(*b);
	while (ft_lstsize(*b) > 0)
		pa(a, b);
	aff(*a, *b);
	return ;
}

void	smart_push(int size_l, t_list **a, t_list **b)
{
	while (size_l-- > 3)
	{
		pb(a, b);
		//if (*b && ) <-- suite de condition pcq je suis debile
	}
	return ;
}

void	algo(t_list *a)
{
	t_list *b[1];
	int	size_l;

	*b = NULL;
	get_target(a);
	get_price(a);
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
	ft_lstclear(&a, &free);
	return ;
}
