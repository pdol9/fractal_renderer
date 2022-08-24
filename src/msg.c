/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdolinar <pdolinar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 17:12:33 by pdolinar          #+#    #+#             */
/*   Updated: 2022/07/18 19:57:58 by pdolinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	msg(void)
{
	ft_putendl_fd("\n************************************************\n", 1);
	ft_putendl_fd("  Use the following cmd to run any of the fractals: ", 1);
	ft_putendl_fd("     ./fractol -[initial letter]\n", 1);
	ft_putendl_fd("--> to zoom use mouse wheel or up / down arrow ", 1);
	ft_putendl_fd("--> to move use W, A, S, D", 1);
	ft_putendl_fd("--> to change set press SPACE", 1);
	ft_putendl_fd("--> to change colors press ENTER", 1);
	ft_putendl_fd("--> to reset any set press R\n", 1);
	ft_putendl_fd("************************************************\n", 1);
	return (0);
}

void	handle_error(int value)
{
	if (value == -1)
	{
		ft_putendl_fd("\n***********************************************\n", 1);
		ft_putendl_fd("  Invalid input, run cmd as such:\n", 1);
		ft_putendl_fd("\t ./fractol -[first letter of a fractal]", 1);
		ft_putendl_fd("\n***********************************************\n", 1);
		exit(1);
	}
	else if (value == -2)
	{
		ft_putendl_fd("\n**********************************************\n", 1);
		ft_putendl_fd("Use a valid fractal:", 1);
		ft_putendl_fd(" >> -m for mandelbrot", 1);
		ft_putendl_fd(" >> -j for julia", 1);
		ft_putendl_fd(" >> -b for burning ship", 1);
		ft_putendl_fd("************************************************\n", 1);
		exit(1);
	}
}

void	handle_input(int argc, char **argv, t_fractol *data)
{
	int	value;

	value = -2;
	data->jstart = 0;
	if (argc < 2 || ft_strncmp(argv[0], "./fractol", 9))
		value = -1;
	else if (ft_strncmp(argv[1], "-m", 2) == 0)
		value = 0;
	else if (ft_strncmp(argv[1], "-j", 2) == 0)
	{
		julia_args(argc, argv, data);
		value = 1;
	}
	else if (ft_strncmp(argv[1], "-b", 2) == 0)
		value = 2;
	handle_error(value);
	data->fract_num = value;
}

void	julia_args(int argc, char **argv, t_fractol *data)
{
	if (argc == 4)
	{
		data->kx = ft_atof(argv[2]);
		data->ky = ft_atof(argv[3]);
		data->jstart = 1;
	}
	else
	{
		ft_putendl_fd("************************************************", 1);
		ft_putendl_fd(" ", 1);
		ft_putendl_fd("Use valid float values:\n\t-> -0.766667  -0.090000", 1);
		ft_putendl_fd("or other possible values:", 1);
		ft_putendl_fd("\t->  0.377778   0.314667", 1);
		ft_putendl_fd("\t-> -0.337778   0.683333", 1);
		ft_putendl_fd("\t->  0.004444   0.646000", 1);
		ft_putendl_fd("\t->  0.386667   0.103333", 1);
		ft_putendl_fd("\t-> -0.203333  -0.696667", 1);
		ft_putendl_fd("\t->  0.180000  -0.566667", 1);
		ft_putendl_fd("\t->  0.371504  -0.153893\n", 1);
		ft_putendl_fd("************************************************", 1);
		exit(1);
	}
}
