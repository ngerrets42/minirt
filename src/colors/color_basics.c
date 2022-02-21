/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color_basics.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/16 10:38:34 by ngerrets      #+#    #+#                 */
/*   Updated: 2022/02/21 17:27:02 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include <math.h>

t_color	color_rgb(int r, int g, int b)
{
	return ((t_color){(float)r / 255.0, (float)g / 255.0, (float)b / 255.0});
}

t_color	color_f(float r, float g, float b)
{
	return ((t_color){r, g, b});
}

int	color_to_int(t_color c)
{
	unsigned char	trgb[4];

	trgb[0] = c.b * 255;
	trgb[1] = c.g * 255;
	trgb[2] = c.r * 255;
	trgb[3] = 255;
	return (*(int *)trgb);
}

t_color	color_from_int(int c)
{
	unsigned char	trgb[4];
	t_color			result;

	*(int *)trgb = c;
	result.r = (float)trgb[2] / 255.0;
	result.g = (float)trgb[1] / 255.0;
	result.b = (float)trgb[0] / 255.0;
	return (result);
}

void	color_normalize(t_color *c)
{
	float	largest;

	if (c->r >= c->g && c->r >= c->b)
		largest = c->r;
	else if (c->g >= c->r && c->g >= c->b)
		largest = c->g;
	else
		largest = c->b;
	c->r /= largest;
	c->g /= largest;
	c->b /= largest;
}
