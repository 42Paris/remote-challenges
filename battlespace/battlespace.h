/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   battlespace.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geargenc <geargenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 18:46:25 by geargenc          #+#    #+#             */
/*   Updated: 2020/05/25 23:05:44 by geargenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BATTLESPACE_H

# define BATTLESPACE_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <errno.h>
# include <unistd.h>
# include <ctype.h>
# include <signal.h>

typedef enum		e_type
{
	E_TYPE_NONE,
	E_TYPE_VESSEL,
	E_TYPE_MINE,
	E_TYPE_SHIELD
}					t_type;

typedef struct		s_square
{
	t_type			type;
	int				index;
}					t_square;

typedef struct		s_board
{
	t_square		squares[100];
	int				vessels[10];
	int				remaining;
}					t_board;

#endif
