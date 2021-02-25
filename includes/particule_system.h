/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   particule_system.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 16:26:12 by xamartin          #+#    #+#             */
/*   Updated: 2021/02/25 14:09:16 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARTICULE_SYSTEM_H
# define PARTICULE_SYSTEM_H

/*
** Librairies
*/

# ifdef __APPLE__
#  define GL_SILENCE_DEPRECATION
#  define CL_SILENCE_DEPRECATION
#  include <OpenCL/opencl.h>
# else
#  include <CL/cl.h>
# endif

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <time.h>
# include <assert.h>

# include "../external_lib/glad/include/glad/glad.h"
# include <../external_lib/glfw/include/GLFW/glfw3.h>
# include "../external_lib/glfw/deps/linmath.h"

/*
** Defines
*/

# define PROG_NAME "Particule System"

# define W 1080
# define H 720

# define SHADER_READ 1000

#define ToRadian(x) ((x) * M_PI / 180.0f)
#define ToDegree(x) ((x) * 180.0f / M_PI)

/*
** Custom Headers
*/

# include "render_struct.h"

#endif