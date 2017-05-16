/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 14:39:38 by adaly             #+#    #+#             */
/*   Updated: 2017/05/15 16:31:41 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_unplace(int piece, int **draft, int **array)
{
	int index;

	index = 0;
	while (index < 4)
	{
		draft[index][0] = 0;
		++index;
	}
	array[2][piece] = 0;
}

void	ft_place(int piece, int **draft, int **array)
{
	int index;

	index = 0;
	while (index < 4)
	{
		draft[index][0] = piece + 1;
		++index;
	}
	array[2][piece] = 1;
}

int		ft_validate(int **draft)
{
	int index;

	index = 0;
	if (draft)
	{
		while (index < 4)
		{
			if (draft[index])
			{
				if (draft[index][0] != 0)
				{
					return (0);
				}
			}
			else
				return (0);
			++index;
		}
	}
	return (1);
}
