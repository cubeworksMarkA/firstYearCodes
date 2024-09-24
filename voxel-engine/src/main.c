#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "cglm/cglm.h"

float vertices[] = {
    // front bottom left (0)
    -0.5, -0.5, 0.0,
    // front bottom right (1)
    0.5, -0.5, 0.0,
    // front top left (2)
    -0.5, 0.5, 0.0,
    // front top right (3)
    0.5, 0.5, 0.0,
    // back bottom left (4)
    -0.5, -0.5, 1.0,
    // back bottom right (5)
    0.5, -0.5, 1.0,
    // back top left (6)
    -0.5, 0.5, 1.0,
    // back top right (7)
    0.5, 0.5, 1.0};

unsigned int indices[] = {
    // front
    0, 1, 2,
    2, 1, 3,
    //
    // back
    4, 5, 6,
    6, 5, 7,
    //
    // right
    1, 5, 3,
    3, 5, 7,
    //
    // left
    4, 0, 6,
    6, 0, 2,
    //
    // top
    2, 3, 6,
    6, 3, 7,
    //
    // bottom
    0, 1, 4,
    4, 1, 5,
    //
};

vec3 camera_pos = {0.0f, 0.0f, 3.0f};
vec3 camera_front = {0.0f, 0.0f, -1.0f};
vec3 camera_up = {0.0f, 1.0f, 0.0f};

vec3 cube_pos[] = {
    {0.5f, 0.0f, 0.0f}, {1.0f, 0.0f, 0.0f}, {1.5f, 0.0f, 0.0f}, {2.0f, 0.0f, 0.0f}, {2.5f, 0.0f, 0.0f},
    {0.5f, 0.0f, 1.0f}, {1.0f, 0.0f, 1.0f}, {1.5f, 0.0f, 1.0f}, {2.0f, 0.0f, 1.0f}, {2.5f, 0.0f, 1.0f}, 
    // 
    {0.5f, 0.0f, 2.0f}, {1.0f, 0.0f, 2.0f}, {1.5f, 0.0f, 2.0f}, {2.0f, 0.0f, 2.0f}, {2.5f, 0.0f, 2.0f},
    {0.5f, 0.0f, 3.0f}, {1.0f, 0.0f, 3.0f}, {1.5f, 0.0f, 3.0f}, {2.0f, 0.0f, 3.0f}, {2.5f, 0.0f, 3.0f}, 
    // 
    {0.5f, 0.0f, 4.0f}, {1.0f, 0.0f, 4.0f}, {1.5f, 0.0f, 4.0f}, {2.0f, 0.0f, 4.0f}, {2.5f, 0.0f, 4.0f},
    {0.5f, 0.0f, 5.0f}, {1.0f, 0.0f, 5.0f}, {1.5f, 0.0f, 5.0f}, {2.0f, 0.0f, 5.0f}, {2.5f, 0.0f, 5.0f}, 
    // 
    {0.5f, 0.0f, 6.0f}, {1.0f, 0.0f, 6.0f}, {1.5f, 0.0f, 6.0f}, {2.0f, 0.0f, 6.0f}, {2.5f, 0.0f, 6.0f},
    {0.5f, 0.0f, 7.0f}, {1.0f, 0.0f, 7.0f}, {1.5f, 0.0f, 7.0f}, {2.0f, 0.0f, 7.0f}, {2.5f, 0.0f, 7.0f}, 
    // 
    {0.5f, 0.0f, 8.0f}, {1.0f, 0.0f, 8.0f}, {1.5f, 0.0f, 8.0f}, {2.0f, 0.0f, 8.0f}, {2.5f, 0.0f, 8.0f},
    {0.5f, 0.0f, 9.0f}, {1.0f, 0.0f, 9.0f}, {1.5f, 0.0f, 9.0f}, {2.0f, 0.0f, 9.0f}, {2.5f, 0.0f, 9.0f}, 
    // 
    {0.5f, 0.0f, 10.0f}, {1.0f, 0.0f, 10.0f}, {1.5f, 0.0f, 10.0f}, {2.0f, 0.0f, 10.0f}, {2.5f, 0.0f, 10.0f},
    {0.5f, 0.0f, 11.0f}, {1.0f, 0.0f, 11.0f}, {1.5f, 0.0f, 11.0f}, {2.0f, 0.0f, 11.0f}, {2.5f, 0.0f, 11.0f}, 
    // 
    {0.5f, 0.0f, 12.0f}, {1.0f, 0.0f, 12.0f}, {1.5f, 0.0f, 12.0f}, {2.0f, 0.0f, 12.0f}, {2.5f, 0.0f, 12.0f},
    {0.5f, 0.0f, 13.0f}, {1.0f, 0.0f, 13.0f}, {1.5f, 0.0f, 13.0f}, {2.0f, 0.0f, 13.0f}, {2.5f, 0.0f, 13.0f}, 
    // 
    {0.5f, 0.0f, 14.0f}, {1.0f, 0.0f, 14.0f}, {1.5f, 0.0f, 14.0f}, {2.0f, 0.0f, 14.0f}, {2.5f, 0.0f, 14.0f},
    {0.5f, 0.0f, 15.0f}, {1.0f, 0.0f, 15.0f}, {1.5f, 0.0f, 15.0f}, {2.0f, 0.0f, 15.0f}, {2.5f, 0.0f, 15.0f}, 
    // 
    {0.5f, 0.0f, 16.0f}, {1.0f, 0.0f, 16.0f}, {1.5f, 0.0f, 16.0f}, {2.0f, 0.0f, 16.0f}, {2.5f, 0.0f, 16.0f},
    {0.5f, 0.0f, 17.0f}, {1.0f, 0.0f, 17.0f}, {1.5f, 0.0f, 17.0f}, {2.0f, 0.0f, 17.0f}, {2.5f, 0.0f, 17.0f}, 
    // 
    {0.5f, 0.0f, 18.0f}, {1.0f, 0.0f, 18.0f}, {1.5f, 0.0f, 18.0f}, {2.0f, 0.0f, 18.0f}, {2.5f, 0.0f, 18.0f},
    {0.5f, 0.0f, 19.0f}, {1.0f, 0.0f, 19.0f}, {1.5f, 0.0f, 19.0f}, {2.0f, 0.0f, 19.0f}, {2.5f, 0.0f, 19.0f}, 
};

