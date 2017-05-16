/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 14:28:22 by adaly             #+#    #+#             */
/*   Updated: 2017/05/15 14:30:11 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int **array;
	int status;
	int index;
	int **sol;

	index = -1;
	status = 0;
	array = (int**)ft_memalloc(sizeof(int*) * 5);
	while (index < 4)
		array[++index] = (int*)ft_memalloc(sizeof(int) * 26);
	index = 0;
	if (argc == 2)
	{
		status = ft_read_tetrominos(argv[1], array);
		if (status == 0)
		{
			sol = ft_find_solution(array);
			ft_print_board(array, sol);
		}
		else
			ft_putendl("error");
	}
	else
		ft_putendl("error");
	return (1);
}
