/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 22:06:24 by jgaillar          #+#    #+#             */
/*   Updated: 2017/06/19 22:06:25 by jgaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			mlx_pixel_put_to_image(t_img img, int x, int y, int color)
{
	int			bit_pix;
	float		img_size;

	img_size = WIDTH * LENGTH * img.bits_per_pixel / 8;
	if (x < 0 || y < 0 || y * img.size_line + x * img.bits_per_pixel / 8 > \
		img_size
		|| x >= img.size_line / (img.bits_per_pixel / 8) || y >= img_size / \
		img.size_line)
		return ;
	bit_pix = img.bits_per_pixel / 8;
	img.data[y * img.size_line + x * bit_pix] = color;
	img.data[y * img.size_line + x * bit_pix + 1] = color >> 8;
	img.data[y * img.size_line + x * bit_pix + 2] = color >> 16;
}
