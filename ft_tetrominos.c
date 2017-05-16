/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetrominos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 12:11:06 by adaly             #+#    #+#             */
/*   Updated: 2017/05/15 16:32:27 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_read_tetrominos(char *file_path, int **array)
{
	int		nums[3];
	char	*buffer;
	char	*insulated_buffer;

	insulated_buffer = NULL;
	nums[0] = -1;
	nums[0] = ft_open_file(file_path);
	array[0][0] = 0;
	if (nums[0] >= 0)
	{
		buffer = ft_strnew(21);
		if (buffer)
		{
			if (ft_read_helper(array, nums, buffer, insulated_buffer) != 0)
				return (-1);
		}
		return (0);
	}
	return (-1);
}

int		ft_read_helper(int **array, int *nums, \
char *buffer, char *insulated_buffer)
{
	int index;

	index = 0;
	while ((nums[1] = read(nums[0], buffer, 21)))
	{
		if (nums[1] > 0 && nums[1] < 20)
			return (-1);
		else if (ft_how_many_char(buffer, '#') != 4 ||
		ft_how_many_char(buffer, '.') != 12)
			return (-1);
		else
		{
			insulated_buffer = (char*)ft_memalloc(sizeof(char) * 60);
			ft_strcpy(&insulated_buffer[20], buffer);
			array[1][index] = ft_interpret_tetromino(&insulated_buffer[20]);
			if (array[1][index] == -1)
				return (-1);
			array[0][0]++;
			index++;
		}
		if (nums[1] == 20)
			return (0);
	}
	return (-1);
}

int		ft_interpret_tetromino(char *tetromino)
{
	int		index;
	char	*ptr;

	index = 0;
	if (tetromino)
	{
		if (tetromino[index] != '.' && \
		tetromino[index] != '#' && tetromino[index] != '\n')
			return (-1);
		else if ((ptr = ft_strstr(tetromino, "####")))
			return (1);
		else if ((ptr = ft_strstr(tetromino, "###")))
			return (ft_interpret_three(ptr));
		else if ((ptr = ft_strstr(tetromino, "##")))
			return (ft_interpret_two(ptr));
		else if ((ptr = ft_strstr(tetromino, "#")))
		{
			if (*(ptr + 5) == '#' && *(ptr + 10) == '#' && *(ptr + 15) == '#')
				return (8);
		}
	}
	return (-1);
}

int		ft_interpret_three(char *ptr)
{
	if (*(ptr - 5) == '#')
		return (4);
	else if (*(ptr + 5) == '#')
		return (6);
	else if (*(ptr - 4) == '#')
		return (2);
	else if (*(ptr + 6) == '#')
		return (3);
	else if (*(ptr + 7) == '#')
		return (5);
	else if (*(ptr - 3) == '#')
		return (7);
	return (-1);
}

int		ft_interpret_two(char *ptr)
{
	if (*(ptr + 5) == '#' && *(ptr + 4) == '#')
		return (18);
	else if (*(ptr + 6) == '#' && *(ptr + 7) == '#')
		return (17);
	else if (*(ptr + 5) == '#' && *(ptr - 4) == '#')
		return (19);
	else if (*(ptr + 6) == '#' && *(ptr - 5) == '#')
		return (16);
	else if (*(ptr + 5) == '#' && *(ptr + 6) == '#')
		return (15);
	else if (*(ptr + 5) == '#' && *(ptr + 10) == '#')
		return (11);
	else if (*(ptr + 6) == '#' && *(ptr + 11) == '#')
		return (13);
	else if (*(ptr - 5) == '#' && *(ptr - 10) == '#')
		return (14);
	else if (*(ptr - 4) == '#' && *(ptr - 9) == '#')
		return (12);
	else if (*(ptr - 5) == '#' && *(ptr + 5) == '#')
		return (9);
	else if (*(ptr - 4) == '#' && *(ptr + 6) == '#')
		return (10);
	return (-1);
}
