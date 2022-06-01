/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   camera.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/01 13:51:12 by ngerrets      #+#    #+#                 */
/*   Updated: 2022/06/01 14:32:43 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "program.h"

void	camera_calculate_matrix(t_cam *camera)
{
	t_v3	up;
	t_v3	right;

	right = vec3_cross(vec3(0, 1, 0), camera->direction);
	if (vec3_length(right) == 0)
		right = vec3(1, 0, 0);
	else
		vec3_normalize(&right);
	up = vec3_cross(camera->direction, right);
	vec3_normalize(&up);
	camera->view_matrix = matrix(right, up, camera->direction, vec3(0, 0, 0));
}
