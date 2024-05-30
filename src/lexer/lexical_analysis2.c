/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexical_analysis2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:38:40 by beredzhe          #+#    #+#             */
/*   Updated: 2024/05/30 09:40:54 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	tokenise(t_data *data, char *str)
{
	int		i;
	t_token	**head;
	
	i = 0;
	head = &data->token_list;
	data->count = 0;
	while (str[i])
	{
		printf("Position: %d, Charachter: %c\n", i, str[i]);
		if (!find_token(data, str, &i, head))
			continue;
		data->count++;
		if (find_token2(i, str, "|") || find_token2(i, str, ">")
			|| find_token2(i, str, "<") || find_token2(i, str, "&"))
			add_token(head, create_token(data, i + 1));
		i++;
	}
	if (i > 0)
	{
		add_token(head, create_token(data, i));
		add_token(head, create_arg_token(data, "newline", T_NEWLINE));
		printf("data->count: %d\n", data->count);
	}
}
