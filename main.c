/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oruban <oruban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 15:29:53 by oruban            #+#    #+#             */
/*   Updated: 2024/05/15 17:33:17 by oruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int argc, char **argv, char **envp)
{
	if (argv && argc != 1)
	{
		ft_printf("Usage: minishell\n", 2);
		return (EXIT_FAILURE);
	}
	return(minishell(ini_minienv(envp)));

}

int minishell(t_env *minienv)
{
	int exit_status;
	
	exit_status = EXIT_SUCCESS;
	return (exit_status);
}