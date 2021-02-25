/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   callback.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 14:54:53 by xamartin          #+#    #+#             */
/*   Updated: 2021/02/23 16:28:41 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "particule_system.h"

void		key_callback(GLFWwindow *window, int key, int scancode,
	int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	if (scancode || mods)
		return ;
}

void		mouse_callback(GLFWwindow *window, double xpos, double ypos)
{
	if (window || xpos || ypos)
		return ;
}

void		error_callback(int error, const char *description)
{
	printf("Error %d: %s\n", error, description);
}
