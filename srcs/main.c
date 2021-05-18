#include "../includes/minishell.h"

t_signal g_signal = {0, 0, 0, 0};

int	main(int argc, char **argv, char **env)
{
	char		*line;
	t_cmdtable	*cmdtable;
	t_env		*envs;

	envs = env_split(env);
	if (argc == 3 && !ft_strcmp(argv[1], "-c"))
		return(executor(parser(argv[2], envs), envs, env));
	signal(SIGINT, &sig_int);
	signal(SIGQUIT, &sig_quit);
	while (1)
	{
		ft_putstr_fd(BOLDCYAN"paSHtet"BOLDYELLOW" » "RESET, 1);
		get_next_line(0, &line);
		cmdtable = parser(line, envs);
		modify_env(envs, "?", ft_itoa(executor(cmdtable, envs, env)));
		free(line);
	}
	return (0);
}
