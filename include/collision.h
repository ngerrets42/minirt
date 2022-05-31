/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 11:29:31 by ngerrets          #+#    #+#             */
/*   Updated: 2022/05/31 13:12:10 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLLISION_H
# define COLLISION_H

# include "vec3.h"
# include "shape.h"
# include "ray3.h"

/**
**	Collision data of ray intersecting a shape
**	@param point <t_v3> Point-Vector of world collision
**	@param normal <t_v3> Normal vector of collision
**	@param shape <t_shape*> Shape that got collided with
*/
typedef struct s_collision
{
	t_v3	point;
	t_v3	normal;
	t_shape	*shape;
}			t_collision;

typedef t_collision (*t_collfunc)(const t_shape *, const t_ray3 *);

/* raycast.c */
t_collision	collision_none(void);
t_collision	raycast_get_collision(t_list *shapes, const t_ray3 *ray);

/* collisions.c */
void		*collision_get_func(t_shape_type type);
t_collision	collision_sphere(const t_shape *sphere, const t_ray3 *ray);

/* shape_plane.c */
t_collision	shape_plane_collision(const t_shape *plane, const t_ray3 *ray);

#endif
