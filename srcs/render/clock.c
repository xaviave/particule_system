/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clock.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 16:57:04 by xamartin          #+#    #+#             */
/*   Updated: 2021/02/25 17:11:15 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	clock_handler(t_engine *e)
{
	if (glfwGetTime() - e->c.last_time < 1.0)
		return ;
	e->c.fps = 0;
	e->c.draw_time = 1000.0f / (double)e->c.fps;
	e->c.last_time += 1.0f;
}