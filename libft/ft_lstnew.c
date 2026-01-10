/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 09:27:51 by jsantini          #+#    #+#             */
/*   Updated: 2026/01/09 15:58:22 by jsantini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(int content)
{
	t_list	*final;

	final = malloc(sizeof(t_list));
	if (!final)
		return (NULL);
	final->next = NULL;
	final->value = content;
	final->target = final;
	final->price = -1;
	return (final);
}
