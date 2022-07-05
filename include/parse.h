/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjoosten <mjoosten@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/30 13:16:24 by mjoosten      #+#    #+#                 */
/*   Updated: 2022/07/05 10:46:20 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "shape.h"
# include "shape_masks.h"
# include "light.h"
# include "objects.h"
# include "program.h"

/**
**	@param type <t_object> Object enum
**	@param id <char*> Letter identifier
**	@param min_args <int> Minimum amount of arguments
**	@param max_args <int> Maximum amount of arguments
**	@param f <void(*f)(char **, void *)> Function to return object
**	@param ptr <void*> Second argument of f: address to put object in/add to
*/
typedef struct s_object
{
	t_object_type	type;
	char			*id;
	int				min_args;
	int				max_args;
	void			(*f)(char **, t_program *);
}					t_object;

void	build_ambience(char **args, t_program *program);
void	build_camera(char **args, t_program *program);
void	build_light(char **args, t_program *program);

char	*double_err_check(char *str);
double	atod(char *str);

t_v3	parse_vector(char *str);
t_v3	parse_vector_norm(char *str);
t_color	parse_color(char *str);

#endif