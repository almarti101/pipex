/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpenultimate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarti3 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 19:45:03 by almarti3          #+#    #+#             */
/*   Updated: 2025/01/24 19:45:05 by almarti3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstpenultimate(t_list *lst)
{
	if (!lst || !lst->next)
		return (NULL);
	while (lst->next && lst->next->next)
		lst = lst->next;
	return (lst);
}

/*
int main()
{
	t_list *lst3 = malloc(sizeof(t_list));
	lst3->content = "SUCCEED";
	lst3->next = NULL;
	
	t_list *lst2 = malloc(sizeof(t_list));
	lst2->content = "RESIST";
	lst2->next = lst3;

	t_list *lst1 = malloc(sizeof(t_list));
	lst1->content = "SURRENDER";
	lst1->next = lst2;

	t_list *penultimate_node = ft_lstpenultimate(lst1);

	if (penultimate_node != NULL) {
        printf("El penúltimo nodo es: %s\n", (char*)penultimate_node->content);
    } else {
        printf("La lista está vacía.\n");
    }

	free(lst1);
    free(lst2);
    free(lst3);
	return (0);
}
*/
