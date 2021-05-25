#include "../includes/minishell.h"

int	executor_init_fds(int tmp[7], t_cmdtable *table)
{
	tmp[2] = dup(0);
	tmp[3] = dup(1);
	if (table->input_file)
	{
		tmp[4] = open(table->input_file, O_RDONLY);
		if (tmp[4] == -1)
			return (-1);
	}
	else
	{
		tmp[4] = dup(tmp[2]);
		if (tmp[4] == -1)
			return (-1);
	}
	return (0);
}

int	executor_redir(int oldfd, int newfd)
{
	if (dup2(oldfd, newfd) == -1)
		return (-1);
	close(oldfd);
	return (0);
}

int	executor_switch(int **tmp)
{
	int	*cur;

	cur = *tmp;
	if (pipe(cur) == -1)
		return (-1);
	cur[5] = cur[1];
	cur[4] = cur[0];
	return (0);
}

int	executor_run_and_redir(t_cmd *cmd, t_cmdtable *table, int tmp[7])
{
	if (cmd->next == 0)
	{
		if (table->output_file)
		{
			if (table->append)
				tmp[5] = open(table->output_file, APPEND);
			else
				tmp[5] = open(table->output_file, TRUNCATE);
			if (tmp[5] == -1)
				return (-1);
		}
		else
		{
			tmp[5] = dup(tmp[3]);
			if (tmp[5] == -1)
				return (-1);
		}
	}
	else
		return (executor_switch(&tmp));
	return (0);
}
