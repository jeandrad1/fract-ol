void	help_msg(void)
{
	ft_printf("⊱ ───────────────── {.⋅ Fractol ⋅.} ───────────────── ⊰\n\n");
	ft_printf("Which fractal would you like to see?\n");
	ft_printf("M - Mandelbrot    ");
	ft_printf("J - Julia    ");
	ft_printf("T - Tricorn\n\n");
	ft_printf("\e[36mUsage example:\t./fractol <type>\n\t\t./fractol M\e[0m\n\n"\
	);
	ft_printf("\nFor Julia, you may specify starting values which should be betw\
	een -2.0 and 2.0.\n");
	ft_printf("\e[36mUsage example:\t");
	ft_printf("./fractol J\n\t\t./fractol J 0.285 0.01\n");
	ft_printf("\t\t./fractol J -0.4 0.6\n");
	ft_printf("\t\t./fractol J -1.476 0.0\n");
	ft_printf("\t\t./fractol J 0.3 -0.01\e[0m\n\n");
}