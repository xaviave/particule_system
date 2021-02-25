/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 16:05:12 by xamartin          #+#    #+#             */
/*   Updated: 2021/02/25 10:46:47 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "render.h"

static int	init_graphic_context(t_engine *e)
{
	if (!glfwInit())
		return (0);
	glfwSetErrorCallback(error_callback);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	if (!(e->win = glfwCreateWindow(W, H, PROG_NAME, NULL, NULL)))
		return (0);
	glfwWindowHint(GLFW_REFRESH_RATE, 60);
	glfwSetInputMode(e->win, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	glfwSetKeyCallback(e->win, key_callback);
	glfwSetCursorPosCallback(e->win, mouse_callback);
	glfwMakeContextCurrent(e->win);
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		return (0);
	glfwSwapInterval(1);
    glEnable(GL_DEPTH_TEST);
	glEnable(GL_PROGRAM_POINT_SIZE);
	return (1);
}

int			init_graphic(t_engine *e)
{
	if (!init_graphic_context(e))
	{
		printf("Error while init GLFW and OpenGL (render/init/graphic.c)\n");
		return (0);
	}
	if (!init_shader(e))
	{
		printf("Error while init OpenGLSL (render/shader.c)\n");
		return (0);
	}
	return (1);
}