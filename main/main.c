/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjoosten <mjoosten@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/17 11:11:40 by ngerrets      #+#    #+#                 */
/*   Updated: 2022/07/05 19:13:24 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "program.h"

int	main(int argc, char **argv)
{
	t_program	program;

	program = program_get();
	if (argc < 2)
		argv[1] = "scenes/planets.rt"; // TODO: change
	build_scene(&program, argv[1]);
	program_init_mlx(&program);
	program_run(&program);
	program_terminate(&program);
	return (EXIT_SUCCESS);
}
