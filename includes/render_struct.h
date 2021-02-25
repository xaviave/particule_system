/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 15:12:42 by xamartin          #+#    #+#             */
/*   Updated: 2021/02/25 17:10:10 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#ifndef RENDER_STRUCT_H
# define RENDER_STRUCT_H


typedef struct			s_clock
{
	int					fps;
	double				last_time;
	double				draw_time;
}						t_clock;

typedef struct			s_input_handler
{
	short				camera_lock;
	short				keyboard_lock;
}						t_input_handler;

typedef struct			s_engine
{
	GLFWwindow			*win;
	GLuint				shader_program;
	t_clock				c;
	t_input_handler		i;
}						t_engine;

typedef struct			s_perspective_proj
{
	float				fov;
	float				width;
	float				height;
	float				z_near;
	float				z_far;
}						t_perspective_proj;

typedef struct			s_trans_mat
{
	vec3				scale_info;
	vec3				rotate_info;
	vec3				translate_info;
	vec3				camera_info_up;
	vec3				camera_info_pos;
	vec3				camera_info_target;
	t_perspective_proj	proj_info;

	mat4x4				scale;
	mat4x4				rotate;
	mat4x4				translate;
	mat4x4				camera_pos;
	mat4x4				camera_rotate;
	mat4x4				perspective;
	mat4x4				transformation;
}						t_trans_mat;

#endif