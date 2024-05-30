/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 11:36:01 by beredzhe          #+#    #+#             */
/*   Updated: 2024/05/30 09:29:44 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_data(t_data **data, char **envp)
{
	(void)envp;
	*data = malloc(sizeof(t_data));
	if (!*data)
		exit(EXIT_FAILURE);
	(*data)->input_line = NULL;
	(*data)->root_directory = NULL;
	(*data)->input_minishell = "minishell>> ";
}