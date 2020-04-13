#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct s_chain
{
  char c;
}	      t_chain;



void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	long int n;

	n = nb;
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putchar((n % 10) + 48);
	}
	if (n <= 9)
		ft_putchar(n + 48);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)b;
	while (i < len)
	{
		str[i] = (unsigned char)c;
		i++;
	}
	return (b);
}


void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)dst)[i] = ((char *)src)[i];
		i++;
	}
	return (dst);
}

void	*ft_memalloc(size_t size)
{
	void	*ptr;

	if (!(ptr = malloc(size)))
		return (NULL);
	ft_memset(ptr, 0, size);
	return (ptr);
}

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *list;

	if (!(list = (t_list*)ft_memalloc(sizeof(t_list))))
		return (NULL);
	if (content)
	{
		if (!(list->content = (void*)ft_memalloc(content_size)))
			return (NULL);
		ft_memcpy(list->content, content, content_size);
		list->content_size = content_size;
	}
	else
	{
		list->content = NULL;
		list->content_size = 0;
	}
	list->next = NULL;
	return (list);
}


void		ft_lstrevrotate(t_list **alst)
{
	t_list	*first;
	t_list	*current;
	t_list	*before_last;

	first = *alst;
	current = first;
	while (current->next)
	{
		before_last = current;
		current = current->next;
	}
	current->next = first;
	*alst = current;
	before_last->next = NULL;
}

size_t		ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	if (str)
	{
		while (str[i])
			i++;
	}
	return (i);
}

void	ft_lstappend(t_list **alst, t_list *new)
{
	t_list	*holder;

	if (!new)
		return ;
	holder = *alst == NULL ? NULL : *alst;
	if (holder)
	{
		while (holder->next != NULL)
			holder = holder->next;
		holder->next = new;
		return ;
	}
	*alst = new;
}

void	add_to_chain(t_list **list, char c)
{
    t_list *node;
    t_chain elem;

    if (!(node = ft_lstnew(&elem, sizeof(t_chain))))
      return ;
    ((t_chain *)node->content)->c = c;
    ft_lstappend(list, node);
}

t_list	*chain(char *string)
{
  t_list *list;
  t_list *add;
  t_chain elem;
  int i = 1;

  if (!(list = ft_lstnew(&elem, sizeof(t_chain))))
    return (0);
  ((t_chain *)list->content)->c = *string;
  while (string[i])
  {
    add_to_chain(&list, string[i]);
    i++;
  }
  return (list);
}

int compare_lists(t_list *l1, t_list *l2)
{
  t_list *a;
  t_list *b;
  char char1;
  char char2;

  a = l1;
  b = l2;

  while (a)
  {
    char1 = ((t_chain *)a->content)->c;
    char2 = ((t_chain *)b->content)->c;
    if (char1 != char2)
      return (0);
    a = a->next;
    b = b->next;
  }
  return (1);
}

void print_list(t_list *list)
{
  t_list *a;

  a = list;

  while (a)
  {
    ft_putchar(((t_chain *)a->content)->c);
    a = a->next;
  }
  ft_putchar('\n');
}

void    ft_memdel(void **ap)
{
  if (ap)
  {
    free(*ap);
    *ap = NULL;
  }
}

void    ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
    if (*alst)
      (*del)((*alst)->content, (*alst)->content_size);
      ft_memdel((void **)alst);
}

void del_node(void *content, size_t size)
{
  if (content && size)
    free(content);
}

void    ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
    if (*alst)
    {
      ft_lstdel(&(*alst)->next, del);
      ft_lstdelone(alst, del);
    }
}


void clean_lists(t_list **list1, t_list **list2)
{
  ft_lstdel(list1, del_node);
  ft_lstdel(list2, del_node);
}

int ft_necklace(char *s1, char *s2)
{
  t_list *list1;
  t_list *list2;
  t_list *b;
  int size;
  int i = 0;

  list1 = chain(s1);
  list2 = chain(s2);
  size = ft_strlen(s1);
  if (size != ft_strlen(s2))
    return (0);
  while (i++ < size)
  {
    if (compare_lists(list1, list2) == 1)
    {
      clean_lists(&list1, &list2);
      return (1);
    }
    else
      ft_lstrevrotate(&list2);
  }
  clean_lists(&list1, &list2);
  return (0);
}
