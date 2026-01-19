/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 12:26:24 by jsantini          #+#    #+#             */
/*   Updated: 2026/01/18 19:59:42 by jsantini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pars(char **list)
{
	int	i;
	int	j;

	i = -1;
	if (!list)
		return (0);
	while (list[++i])
	{
		j = 0;
		if ((list[i][j] == '-' || list[i][j] == '+') && ft_isdigit(list[i][j + 1]) == 1)
			j++;
		else if ((ft_isdigit(list[i][j]) == 0))
			return (0);
		if (ft_strtol(list[i], NULL) == LONG_MAX || ft_strtol(list[i], NULL) == LONG_MIN)
			return (0);
		while (list[i][j])
			if (ft_isdigit(list[i][j++]) == 0 || ft_strlen(list[i]) > 11)
				return (0);
	}
	return (1);
}

int	check_double(t_list *head)
{
	t_list	*missile;

	while (head)
	{
		missile = head->next;
		while (missile)
		{
			if (missile->value == head->value)
				return (0);
			missile = missile->next;
		}
		head = head->next;
	}
	return (1);
}

t_list	*make_list_one(char **v)
{
	t_list	*final;
	int	i;

	final = NULL;
	if (!pars(v))
		return (ft_freeall(v));
	i = 0;
	while (v[i])
	{
		if (!final)
			final = ft_lstnew(ft_atoi(v[i]));
		else
			ft_lstadd_back(&final, ft_lstnew(ft_atoi(v[i])));
		i++;
	}
	ft_freeall(v);
	if (!check_double(final))
		return (ft_lstclear(&final, &free));
	return (final);
}

t_list	*make_list(char **v)
{
	t_list	*final;

	final = NULL;
	if (!pars(v))
		return (NULL);
	while (*v)
	{
		if (!final)
			final = ft_lstnew(ft_atoi(*v));
		else
			ft_lstadd_back(&final, ft_lstnew(ft_atoi(*v)));
		v++;
	}
	if (!check_double(final))
		return (ft_lstclear(&final, &free));
	return (final);
}

int	main(int i, char **v)
{
	if (i == 1)
		return (0);
	if (i == 2)
		algo(make_list_one(ft_split(v[1], ' ')));
	else
		algo(make_list(++v));
	return (0);
}
