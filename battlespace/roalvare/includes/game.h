/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalvare <roalvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 09:04:18 by roalvare          #+#    #+#             */
/*   Updated: 2020/06/02 09:04:25 by roalvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "libft.h"

typedef enum	e_state
{
	NONE,
	MISS,
	HIT,
	BLOCKED,
	SUNK,
	SHIELD
}				t_state;

#endif
