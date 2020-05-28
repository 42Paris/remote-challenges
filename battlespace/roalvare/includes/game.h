#ifndef GAME_H
# define GAME_H

# include "libft.h"

typedef enum	e_state
{
				NONE,
				MISS,
				HIT,
				SUNK,
				BLOCKED
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

typedef struct s_box
{
	struct s_box	*near[8];
}				t_box;


t_box	*create_box();
void	add_box(t_box *parent, t_way dir);
void	print_box(t_box *node);
void	box_suffixe(t_box *root, t_list **lst);

#endif