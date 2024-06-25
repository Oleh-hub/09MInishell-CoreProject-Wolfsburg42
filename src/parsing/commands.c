/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oruban <oruban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 18:41:40 by beredzhe          #+#    #+#             */
/*   Updated: 2024/06/25 19:47:57 by oruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_envir	*find_envir_variable(t_data *data, char *var_name, int len)
{
	t_envir	*current;

	current = data->env_list;
	while (current)
	{
		if (ft_strncmp(current->var_name, var_name, len) == 0)
			return (current);
		current = current->next;
	}
	return (NULL);
}
