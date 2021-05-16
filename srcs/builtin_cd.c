#include "../includes/minishell.h"
#include "limits.h"

int	builtin_cd(char **argv, t_env *envs)
{
	char	*path;

	(void)envs;
	if (!argv[1])
	{
		path = get_env(envs, "HOME");
		if (!path)
		{
			print_error("cd", 0, "HOME not set");
			return (1);
		}
		modify_env(envs, "OLDPWD", pwd_getcurpath());
		if (chdir(path) == -1)
		{
			printf("[%s]\n", path);
			print_error("cd", 0, 0);
			return (1);
		}
		return (0);
	}
	if (!ft_strcmp(argv[1], "-"))
	{
		path = get_env(envs, "OLDPWD");
		if (!path)
		{
			print_error("cd", 0, "OLDPWD not set");
			return (1);
		}
		modify_env(envs, "OLDPWD", pwd_getcurpath());
		if (chdir(path) == -1)
		{
			printf("[%s]\n", path);
			print_error("cd", 0, 0);
			return (1);
		}
		ft_puts(path, 1);
		ft_puts("\n", 1);
		return (0);
	}
	modify_env(envs, "OLDPWD", pwd_getcurpath());
	if (chdir(argv[1]) == -1)
	{
		printf("[%s]\n", path);
		print_error("cd", 0, 0);
		return (1);
	}
	return (0);
}
