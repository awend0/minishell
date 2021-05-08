#include "../includes/minishell.h"

int	main(int argc, char **argv, char **env)
{
	int			status;
	char		*line;
	t_cmdtable	*cmdtable;
	t_env		*envs;

	(void)argc;
	(void)argv;
	envs = init_envs(env);
	while (!status)
	{
		putstr("sh» ", 1);
		line = get_next_line(1, &line);
		cmdtable = parser(line, envs);
		free(line);
		status = executor(cmdtable, envs);
	}
	return (status);
}
