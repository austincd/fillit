/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 20:09:31 by adaly             #+#    #+#             */
/*   Updated: 2017/05/15 17:40:53 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_print_board(int **array, int **sol)
{
	int		status;
	int		index;
	char	*tileset;

	tileset = ft_strdup(".ABCDEFGHIJKLMNOPQRSTUVWXYZ123456789\
	abcdefghijklmnopqrstuvwxyz");
	status = 0;
	index = 0;
	while (status < array[0][1])
	{
		while (index < array[0][1])
		{
			ft_putchar(*(sol[index][status] + tileset));
			++index;
		}
		ft_putchar('\n');
		++status;
		index = 0;
	}
	free(tileset);
}
