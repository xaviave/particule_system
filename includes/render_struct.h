/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 15:12:42 by xamartin          #+#    #+#             */
/*   Updated: 2021/02/24 14:29:32 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#ifndef RENDER_STRUCT_H
# define RENDER_STRUCT_H


typedef struct				s_engine
{
	GLFWwindow				*win;
	GLuint					shader_program;
}							t_engine;

#endif