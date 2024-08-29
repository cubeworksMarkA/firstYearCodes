#include <stdio.h>
#include <stdlib.h>
#include "glad/glad.h"
#include "GLFW/glfw3.h"

float vertices[] = {
    -0.5, -0.5, 0.0,
    0.5, -0.5, 0.0,
    -0.5, 0.5, 0.0,
    -0.5, -0.5, 0.0,
    0.5, -0.5, 0.0,
    -0.5, 0.5, 0.0,
};

const char *vertex_shader_src = "#version 330 core\n"
                                "layout (location = 0) in vec3 point;\n"
                                "void main() {\n"
                                "   gl_Position = vec4(point, 1.0);\n"
                                "}\n"
                                "\0";

const char *fragment_shader_src = "#version 330 core\n"
                                  "out vec4 point_color;\n"
                                  "void main() {\n"
                                  "   point_color = vec4(0.5, 0.0, 1.0, 1.0);\n"
                                  "}\n"
                                  "\0";

unsigned int create_shader(char *shader_src, int shader_type)
{
    unsigned int shader = glCreateShader(shader_type);
    glShaderSource(shader, 1, &shader_src, NULL);
    glCompileShader(shader);
    return shader;
}

void clean(GLFWwindow *window)
{
    if (window != NULL)
    {
        glfwDestroyWindow(window);
    }
    glfwTerminate();
}

static void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}

static void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}

int main()
{
    if (!glfwInit())
    {
        puts("error initializing glfw");
        return -1;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    GLFWwindow *window = glfwCreateWindow(640, 480, "Hello world", NULL, NULL);
    if (!window)
    {
        puts("error creating window");
        clean(NULL);
        return -1;
    }

    glfwSetKeyCallback(window, key_callback);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    glfwMakeContextCurrent(window);
    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
    glfwSwapInterval(1);

    unsigned int vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    unsigned int vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), NULL);
    glEnableVertexAttribArray(0);

    unsigned int vertex_shader = create_shader(vertex_shader_src, GL_VERTEX_SHADER);
    unsigned int fragment_shader = create_shader(fragment_shader_src, GL_FRAGMENT_SHADER);
    unsigned int shader_program = glCreateProgram();
    glAttachShader(shader_program, vertex_shader);
    glAttachShader(shader_program, fragment_shader);
    glLinkProgram(shader_program);
    glDeleteShader(vertex_shader);
    glDeleteShader(fragment_shader);

    while (!glfwWindowShouldClose(window))
    {
        glClearColor(1, 1, 1, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shader_program);
        glBindVertexArray(vao);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    clean(window);
    return 0;
}