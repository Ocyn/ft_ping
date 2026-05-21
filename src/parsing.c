#include "./ft_ping.h"

t_params	parse_arg(char **tab)
{
	t_params	params;
	params.help = 0;
	params.verbose = 0;
	for (size_t j = 0; tab[j]; j++)
	{
		char *arg = tab[j];
		for (size_t i = 0; arg[i]; i++)
		{
			if (arg[i] == '-')
			{
				if (arg[i + 1] && arg[i + 1] == 'v')
					params.verbose = true;
				if (arg[i + 1] && arg[i + 1] == '?')
					params.help = true;
			}
		}
	}
	return params;
}

