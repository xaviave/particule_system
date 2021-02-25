/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 16:02:25 by xamartin          #+#    #+#             */
/*   Updated: 2021/02/25 17:15:36 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static int	is_press(GLFWwindow *window, int key)
{
	if (glfwGetKey(window, key) == GLFW_PRESS)
		return (1);
	return (0);
}

static void	quit_options(t_engine *e)
{
	if (is_press(e->win, GLFW_KEY_ESCAPE))
		glfwSetWindowShouldClose(e->win, true);	
}

static void	lock_options(t_engine *e)
{
	if (is_press(e->win, GLFW_KEY_L) && is_press(e->win, GLFW_KEY_C))
		e->i.camera_lock = (!e->i.camera_lock ? 1 : 0);
	if (is_press(e->win, GLFW_KEY_L) && is_press(e->win, GLFW_KEY_K))
		e->i.camera_lock = (!e->i.camera_lock ? 1 : 0);
}

static void	polygon_mode(t_engine *e)
{
	if (is_press(e->win, GLFW_KEY_P) && is_press(e->win, GLFW_KEY_L))
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	else if (is_press(e->win, GLFW_KEY_P) && is_press(e->win, GLFW_KEY_F))
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

static void	camera_handler(t_engine *e, t_trans_mat *m)
{
	if (is_press(e->win, GLFW_KEY_LEFT_SHIFT))
		m->camera_info_pos[1] += 0.25;
	if (is_press(e->win, GLFW_KEY_LEFT_CONTROL))
		m->camera_info_pos[1] -= 0.25;
	if (is_press(e->win, GLFW_KEY_LEFT))
		m->camera_info_pos[0] += 0.25;
	if (is_press(e->win, GLFW_KEY_RIGHT))
		m->camera_info_pos[0] -= 0.25;
	if (is_press(e->win, GLFW_KEY_UP))
		m->camera_info_pos[2] += 0.25;
	if (is_press(e->win, GLFW_KEY_DOWN))
		m->camera_info_pos[2] -= 0.25;
	if (is_press(e->win, GLFW_KEY_UP) && m->proj_info.fov < 90)
		m->proj_info.fov += 0.25;
	if (is_press(e->win, GLFW_KEY_DOWN) && m->proj_info.fov > 0)
		m->proj_info.fov -= 0.25;
}

void		input_handler(t_engine *e, t_trans_mat *m)
{
	glfwPollEvents();
	quit_options(e);
	lock_options(e);
	polygon_mode(e);
	e->i.camera_lock = 1;
	if (!e->i.camera_lock)
		camera_handler(e, m);
}