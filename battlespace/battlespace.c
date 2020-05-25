/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   battlespace.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geargenc <geargenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 10:52:45 by geargenc          #+#    #+#             */
/*   Updated: 2020/05/25 23:04:16 by geargenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "battlespace.h"

int					ft_maperror(int fd)
{
	dprintf(STDERR_FILENO, "Map Error\n");
	close(fd);
	return (-1);
}

int					ft_readmap(char *map, t_board *board)
{
	int				fd;
	char			buf[21];
	int				ret;
	int				i;
	int				j;

	if ((fd = open(map, O_RDONLY)) < 0)
	{
		perror(NULL);
		return (-1);
	}
	j = 0;
	while ((ret = read(fd, buf, 21)) > 0)
	{
		if (j > 9 || ret < 21 || buf[20] != '\n')
			return (ft_maperror(fd));
		i = 0;
		while (i < 10)
		{
			if (buf[2 * i] != ' ')
				return (ft_maperror(fd));
			if (buf[2 * i + 1] == '.')
				board->squares[j * 10 + i].type = E_TYPE_NONE;
			else if (buf[2 * i + 1] == 'M')
				board->squares[j * 10 + i].type = E_TYPE_MINE;
			else if (buf[2 * i + 1] == 'S')
				board->squares[j * 10 + i].type = E_TYPE_SHIELD;
			else if (isdigit(buf[2 * i + 1]))
			{
				board->squares[j * 10 + i].type = E_TYPE_VESSEL;
				board->squares[j * 10 + i].index = buf[2 * i + 1] - '0';
				if (board->vessels[board->squares[j * 10 + i].index] == 0)
					board->remaining++;
				board->vessels[board->squares[j * 10 + i].index]++;
			}
			else
				return (ft_maperror(fd));
			i++;
		}
		j++;
	}
	close(fd);
	if (ret < 0)
	{
		perror(NULL);
		return (-1);
	}
	return (0);
}

void				ft_exec_child(char *resolver, int pipefdin[2],
					int pipefdout[2], char **envp)
{
	char			*argv[2];

	close(pipefdin[0]);
	close(pipefdout[1]);
	if (dup2(pipefdin[1], STDOUT_FILENO) < 0)
	{
		perror(NULL);
		exit(EXIT_FAILURE);
	}
	close(pipefdin[1]);
	if (dup2(pipefdout[0], STDIN_FILENO) < 0)
	{
		perror(NULL);
		exit(EXIT_FAILURE);
	}
	close(pipefdout[0]);
	argv[0] = resolver;
	argv[1] = NULL;
	execve(resolver, argv, envp);
	perror(NULL);
	exit(EXIT_FAILURE);
}

int					ft_get_move(int fd)
{
	char			buf[3];
	int				i;
	int				ret;

	i = 0;
	while (i < 3 && (ret = read(fd, buf + i, 3 - i)) > 0)
		i += ret;
	if (ret < 0)
		perror(NULL);
	if (i < 3 || buf[0] < 'A' || buf[0] > 'J' || buf[1] < '0' ||
		buf[1] > '9' || buf[2] != '\n')
		return (-1);
	return ((buf[0] - 'A') * 10 + (buf[1] - '0'));
}

int					ft_is_protected(int move, t_board *board)
{
	int				i;
	int				j;

	j = move / 10 - 2;
	while (j < move / 10 + 3)
	{
		i = move % 10 - 2;
		while (i < move % 10 + 3)
		{
			if (j >= 0 && j < 10 && i >= 0 && i < 10 &&
				board->squares[j * 10 + i].type == E_TYPE_SHIELD)
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}

int					ft_play_move(int move, int fd, t_board *board)
{
	if (board->squares[move].type == E_TYPE_NONE)
		dprintf(fd, "MISS\n");
	else if (board->squares[move].type == E_TYPE_MINE)
	{
		if (ft_is_protected(move, board))
			dprintf(fd, "BLOCKED\n");
		else
		{
			board->squares[move].type = E_TYPE_NONE;
			dprintf(fd, "HIT\n");
		}
	}
	else if (board->squares[move].type == E_TYPE_SHIELD)
	{
		board->squares[move].type = E_TYPE_NONE;
		dprintf(fd, "SUNK\n");
	}
	else if (board->squares[move].type == E_TYPE_VESSEL)
	{
		if (ft_is_protected(move, board))
			dprintf(fd, "BLOCKED\n");
		else
		{
			board->squares[move].type = E_TYPE_NONE;
			board->vessels[board->squares[move].index]--;
			if (board->vessels[board->squares[move].index] < 1)
			{
				board->remaining--;
				if (board->remaining < 1)
					return (0);
				dprintf(fd, "SUNK\n");
			}
			else
				dprintf(fd, "HIT\n");
		}
	}
	return (1);
}

int					ft_exec_parent(pid_t pid, int pipefdin[2],
					int pipefdout[2], t_board *board)
{
	int				ret;
	int				count;

	close(pipefdin[1]);
	close(pipefdout[0]);
	ret = 1;
	count = 0;
	while (ret > 0 && count < 200)
	{
		ret = ft_get_move(pipefdin[0]);
		if (ret >= 0)
			ret = ft_play_move(ret, pipefdout[1], board);
		count++;
	}
	kill(pid, SIGTERM);
	printf("%d\n", ret < 0 ? 200 : count);
	return (0);
}

int					ft_exec_resolver(char *resolver, t_board *board,
					char **envp)
{
	pid_t			pid;
	int				pipefdin[2];
	int				pipefdout[2];

	if (pipe(pipefdin) || pipe(pipefdout) || (pid = fork()) < 0)
	{
		perror(NULL);
		return (-1);
	}
	if (pid == 0)
		ft_exec_child(resolver, pipefdin, pipefdout, envp);
	return (ft_exec_parent(pid, pipefdin, pipefdout, board));
}

int					ft_battlespace(char *map, char *resolver, char **envp)
{
	t_board			board;

	bzero(&board, sizeof(t_board));
	if (ft_readmap(map, &board) || ft_exec_resolver(resolver, &board, envp))
		return (-1);
	return (0);
}

int					main(int argc, char **argv, char **envp)
{
	char			*tmp;

	if (argc != 3)
	{
		tmp = strrchr(argv[0], '/');
		tmp = tmp ? tmp + 1 : argv[0];
		printf("Usage: %s <map> <resolver>\n", tmp);
		return (1);
	}
	if (ft_battlespace(argv[1], argv[2], envp))
		return (1);
	return (0);
}
