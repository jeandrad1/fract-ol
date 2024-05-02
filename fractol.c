#include "fractol.h"

bool    get_formula(char *str)
{
//    if (ft_strcmp(str, "mandelbrot") == 0)
//        return (1);
    if (ft_strcmp(str, "julia") == 0)
        return (1);
//    if (ft_strcmp(str, "burning_ship") == 0)
//        return (1);
    return (0);
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc >= 2 && argc <= 3)
	{
		i = 1;
		while (i < argc)
		{
			if (!get_formula(argv[i]))
				break ;
			i++;
		}
		if (i == argc)
			start(argc - 1, &argv[1]);
	}
	print_help();
	return (0);
}