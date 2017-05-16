/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 20:09:31 by adaly             #+#    #+#             */
/*   Updated: 2017/05/15 17:53:20 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		**ft_find_solution(int **array)
{
	unsigned long	size_insulated;
	int				**sol;
	int				*sol_str;
	int				**solution;

	sol = NULL;
	array[3][0] = -1;
	array[0][1] = ft_next_sqrt(array[0][0] * 4);
	while (!sol)
	{
		sol_str = ft_generate_square(&solution, array[0][1], &size_insulated);
		if (sol_str)
		{
			sol = ft_assemble(array, solution, 0);
			if (!sol)
			{
				free(sol_str);
				++(array[0][1]);
				array[3][0] = -1;
				array[3][1] = -1;
			}
		}
	}
	return (sol);
}

int		*ft_generate_square(int ***sol_inner, int dimensions, \
unsigned long *size_insulated)
{
	int size;
	int index;
	int *sol_str;
	int counter;

	counter = -1;
	index = -1;
	size = dimensions * (dimensions + 2);
	*size_insulated = size * (size + 4);
	sol_str = (int*)ft_memalloc(sizeof(int) * *size_insulated);
	while ((unsigned int)++index < *size_insulated)
		sol_str[index] = -2;
	index = -1;
	*sol_inner = (int**)ft_memalloc(sizeof(int*) * (dimensions + 8));
	while (++index <= dimensions + 8)
	{
		(*sol_inner)[index] = sol_str + (size / 2) * (size + index * index);
		while (++counter < dimensions && index < dimensions)
			(*sol_inner)[index][counter] = 0;
		counter = -1;
	}
	return (sol_str);
}

int		**ft_assemble(int **array, int **sol, int piece)
{
	int **draft;
	int ox;
	int oy;

	ox = -1;
	oy = -1;
	piece = ft_next_piece(array);
	if (piece >= 0)
	{
		while (ft_next_spot(array, sol, &ox, &oy))
		{
			draft = ft_draft_tetromino(array[1][piece], ox, oy, sol);
			if (ft_validate(draft))
			{
				ft_place(piece, draft, array);
				if (ft_assemble(array, sol, piece))
					return (sol);
				else
					ft_unplace(piece, draft, array);
			}
		}
		return (NULL);
	}
	else
		return (sol);
}
