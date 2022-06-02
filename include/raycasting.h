/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycasting.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/02 12:24:49 by ngerrets      #+#    #+#                 */
/*   Updated: 2022/06/02 12:37:48 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include "program.h"
# include "ray3.h"
# include "collision.h"
# include "color.h"

/**
**	Ray data accumulated over bounces
*/
typedef struct s_rdata
{
	t_collision	last_coll;
	t_color		color;
}	t_rdata;

typedef t_rdata (*t_rcastfunc)(t_program *, t_ray3 *, t_rdata);


void	*material_get_func(t_material_type type);

t_collision	raycast_get_collision(t_list *shapes, const t_ray3 *ray);
t_color		ray_to_light(t_program *program, t_collision coll);
t_rdata		raycast(t_program *program, t_ray3 *ray);


#endif