#ifndef GAME_H
# define GAME_H

# include "libft.h"
# include <sys/time.h>
# include <time.h>
#include <stdio.h>

typedef enum	e_state
{
				NONE,
				MISS,
				HIT,
				BLOCKED,
				SUNK,
				SHIELD
}				t_state;

typedef enum	e_way
{
				UP,
				UP_RIGHT,
				RIGHT,
				DOWN_RIGHT,
				DOWN,
				DOWN_LEFT,
				LEFT,
				UP_LEFT 
}				t_way;

typedef enum	e_boat
{
				FREGATE,
				DESTROYER,
				CRUISER,
				CARRIER,
				STATION,
				SQUARE,
				MOTHER_SHIP,
				HOLE,
				BLOCKER
}				t_boat;

typedef struct s_box
{
	struct s_box	*near[8];
}				t_box;

typedef struct	s_army
{
	int			nation[5];
	int			mercenaries[5];
	int			aliens[5];
}				t_army;


t_box	*create_box();
void	add_box(t_box *parent, t_way dir);
void	add_link(t_box *parent, t_box *child, t_way dir);
void	print_box(t_box *node);
void	box_suffixe(t_box *root, t_list **lst);

t_box	*create_fregate();
t_box	*create_destroyer();
t_box	*create_cruiser();
t_box	*create_carrier();

t_box	*create_station();
t_box	*create_square();

t_box	*create_mother_ship();
t_box	*create_hole();
t_box	*create_blocker();

#endif