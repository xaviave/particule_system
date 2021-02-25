/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 15:09:47 by xamartin          #+#    #+#             */
/*   Updated: 2021/02/25 17:13:03 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "particule_system.h"


/* events.c */

void		input_handler(t_engine *e, t_trans_mat *m);

/* clock.c */

void		clock_handler(t_engine *e);

/* callback.c */

void		key_callback(GLFWwindow *window, int key, int scancode,
    int action, int mods);
void		mouse_callback(GLFWwindow *window, double xpos, double ypos);
void		error_callback(int error, const char *description);

/*
** INIT
*/

/* matrix.c */

void		get_trans_mat(t_trans_mat *m, short new_m);
void		m_print(mat4x4 m, char *name);

/* graphic.c */

int			init_graphic(t_engine *e);

/* shaders.c */

int			init_shader(t_engine *e);

#endif