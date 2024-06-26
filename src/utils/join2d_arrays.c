/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join2d_arrays.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 11:42:29 by beredzhe          #+#    #+#             */
/*   Updated: 2024/06/25 11:43:01 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**initialize_result(char **str1, char **str2)
{
	char	**result;

	if (!str1)
	{
		result = dup_2darray(str2);
		free_2darray(str2);
		return (result);
	}
	return (NULL);
}

static char	**allocate_result(char **str1, char **str2)
{
	int	len1;
	int	len2;

	len1 = len_2darray(str1);
	len2 = len_2darray(str2);
	return ((char **)malloc((len1 + len2 + 1) * sizeof(char *)));
}

static char	**copy_array(char **src, char **dest, int *i)
{
	while (*src)
	{
		dest[*i] = ft_strdup(*src);
		if (!dest[*i])
		{
			free_2darray(dest);
			return (NULL);
		}
		(*i)++;
		src++;
	}
	return (dest);
}

char	**join2darrays(char **str1, char **str2)
{
	char	**result;
	int		i;

	i = 0;
	result = initialize_result(str1, str2);
	if (result)
		return (result);
	result = allocate_result(str1, str2);
	if (!result)
		return (NULL);
	result = copy_array(str1, result, &i);
	if (!result)
		return (NULL);
	result = copy_array(str2, result, &i);
	if (!result)
		return (NULL);
	result[i] = (NULL);
	free_2darray(str1);
	free_2darray(str2);
	return (result);
}
