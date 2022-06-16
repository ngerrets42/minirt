/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_debug.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 13:51:29 by ngerrets          #+#    #+#             */
/*   Updated: 2022/06/16 11:34:27 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"
#include <stdio.h>
#include <math.h>
#include "objects.h"

static void	_shape_print_mask(t_shape *shape)
{
	if (shape->type == OBJECT_PLANE)
	{
		printf("|  |  normal ");
		vec3_print(shape->n);
	}
	if (shape->type == OBJECT_SPHERE)
		printf("|  |  radius: %.3f\n", shape->sp.radius);
	if (shape->type == OBJECT_CYLINDER)
	{
		printf("|  |  normal ");
		vec3_print(shape->n);
		printf("|  |  radius: %.3f\n", shape->cy.radius);
		printf("|  |  height: %.3f\n", shape->cy.height);
	}
	if (shape->type == OBJECT_CONE)
	{
		printf("|  |  normal ");
		vec3_print(shape->n);
		printf("|  |  height: %.3f\n", shape->co.height);
		printf("|  |  angle: %.3f\n", shape->co.angle * 180 / M_PI);
	}
}

void	shape_print(t_shape *shape)
{
	char	*shape_names[] = {
	"NONE",
	"CAMERA",
	"LIGHT",
	"AMBIENCE",
	"SPHERE",
	"PLANE",
	"CYLINDER",
	"CONE"
	};

	printf("# - SHAPE - - - - - - - - - - - - - - - -\n");
	printf("|  type %s\n", shape_names[shape->type]);
	printf("|  origin ");
	vec3_print(shape->o);
	printf("|  color ");
	color_print_f(shape->color);
	printf("|  MASK:\n");
	_shape_print_mask(shape);
	printf("# - - - - - - - - - - - - - - - - - - - -\n");
}
