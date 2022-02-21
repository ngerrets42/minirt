/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/17 11:11:40 by ngerrets      #+#    #+#                 */
/*   Updated: 2022/02/21 17:50:48 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "program.h"
#include "log.h"


int	main(void)
{
	t_program	*program;

	program = program_get();
	if (program == NULL)
		return (EXIT_FAILURE);
	program_run(program);
	LOG("Program end");
	return (EXIT_SUCCESS);
}
