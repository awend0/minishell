#include "../includes/minishell.h"

char	**array_append(char **arr, int len)
{
	char	**new;

	new = ft_calloc(len + 2, sizeof(char *));
	new = arr_copy(new, arr);
	free_arr(arr);
	return (new);
}

void	arg_init(t_cmd *last)
{
	last->argc++;
	last->argv = (array_append(last->argv, last->argc));
}

void	cmd_init(t_cmd **cmd)
{

	(*cmd) = ft_calloc(1, sizeof(t_cmd));
	(*cmd)->next = 0;
	(*cmd)->argc = 0;
	(*cmd)->argv = ft_calloc(2, sizeof(char *));
}

void	cmdtable_init(t_cmdtable **table)
{
	*table = ft_calloc(1, sizeof(t_cmdtable));
	cmd_init(&(*table)->cmds);
	(*table)->last = (*table)->cmds;
	(*table)->input_file = 0;
	(*table)->output_file = 0;
	(*table)->next = 0;
}
