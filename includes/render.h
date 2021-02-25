/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 15:09:47 by xamartin          #+#    #+#             */
/*   Updated: 2021/02/24 14:32:09 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "particule_system.h"


/*
** init/graphic.c
*/

int			init_graphic(t_engine *e);

/*
** callback.c
*/

void		key_callback(GLFWwindow *window, int key, int scancode,
    int action, int mods);
void		mouse_callback(GLFWwindow *window, double xpos, double ypos);
void		error_callback(int error, const char *description);

/*
** shaders.c
*/

int			init_shader(t_engine *e);

#endif