const int WIDTH = 640, HEIGHT = 480;

float delta_time = 0.0f, last_frame = 0.0f;

float yaw = -90.0f;
float pitch = 0.0f;
float last_x = 400, last_y = 300;
bool first_mouse = true;

char *get_shader_src(char *file_path)
{
    FILE *file = fopen(file_path, "r");
    char *shader_src;
    char inter_var[32];

    if (file == NULL)
    {
        printf("error opening file\n");
        fclose(file);
        exit(-1);
    }

    fseek(file, 0, SEEK_END);
    int file_len = ftell(file);
    fseek(file, 0, SEEK_SET);
    shader_src = (char *)malloc(file_len + 1);
    shader_src[0] = '\0';
    while (fgets(inter_var, 32, file) != NULL)
    {
        strcat(shader_src, inter_var);
    }
    fclose(file);
    return shader_src;
}

unsigned int create_shader(char *shader_src, int shader_type)
{
    unsigned int shader = glCreateShader(shader_type);
    glShaderSource(shader, 1, &shader_src, NULL);
    glCompileShader(shader);
    return shader;
}

void clean(GLFWwindow *window, unsigned int *vao, unsigned int *vbo, char *vertex_shader_src, char *fragment_shader_src)
{
    if (window != NULL)
    {
        glfwDestroyWindow(window);
    }
    if (vao != NULL)
    {
        glDeleteVertexArrays(1, &vao);
    }
    if (vbo != NULL)
    {
        glDeleteBuffers(1, &vbo);
    }
    if (vertex_shader_src != NULL)
    {
        free(vertex_shader_src);
    }
    if (fragment_shader_src != NULL)
    {
        free(fragment_shader_src);
    }
    glfwTerminate();
}

