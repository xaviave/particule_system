/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 14:24:14 by xamartin          #+#    #+#             */
/*   Updated: 2021/02/25 10:41:35 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static char			*get_shader(char *name)
{
	FILE			*file;
	char			*buffer;
	unsigned int	file_len;

	if ((file = fopen(name, "r")) == NULL)
		return (NULL);
	
	fseek(file, 0, SEEK_END);
	file_len = ftell(file); 
	rewind(file);
	
	if (!(buffer = (char *)malloc(sizeof(char) * file_len + 1)))
		return (NULL);

	memset(buffer, 0, sizeof(char) * file_len + 1);
	fread(buffer, sizeof(char), file_len, file);
	fclose(file);
	return (buffer);
}

static int			print_shader_error(GLint addr, int opt)
{
	char			info_log[1024];

	if (opt)
		glGetShaderInfoLog(addr, 1024, NULL, info_log);
	else
		glGetProgramInfoLog(addr, 1024, NULL, info_log);
	dprintf(1, "[SHADER_ERROR_HANDLER] %s\n", info_log);
	return (0);
}

static int			init_program(t_engine *e, GLuint vs, GLuint fs)
{
	int				success;

	e->shader_program = glCreateProgram();
	glAttachShader(e->shader_program, vs);
	glAttachShader(e->shader_program, fs);
	glLinkProgram(e->shader_program);
	glGetProgramiv(e->shader_program, GL_LINK_STATUS, &success);
	if (!success)
		return (print_shader_error(e->shader_program, 0));
	return (1);
}

static int			compile_shader(char *shader_name, GLuint shader_type)
{
	GLuint			s;
	const GLchar	*shader;

	if (!(shader = get_shader(shader_name)))
		return (-1);
	s = glCreateShader(shader_type);
	glShaderSource(s, 1, &shader, NULL);
	glCompileShader(s);
	free((void *)shader);
	return (s);
}

int					init_shader(t_engine *e)
{
	GLuint			vs;
	GLuint			fs;
	int				success;

	vs = compile_shader("shaders/vertex_shader", GL_VERTEX_SHADER);
	fs = compile_shader("shaders/fragment_shader", GL_FRAGMENT_SHADER);
	if (!vs || !fs)
		return (0);

	if (!(init_program(e, vs, fs)))
		return (0);
	glGetProgramiv(e->shader_program, GL_LINK_STATUS, &success);
	if (!success)
		return (print_shader_error(e->shader_program, 1));
	glDeleteShader(vs);
	glDeleteShader(fs);
	return (1);
}