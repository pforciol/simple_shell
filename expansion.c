#include "simpleshell.h"

/**
 * expansion - handles all expansions and replacement functions
 *
 * @data: the data_t structure
 *
 * Return: an int
 */

int expansion(data_t *data)
{
	cmd_lst_lst_t   *llav_head = data->llav_head;
	cmd_lst_t *node;
	int i = 0, j = 0;

	while (llav_head)
	{
		printf("llav_node(%d): [%s]\n", i, llav_head->list);
		node = (llav_head->head);
		j = 0;
		while (node)
		{
			expansion_var_alias(node->av, data);
			expansion_path(&node->av[0], sh_get_env_var("PATH", data->env));
			printf("node (%d) cmds: [%s] exe: [%d]\n", j, node->cmd, node->exe);
			node = node->next;
			++j;
		}
		llav_head = llav_head->next;
		++i;
	}
}
