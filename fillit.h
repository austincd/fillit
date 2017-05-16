/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 12:54:28 by adaly             #+#    #+#             */
/*   Updated: 2017/05/15 16:34:19 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft/libft.h"

int			*ft_generate_square(int ***sol_inner, \
int dimensions, unsigned long *size_insulated);
int			**ft_find_solution(int **array);
int			**ft_assemble(int **array, int **sol, int piece);
int			ft_next_spot(int **array, int **sol, int *c_x, int *c_y);
int			ft_next_piece(int **array);
int			ft_validate(int **draft);
int			**ft_draft_tetromino(int tetromino, int ox, int oy, int **sol);
void		ft_draft_tetromino_two(int *num, int **sol, int ***ptr);
void		ft_draft_tetromino_three(int *num, int **sol, int ***ptr);
void		ft_draft_tetromino_four(int *num, int **sol, int ***ptr);
void		ft_place(int piece, int **draft, int **array);
void		ft_unplace(int piece, int **draft, int **array);
void		ft_print_board(int **array, int **sol);
int			ft_interpret_tetromino(char *tetromino);
int			ft_interpret_three(char *ptr);
int			ft_interpret_two(char *ptr);
int			ft_read_tetrominos(char *file_path, int **array);
int			ft_read_helper(int **array, int *nums, char \
*buffer, char *insulated_buffer);

#endif
