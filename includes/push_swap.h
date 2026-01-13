/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:37:50 by jsantini          #+#    #+#             */
/*   Updated: 2026/01/13 19:25:22 by jsantini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

void	algo(t_list *head);
void	aff_lst(t_list *head);
void	get_target(t_list *head);
void	get_price(t_list *head);
t_list	*get_min(t_list *head);

void	*push_list(t_list **head, t_list *new);

int		pb(t_list **a, t_list **b);
int		pa(t_list **a, t_list **b);

int		ra(t_list **a, int act);
int		rb(t_list **b, int act);
int		rr(t_list **a, t_list **b);

int		rra(t_list **a, int act);
int		rrb(t_list **b, int act);
int		rrr(t_list **a, t_list **b);

int		sa(t_list **a, int act);
int		sb(t_list **b, int act);
int		ss(t_list **a, t_list **b);

t_list	*pop_item(t_list **head);

#endif
