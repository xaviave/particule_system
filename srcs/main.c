/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 16:25:35 by xamartin          #+#    #+#             */
/*   Updated: 2021/02/25 11:25:51 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "tools.h"


void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

int				launch_render(t_engine *e)
{
	float		scale = 0.0f;
    GLuint VAO, VBO, gWorldLocation;
	float vertices[] = {
         0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,
        -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,
         0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f 
    };
	
	mat4x4 world;

	mat4x4_identity(world);
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

	glUseProgram(e->shader_program);

	while (!glfwWindowShouldClose(e->win))
	{
		scale += 0.01;
		mat4x4_translate_in_place(world, sinf(scale) - cosf(scale), sinf(scale) + cosf(scale), 0);
		mat4x4_rotate(world, world, 0, 1, 0, tanf(scale));
		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

 		glUniformMatrix4fv(gWorldLocation, 1, GL_TRUE, &world[0][0]);

		glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);

    	glfwSwapBuffers(e->win);
		glfwPollEvents();
		processInput(e->win);
	}
	glfwTerminate();
	return (1);
}

int				main(int argc, char **argv)
{
	t_engine	e;

    printf("%d - %s\n", argc, argv[0]);
	if (!init_graphic(&e))
	{
		
		exit(0);
	}
	launch_render(&e);
	return (1);
}
