#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <random>
#include <vector>


void processInput(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

const unsigned int SCR_WIDTH = 1200;
const unsigned int SCR_HEIGHT = 1200;

const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"layout (location = 1) in vec3 aColor;\n"
"out vec3 ourColor;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos, 1.0);\n"
"   ourColor = aColor;\n"
"}\0";

const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"in vec3 ourColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(ourColor, 1.0f);\n"
"}\n\0";

int main() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Laboratorio 05", NULL, NULL);
    if (window == NULL) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    unsigned int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    float vertices[] = {

        //A  0.0f, 0.66f,0.0f,
        //B -0.16f, 0.22f,0.0f,
        //C -0.66f, 0.2f,0.0f,
        //D -0.26f, -0.12f,0.0f,
        //E -0.4f, -0.57f,0.0f,
        //F 0.0f, -0.28f,0.0f,
        //G 0.4f, -0.57f,0.0f,
        //H 0.27f, -0.12f,0.0f,
        //I 0.64f, 0.19f,0.0f,
        //J 0.2f, 0.2f,0.0f,

        //BCD
        -0.16f, 0.22f,0.0f,     0.0f,0.0f,0.0f,
        -0.66f, 0.2f,0.0f,      0.0f,0.0f,0.0f,
        -0.26f, -0.12f,0.0f,    0.0f,0.0f,0.0f,

        //DEF
        -0.26f, -0.12f,0.0f,    0.0f,0.0f,0.0f,
        -0.4f, -0.57f,0.0f,     0.0f,0.0f,0.0f,
        0.0f, -0.28f,0.0f,      0.0f,0.0f,0.0f,

        //FGH
        0.0f, -0.28f,0.0f,      0.0f,0.0f,0.0f,
        0.4f, -0.57f,0.0f,      0.0f,0.0f,0.0f,
        0.27f, -0.12f,0.0f,     0.0f,0.0f,0.0f,
        //HIJ
         0.27f, -0.12f,0.0f,    0.0f,0.0f,0.0f,
         0.64f, 0.19f,0.0f,     0.0f,0.0f,0.0f,
         0.2f, 0.2f,0.0f,       0.0f,0.0f,0.0f,
        //JAB
        0.2f, 0.2f,0.0f,        0.0f,0.0f,0.0f,
        0.0f, 0.66f,0.0f,       0.0f,0.0f,0.0f,
        -0.16f, 0.22f,0.0f,     0.0f,0.0f,0.0f,

        //BDF
        - 0.16f, 0.22f,0.0f,    0.0f,0.0f,0.0f,
        -0.26f, -0.12f,0.0f,    0.0f,0.0f,0.0f,
        0.0f, -0.28f,0.0f,      0.0f,0.0f,0.0f,

        //FHJ
        0.0f, -0.28f,0.0f,      0.0f,0.0f,0.0f,
        0.27f, -0.12f,0.0f,     0.0f,0.0f,0.0f,
        0.2f, 0.2f,0.0f,        0.0f,0.0f,0.0f,

        //BJF
        0.2f, 0.2f,0.0f,        0.0f,0.0f,0.0f,
        -0.16f, 0.22f,0.0f,     0.0f,0.0f,0.0f,
        0.0f, -0.28f,0.0f,      0.0f,0.0f,0.0f,
    };

    //COLOR OF THE LINES



    int numTriangles = 30;

    unsigned int VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glUseProgram(shaderProgram);

    while (!glfwWindowShouldClose(window)) {
        processInput(window);

        glClearColor(1.0f, 0.9f, 1.0f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, numTriangles * 3);



        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteProgram(shaderProgram);

    glfwTerminate();
    return 0;
}