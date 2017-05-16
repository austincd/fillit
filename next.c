/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 20:09:31 by adaly             #+#    #+#             */
/*   Updated: 2017/05/15 16:31:05 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_next_spot(int **array, int **sol, int *c_x, int *c_y)
{
	int x;
	int y;

	x = *c_x;
	y = *c_y;
	while (y < array[0][1])
	{
		while (x < array[0][1])
		{
			if (x >= 0 && y >= 0)
			{
				if (sol[x][y] == 0 && (x != *c_x || y != *c_y))
				{
					*c_x = x;
					*c_y = y;
					return (1);
				}
			}
			++x;
		}
		x = 0;
		++y;
	}
	return (0);
}

int		ft_next_piece(int **array)
{
	int index;

	index = 0;
	while (index < array[0][0])
	{
		if (array[2][index] == 0)
			return (index);
		++index;
	}
	return (-1);
}
