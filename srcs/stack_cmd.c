/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantini <jsantini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 15:09:04 by jsantini          #+#    #+#             */
/*   Updated: 2026/01/13 19:21:59 by jsantini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*pop_item(t_list **head)
{
	t_list	*item;

	if (!head || !(*head))
		return (NULL);
	item = *head;
	*head = (*head)->next;
	item->next = NULL;
	return (item);
}

void	*push_list(t_list **head, t_list *new)
{
	if (!new)
		return (NULL);
	if (!*head)
	{
		*head = new;
		return (new);
	}
	new->next = *head;
	*head = new;
	return (new);
}

void	aff_lst(t_list *head)
{
	while (head)
	{
		ft_printf("%p --> |%d| price: %d || target: %p --> |%d|\n", head, head->value, head->price, head->target, head->target->value);
		head = head->next;
	}
	return ;
}

t_list	*get_min(t_list *head)
{
	t_list	*min;

	min = head;
	while (head)
	{
		if (head->value <= min->value)
			min = head;
		head = head->next;
	}
	return (min);
}

void	get_target(t_list *head)
{
	t_list	*cycle;
	t_list	*target;
	t_list	*ori;

	cycle = head;
	ori = head;
	while (cycle)
	{
		target = NULL;
		head = ori;
		while (head)
		{
			if (head->value > cycle->value)
				if (!target || head->value < target->value)
					target = head;
			head = head->next;
		}
		if (target)
			cycle->target = target;
		else
			cycle->target = get_min(ori);
		cycle = cycle->next;
	}
	return ;
}

void	get_price(t_list *head)
{
	int	size_l;
	int	i;

	size_l = ft_lstsize(head);
	i = 1;
	while (head)
	{
		if (i >= (size_l / 2) + 1)
			head->price = (size_l - i + 1);
		else
			head->price = i;
		head->place = i - 1;
		head->size = size_l;
		i++;
		head = head->next;
	}
}
