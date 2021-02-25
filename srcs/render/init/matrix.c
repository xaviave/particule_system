/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 12:11:10 by xamartin          #+#    #+#             */
/*   Updated: 2021/02/25 16:42:42 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static void	init_proj_vec(t_perspective_proj *p)
{
	p->fov = 30.0f;
	p->width = W;
	p->height = H;
	p->z_near = 1.0f;
	p->z_far = 100.f;
}

static void	init_vec(t_trans_mat *m)
{
	m->scale_info[0] = 1.0f;
	m->scale_info[1] = 1.0f;
	m->scale_info[2] = 1.0f;

	m->rotate_info[0] = 0.0f;
	m->rotate_info[1] = 0.0f;
	m->rotate_info[2] = 0.0f;
	
	m->translate_info[0] = 0.0f;
	m->translate_info[1] = 0.0f;
	m->translate_info[2] = 5.0f;
	
	m->camera_info_up[0] = 0.0f;
	m->camera_info_up[1] = 1.0f;
	m->camera_info_up[2] = 0.0f;
	
	m->camera_info_pos[0] = 0.0f;
	m->camera_info_pos[1] = 0.0f;
	m->camera_info_pos[2] = -3.0f;
	
	m->camera_info_target[0] = 0.0f;
	m->camera_info_target[1] = 0.0f;
	m->camera_info_target[2] = 2.0f;
	
	init_proj_vec(&m->proj_info);
}

static void	init_scale(t_trans_mat *m)
{
	mat4x4_identity(m->scale);
	m->scale[0][0] = m->scale_info[0];
	m->scale[1][1] = m->scale_info[1];
	m->scale[2][2] = m->scale_info[2];
}

static void	init_rotate(t_trans_mat *m)
{
	mat4x4	rx, ry, rz;

	mat4x4_identity(m->rotate);
	mat4x4_rotate_X(rx, m->rotate, m->rotate_info[0]);
	mat4x4_rotate_Y(ry, m->rotate, m->rotate_info[1]);
	mat4x4_rotate_Z(rz, m->rotate, m->rotate_info[2]);
	mat4x4_mul(m->rotate, rx, ry);
	mat4x4_mul(m->rotate, m->rotate, rz);
}

static void	init_translate(t_trans_mat *m)
{
	mat4x4_identity(m->translate);
	m->translate[0][3] = m->translate_info[0];
	m->translate[1][3] = m->translate_info[1];
	m->translate[2][3] = m->translate_info[2];
}

static void	init_perspective(t_trans_mat *m)
{
	float	t_fov;
	
	t_fov = tanf(ToRadian(m->proj_info.fov / 2.0f));
	memset(m->perspective, 0.0f, sizeof(mat4x4));
    m->perspective[0][0] = 1.0f / (t_fov * (m->proj_info.width / m->proj_info.height));
	m->perspective[1][1] = 1.0f / t_fov;
	m->perspective[2][2] = (-m->proj_info.z_near - m->proj_info.z_far) / (m->proj_info.z_near - m->proj_info.z_far);
	m->perspective[2][3] = (2.0f * m->proj_info.z_near * m->proj_info.z_far) / (m->proj_info.z_near - m->proj_info.z_far);
	m->perspective[3][2] = 1.0f;
}

static void	init_camera_translate(t_trans_mat *m)
{
	mat4x4_identity(m->camera_pos);
	m->camera_pos[0][3] = m->camera_info_pos[0];
	m->camera_pos[1][3] = m->camera_info_pos[1];
	m->camera_pos[2][3] = m->camera_info_pos[2];
}

static void	init_camera_rotate(t_trans_mat *m)
{
	vec3	t, u, v;

	mat4x4_identity(m->camera_rotate);
	vec3_norm(t, m->camera_info_target);
	vec3_norm(u, m->camera_info_up);
	vec3_mul_cross(u, u, t);
	vec3_mul_cross(v, t, u);
    m->camera_rotate[0][0] = u[0];
	m->camera_rotate[0][1] = u[1];
	m->camera_rotate[0][2] = u[2];
    m->camera_rotate[1][0] = v[0];
	m->camera_rotate[1][1] = v[1];
	m->camera_rotate[1][2] = v[2];
    m->camera_rotate[2][0] = t[0];
	m->camera_rotate[2][1] = t[1];
	m->camera_rotate[2][2] = t[2];
}

static void	init_transformation(t_trans_mat *m)
{
	mat4x4	tmp, tmp2;
	
	mat4x4_mul(tmp, m->scale, m->rotate);
	mat4x4_mul(tmp2, tmp, m->translate);
	mat4x4_mul(tmp, tmp2, m->camera_pos);
	mat4x4_mul(tmp2, tmp, m->camera_rotate);
	mat4x4_mul(m->transformation, tmp2, m->perspective);
}

void		m_print(mat4x4 m, char *name)
{
	dprintf(1, "\n==============================================\n\tmat4x4: %s\n", name);
	for(int i = 0; i < 4; i = i + 1)
	{
		for(int j = 0; j < 4; j = j + 1)
			dprintf(1, "| %f ", m[i][j]);
		dprintf(1, "|\n");
	}
	dprintf(1, "==============================================\n");
}

void		get_trans_mat(t_trans_mat *m, short new_m)
{
	if (new_m)
		init_vec(m);
	init_scale(m);
	init_rotate(m);
	init_translate(m);
	init_perspective(m);
	init_camera_translate(m);
	init_camera_rotate(m);
	init_transformation(m);
}
