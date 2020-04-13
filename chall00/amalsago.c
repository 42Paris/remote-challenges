/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   amalsago.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 22:03:32 by amalsago          #+#    #+#             */
/*   Updated: 2020/04/06 23:17:18 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

#define SUCCESS 1
#define FAILURE 0

typedef struct	s_letter t_letter;
struct			s_letter
{
	t_letter	*prev;
	char		letter;
	t_letter	*next;
};

typedef struct	s_word t_word;
struct			s_word
{
	t_letter	*head;
	int			len;
};

static t_letter	*new_letter(char c)
{
	t_letter	*new;

	if (!(new = (t_letter *)malloc(sizeof(t_letter))))
		return (NULL);
	new->prev = new;
	new->letter = c;
	new->next = new;
	return (new);
}

static void		add2word(t_word *word, t_letter *letter)
{
	t_letter	*head;

	if (word->len == 0)
		word->head = letter;
	else
	{
		head = word->head;
		head->prev->next = letter;
		letter->prev = head->prev;
		head->prev = letter;
		letter->next = head;
	}
	word->len += 1;
}

static char		*rotate_word(t_word *word, char *llword)
{
	int			i;
	t_letter	*letter;

	i = -1;
	letter = word->head;
	while (++i < word->len)
	{
		llword[i] = letter->letter;
		letter = letter->next;
	}
	return (llword);
}

int				ft_necklace(const char *s1, const char *s2)
{
	int			i;
	int			found;
	char		*llword;
	t_word		*word;

	i = -1;
	found = 1;
	if (!*s1 && !*s2)
		return (SUCCESS);
	if (!(word = (t_word *)malloc(sizeof(t_word))))
		return (FAILURE);
	while (*s2)
		add2word(word, new_letter(*s2++));
	if (!(llword = (char *)malloc((sizeof(char) * word->len) + 1)))
		return (FAILURE);
	while (++i < word->len)
	{
		llword = rotate_word(word, llword);
		if (!(found = strcmp(s1, llword)))
			break ;
		word->head = word->head->next;
	}
	return (found == 0 ? SUCCESS : FAILURE);
}
