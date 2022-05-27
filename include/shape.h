/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shape.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/16 13:11:37 by ngerrets      #+#    #+#                 */
/*   Updated: 2022/03/03 12:55:40 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPE_H
# define SHAPE_H

# include "vec3.h"
# include "color.h"
# include "ray3.h"
# include "shape_masks.h"
# include <stdlib.h>

typedef enum e_material_type
{
	MATERIAL_DEFAULT = 0,
	MATERIAL_CUSTOM
}	t_material_type;

/**
**	data to define behaviour of impacting rays
**	@param reflection	<float> percentage (0.0 - 1.0) of "mirrorness"
**
*/
typedef struct s_material
{
	t_material_type	type;
	float			reflection;
}				t_material;

/**
**	Represents a default shape
**	@param type <t_shape_type> Enumerator for the type of shape (like circle)
**	@param origin <t_v3> Origin point vector of the shape. Usually the center
**	@param color <t_color> Color the shape has overall.
**	@param mask <void*> Pointer to the shape's collision data, it's mask.
*/
typedef struct s_shape
{
	t_shape_type	type;
	t_v3			origin;
	t_color			color;
	t_material		material;
	void			*mask;
}					t_shape;

/* shape.c */
t_shape	*shape_create(t_shape_type type, t_v3 origin, t_color col, void *mask);
void	shape_free(void *shape);

/* shape_mask.c */
void	*shape_mask(t_shape_type type, void *data);

/* shape_debug.c */
void	shape_print(t_shape *shape);

/* shape_material.c */
int	shape_is_default_material(t_shape *shape);

#endif