void mouse_callback(GLFWwindow *window, double x_pos, double y_pos)
{
    float x_pos_ = (float)x_pos;
    float y_pos_ = (float)y_pos;
    if (first_mouse)
    {
        last_x = x_pos_;
        last_y = y_pos_;
        first_mouse = false;
    }
    float x_offset = x_pos_ - last_x;
    float y_offset = last_y - y_pos_;
    last_x = x_pos_;
    last_y = y_pos_;

    float sensitity = 0.1f;
    x_offset *= sensitity;
    y_offset *= sensitity;

    yaw += x_offset;
    pitch += y_offset;

    if (pitch > 89.0f)
    {
        pitch = 89.0f;
    }
    if (pitch < -89.0f)
    {
        pitch = -89.0f;
    }
    vec3 direction;
    direction[0] = cos(glm_rad(yaw)) * cos(glm_rad(pitch));
    direction[1] = sin(glm_rad(pitch));
    direction[2] = sin(glm_rad(yaw)) * cos(glm_rad(pitch));
    glm_vec3_norm(direction);
    camera_front[0] = direction[0];
    camera_front[1] = direction[1];
    camera_front[2] = direction[2];
}

static void process_input(GLFWwindow *window)
{
    const float camera_speed = 2.5f * delta_time;
    vec3 intermidiate;
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
    else if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
    {
        glm_vec3_mul(camera_front, (vec3){camera_speed, camera_speed, camera_speed}, intermidiate);
        glm_vec3_add(camera_pos, intermidiate, camera_pos);
    }
    else if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
    {
        glm_vec3_mul(camera_front, (vec3){camera_speed, camera_speed, camera_speed}, intermidiate);
        glm_vec3_sub(camera_pos, intermidiate, camera_pos);
    }
    else if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
    {
        glm_vec3_cross(camera_front, camera_up, intermidiate);
        glm_vec3_norm(intermidiate);
        glm_vec3_mul(intermidiate, (vec3){camera_speed, camera_speed, camera_speed}, intermidiate);
        glm_vec3_sub(camera_pos, intermidiate, camera_pos);
    }
    else if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
    {
        glm_vec3_cross(camera_front, camera_up, intermidiate);
        glm_vec3_norm(intermidiate);
        glm_vec3_mul(intermidiate, (vec3){camera_speed, camera_speed, camera_speed}, intermidiate);
        glm_vec3_add(camera_pos, intermidiate, camera_pos);
    }
}

static void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}

int main()
{
    char *vertex_shader_src = get_shader_src("src/shaders/vertex.glsl");
    char *fragment_shader_src = get_shader_src("src/shaders/fragment.glsl");
    if (!glfwInit())
    {
        printf("error initializing glfw");
        exit(-1);
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    GLFWwindow *window = glfwCreateWindow(WIDTH, HEIGHT, "Hello world", NULL, NULL);
    if (!window)
    {
        printf("error creating window");
        free(vertex_shader_src);
        free(fragment_shader_src);
        clean(NULL, NULL, NULL, NULL, NULL);
        exit(-1);
    }
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetCursorPosCallback(window, mouse_callback);
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwMakeContextCurrent(window);
    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
    glfwSwapInterval(1);
    glEnable(GL_DEPTH_TEST);

    unsigned int vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    unsigned int vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    unsigned int ebo;
    glGenBuffers(1, &ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

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
        float current_frame = glfwGetTime();
        delta_time = current_frame - last_frame;
        last_frame = current_frame;

        process_input(window);

        glClearColor(1, 1, 1, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glUseProgram(shader_program);
        mat4 view = GLM_MAT4_IDENTITY_INIT, projection;
        int view_loc = glGetUniformLocation(shader_program, "view");
        vec3 intermidiate;
        glm_vec3_add(camera_pos, camera_front, intermidiate);
        glm_lookat(camera_pos, intermidiate, camera_up, view);
        glUniformMatrix4fv(view_loc, 1, GL_FALSE, view[0]);
        int projection_loc = glGetUniformLocation(shader_program, "projection");
        glm_perspective_default((float)WIDTH / (float)HEIGHT, projection);
        glUniformMatrix4fv(projection_loc, 1, GL_FALSE, projection[0]);
        glBindVertexArray(vao);
        for (int i = 0; i < 100; i++)
        {
            mat4 model = GLM_MAT4_IDENTITY_INIT;
            int model_loc = glGetUniformLocation(shader_program, "model");
            glm_translate(model, cube_pos[i]);
            glUniformMatrix4fv(model_loc, 1, GL_FALSE, model[0]);
            glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(indices[0]), GL_UNSIGNED_INT, 0);
        }

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    clean(window, vao, vbo, vertex_shader_src, fragment_shader_src);
    return 0;
}