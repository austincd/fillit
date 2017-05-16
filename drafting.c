/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drafting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 14:26:54 by adaly             #+#    #+#             */
/*   Updated: 2017/05/15 16:30:44 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		**ft_draft_tetromino(int tetromino, int ox, int oy, int **sol)
{
	int **ptr;
	int index;
	int	num[3];

	index = 0;
	num[0] = tetromino;
	num[1] = ox;
	num[2] = oy;
	ptr = (int**)ft_memalloc(sizeof(int*) * 5);
	ptr[0] = &(sol[ox][oy]);
	while (tetromino >= 1 && tetromino <= 7 && index < 3)
	{
		ptr[index] = &(sol[ox + index][oy]);
		++index;
	}
	while (tetromino >= 8 && tetromino <= 14 && index < 3)
	{
		ptr[index] = &(sol[ox][oy + index]);
		++index;
	}
	ft_draft_tetromino_two(num, sol, &ptr);
	return (ptr);
}

void	ft_draft_tetromino_two(int *num, int **sol, int ***ptr)
{
	int	tetromino;
	int	ox;
	int	oy;

	tetromino = num[0];
	ox = num[1];
	oy = num[2];
	if (tetromino >= 15 && tetromino <= 17)
	{
		(*ptr)[1] = &(sol[ox][oy + 1]);
		(*ptr)[2] = &(sol[ox + 1][oy + 1]);
	}
	else if (tetromino >= 18 && tetromino <= 19)
	{
		(*ptr)[1] = &(sol[ox + 1][oy]);
		(*ptr)[2] = &(sol[ox][oy + 1]);
	}
	if (tetromino == 1)
		(*ptr)[3] = &(sol[ox + 3][oy]);
	else if (tetromino == 2)
		(*ptr)[3] = &(sol[ox + 1][oy - 1]);
	else if (tetromino == 3)
		(*ptr)[3] = &(sol[ox + 1][oy + 1]);
	ft_draft_tetromino_three(num, sol, ptr);
}

void	ft_draft_tetromino_three(int *num, int **sol, int ***ptr)
{
	int	tetromino;
	int	ox;
	int	oy;

	tetromino = num[0];
	ox = num[1];
	oy = num[2];
	if (tetromino == 4)
		(*ptr)[3] = &(sol[ox][oy - 1]);
	else if (tetromino == 5)
		(*ptr)[3] = &(sol[ox + 2][oy + 1]);
	else if (tetromino == 6)
		(*ptr)[3] = &(sol[ox][oy + 1]);
	else if (tetromino == 7)
		(*ptr)[3] = &(sol[ox + 2][oy - 1]);
	else if (tetromino == 8)
		(*ptr)[3] = &(sol[ox][oy + 3]);
	else if (tetromino == 9)
		(*ptr)[3] = &(sol[ox + 1][oy + 1]);
	else if (tetromino == 10 && ox > 0)
		(*ptr)[3] = &(sol[ox - 1][oy + 1]);
	else if (tetromino == 11)
		(*ptr)[3] = &(sol[ox + 1][oy]);
	ft_draft_tetromino_four(num, sol, ptr);
}

void	ft_draft_tetromino_four(int *num, int **sol, int ***ptr)
{
	int	tetromino;
	int	ox;
	int	oy;

	tetromino = num[0];
	ox = num[1];
	oy = num[2];
	if (tetromino == 12 && ox > 0)
		(*ptr)[3] = &(sol[ox - 1][oy + 2]);
	else if (tetromino == 13 && ox > 0)
		(*ptr)[3] = &(sol[ox - 1][oy]);
	else if (tetromino == 14)
		(*ptr)[3] = &(sol[ox + 1][oy + 2]);
	else if (tetromino == 15)
		(*ptr)[3] = &(sol[ox + 1][oy]);
	else if (tetromino == 16)
		(*ptr)[3] = &(sol[ox + 1][oy + 2]);
	else if (tetromino == 17 && ox > 0)
		(*ptr)[3] = &(sol[ox - 1][oy]);
	else if (tetromino == 18 && ox > 0)
		(*ptr)[3] = &(sol[ox - 1][oy + 1]);
	else if (tetromino == 19)
		(*ptr)[3] = &(sol[ox + 1][oy - 1]);
}
