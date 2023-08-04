/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cogata <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 11:20:02 by cogata            #+#    #+#             */
/*   Updated: 2023/07/29 11:20:03 by cogata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = malloc(1 * sizeof(t_list));
	if (new_node == NULL)
	{
		return (NULL);
	}
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

/* #include <stdio.h>
int	main(void)
{
    t_list *tester;
	char	*s;

    s = "abc";
    tester = ft_lstnew(s);
    printf("content: %s\n", (char *) tester->content);
    printf("content address: %p\n", tester->content);
    printf("next address: %p\n", tester->next);
}
 */