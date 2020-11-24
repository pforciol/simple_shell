#include "simpleshell.h"

int	free_av(char **av)
{
	int	i = 0;

	if (!av)
		return (-1);
	while (av[i])
	{
		free(av[i]);
		++i;
	}
	free(av[i]);
	free(av);
	return (1);
}

void	free_cmd_lst(cmd_lst_t *node)
{
	if (node)
	{
		free_av(node->av);
		free(node->cmd);
		free(node);
	}
}

void	free_cmd_lst_lst(cmd_lst_lst_t *llav)
{
	cmd_lst_t	*node;
	cmd_lst_t	*buf;

	if (llav)
	{
		node = llav->head;
		while (node)
		{
			buf = node;
			node = node->next;
			free_cmd_lst(buf);
		}
		free(llav->list);
		free(llav);
	}
}

int	free_all(cmd_lst_lst_t **head)
{
	cmd_lst_lst_t	*llav;
	cmd_lst_lst_t	*buf;

	if (!head)
		return (-1);
	llav = *head;
	while (llav)
	{
		buf = llav;
		llav = llav->next;
		free_cmd_lst_lst(buf);
	}
	*head = NULL;
	return (1);
}
