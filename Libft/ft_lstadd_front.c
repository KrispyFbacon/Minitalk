/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 15:35:54 by frbranda          #+#    #+#             */
/*   Updated: 2024/05/13 15:30:26 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new != NULL || lst != NULL)
	{
		new -> next = *lst;
		*lst = new;
	}
}
/* 
int main(void)
{
	t_list *lst = NULL;
	t_list *node1 = ft_lstnew("Hello ");
	t_list *node2 = ft_lstnew("World ");
	
	ft_lstadd_front(&lst, node1);
	node1->next = node2;
	node2->next = node1; //NULL;
	while(lst)
	{
		printf("%s", (char *)lst->next->content);
		printf("%s", (char *)lst->next->next->content);
	}
	free(node1);
	free(node2);
} */