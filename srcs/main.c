/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 16:25:35 by xamartin          #+#    #+#             */
/*   Updated: 2021/02/25 17:11:18 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "tools.h"


int				launch_render(t_engine *e)
{
	GLuint VAO, VBO, IBO, gWorldLocation;
	float vertices[] = {
		0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,
		-0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,
		0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f 
	};

	unsigned int indices[] = {
		0, 3, 1,
		1, 3, 2,
		2, 3, 0,
		0, 1, 2
	};

	t_trans_mat	m;

	get_trans_mat(&m, 1);
	m.scale_info[0] = 0.2;
	m.scale_info[1] = 0.2;
	m.scale_info[2] = 0.2;
	gWorldLocation = glGetUniformLocation(e->shader_program, "gWorld");
	assert(gWorldLocation != 0xFFFFFFFF);

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glGenBuffers(1, &IBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

		e->c.last_time = glfwGetTime();
	while (!glfwWindowShouldClose(e->win))
	{
		glUseProgram(e->shader_program);
		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		m.rotate_info[2] += 0.1f;
		m.rotate_info[1] = tanf(m.rotate_info[2]);
		get_trans_mat(&m, 0);

		glUniformMatrix4fv(gWorldLocation, 1, GL_TRUE, &m.transformation[0][0]);

		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);

		glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_INT, 0);

		glfwSwapBuffers(e->win);
	
		e->c.fps++;
		clock_handler(e);
		input_handler(e, &m);
	}
	glfwTerminate();
	return (1);
}

int				main(int argc, char **argv)
{
	t_engine	e;

	printf("%d - %s\n", argc, argv[0]);
	memset(&e, 0, sizeof(e));
	if (!init_graphic(&e))
		exit(0);
	launch_render(&e);
	return (1);
}
