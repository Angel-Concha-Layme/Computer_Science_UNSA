#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";
const char* fragmentShader1Source = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(1.0f, 0.0f, 0.0f, 1.0f);\n"
"}\n\0";
const char* fragmentShader2Source = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(0.0f, 0.0f, 1.0f, 1.0f);\n"
"}\n\0";
const char* fragmentShader3Source = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(0.0f, 1.0f, 0.0f, 1.0f);\n"
"}\n\0";

const char* fragmentShader4Source = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(0.5f, 0.0f, 0.5f, 1.0f);\n"
"}\n\0";

const char* fragmentShader5Source = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(1.0f, 1.0f, 0.0f, 1.0f);\n"
"}\n\0";

const char* fragmentShader6SourceFondo = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(0.7f, 0.7f, 0.7f, 1.0f);\n"
"}\n\0";

const char* fragmentShader7SourceFondo = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(0.5f, 1.0f, 0.2f, 1.0f);\n"
"}\n\0";

const char* fragmentShader8SourceFondo = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(1.5f, 1.0f, 0.8f, 1.0f);\n"
"}\n\0";

const char* fragmentShader9SourceFondo = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(0.5f, 1.5f, 1.5f, 1.0f);\n"
"}\n\0";

const char* fragmentShader10SourceFondo = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(0.0f, 1.5f, 0.5f, 1.0f);\n"
"}\n\0";

const char* fragmentShader11SourceFondo = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(1.0f, 0.8f, 1.0f, 1.0f);\n"
"}\n\0";

const char* fragmentShader12SourceFondo = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(1.5f, 0.5f, 0.0f, 1.0f);\n"
"}\n\0";


int main()
{
    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // glfw window creation
    // --------------------
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }


    // build and compile our shader program
    // ------------------------------------
    // we skipped compile log checks this time for readability (if you do encounter issues, add the compile-checks! see previous code samples)
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    unsigned int fragmentShaderOrange = glCreateShader(GL_FRAGMENT_SHADER); 
    unsigned int fragmentShaderYellow = glCreateShader(GL_FRAGMENT_SHADER); 
    unsigned int fragmentShaderCeleste = glCreateShader(GL_FRAGMENT_SHADER);
    unsigned int fragmentShaderCeleste2 = glCreateShader(GL_FRAGMENT_SHADER);
    unsigned int fragmentShaderNew = glCreateShader(GL_FRAGMENT_SHADER);
    unsigned int fragmentShaderFondo1 = glCreateShader(GL_FRAGMENT_SHADER);
    unsigned int fragmentShaderFondo2 = glCreateShader(GL_FRAGMENT_SHADER);
    unsigned int fragmentShaderFondo3 = glCreateShader(GL_FRAGMENT_SHADER);
    unsigned int fragmentShaderFondo4 = glCreateShader(GL_FRAGMENT_SHADER);
    unsigned int fragmentShaderFondo5 = glCreateShader(GL_FRAGMENT_SHADER);
    unsigned int fragmentShaderFondo6 = glCreateShader(GL_FRAGMENT_SHADER);
    unsigned int fragmentShaderFondo7 = glCreateShader(GL_FRAGMENT_SHADER);

    unsigned int shaderProgramOrange = glCreateProgram();
    unsigned int shaderProgramYellow = glCreateProgram();
    unsigned int shaderProgramCeleste = glCreateProgram();
    unsigned int shaderProgramCeleste2 = glCreateProgram();
    unsigned int shaderProgramNew = glCreateProgram();
    unsigned int shaderProgramFondo1 = glCreateProgram();
    unsigned int shaderProgramFondo2 = glCreateProgram();
    unsigned int shaderProgramFondo3 = glCreateProgram();
    unsigned int shaderProgramFondo4 = glCreateProgram();
    unsigned int shaderProgramFondo5 = glCreateProgram();
    unsigned int shaderProgramFondo6 = glCreateProgram();
    unsigned int shaderProgramFondo7 = glCreateProgram();

    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    glShaderSource(fragmentShaderOrange, 1, &fragmentShader1Source, NULL);
    glCompileShader(fragmentShaderOrange);
    glShaderSource(fragmentShaderYellow, 1, &fragmentShader2Source, NULL);
    glCompileShader(fragmentShaderYellow);
    glShaderSource(fragmentShaderCeleste, 1, &fragmentShader3Source, NULL);
    glCompileShader(fragmentShaderCeleste);
    glShaderSource(fragmentShaderCeleste2, 1, &fragmentShader4Source, NULL);
    glCompileShader(fragmentShaderCeleste2);
    glShaderSource(fragmentShaderNew, 1, &fragmentShader5Source, NULL);
    glCompileShader(fragmentShaderNew);
    glShaderSource(fragmentShaderFondo1, 1, &fragmentShader6SourceFondo, NULL);
    glCompileShader(fragmentShaderFondo1);
    glShaderSource(fragmentShaderFondo2, 1, &fragmentShader7SourceFondo, NULL);
    glCompileShader(fragmentShaderFondo2);
    glShaderSource(fragmentShaderFondo3, 1, &fragmentShader8SourceFondo, NULL);
    glCompileShader(fragmentShaderFondo3);
    glShaderSource(fragmentShaderFondo4, 1, &fragmentShader9SourceFondo, NULL);
    glCompileShader(fragmentShaderFondo4);
    glShaderSource(fragmentShaderFondo5, 1, &fragmentShader10SourceFondo, NULL);
    glCompileShader(fragmentShaderFondo5);
    glShaderSource(fragmentShaderFondo6, 1, &fragmentShader11SourceFondo, NULL);
    glCompileShader(fragmentShaderFondo6);
    glShaderSource(fragmentShaderFondo7, 1, &fragmentShader12SourceFondo, NULL);
    glCompileShader(fragmentShaderFondo7);

    // link the first program object
    glAttachShader(shaderProgramOrange, vertexShader);
    glAttachShader(shaderProgramOrange, fragmentShaderOrange);
    glLinkProgram(shaderProgramOrange);

    glAttachShader(shaderProgramYellow, vertexShader);
    glAttachShader(shaderProgramYellow, fragmentShaderYellow);
    glLinkProgram(shaderProgramYellow);

    glAttachShader(shaderProgramCeleste, vertexShader);
    glAttachShader(shaderProgramCeleste, fragmentShaderCeleste);
    glLinkProgram(shaderProgramCeleste);

    glAttachShader(shaderProgramCeleste2, vertexShader);
    glAttachShader(shaderProgramCeleste2, fragmentShaderCeleste2);
    glLinkProgram(shaderProgramCeleste2);

    glAttachShader(shaderProgramNew, vertexShader);
    glAttachShader(shaderProgramNew, fragmentShaderNew);
    glLinkProgram(shaderProgramNew);

    glAttachShader(shaderProgramFondo1, vertexShader);
    glAttachShader(shaderProgramFondo1, fragmentShaderFondo1);
    glLinkProgram(shaderProgramFondo1);

    glAttachShader(shaderProgramFondo2, vertexShader);
    glAttachShader(shaderProgramFondo2, fragmentShaderFondo2);
    glLinkProgram(shaderProgramFondo2);

    glAttachShader(shaderProgramFondo3, vertexShader);
    glAttachShader(shaderProgramFondo3, fragmentShaderFondo3);
    glLinkProgram(shaderProgramFondo3);

    glAttachShader(shaderProgramFondo4, vertexShader);
    glAttachShader(shaderProgramFondo4, fragmentShaderFondo4);
    glLinkProgram(shaderProgramFondo4);

    glAttachShader(shaderProgramFondo5, vertexShader);
    glAttachShader(shaderProgramFondo5, fragmentShaderFondo5);
    glLinkProgram(shaderProgramFondo5);

    glAttachShader(shaderProgramFondo6, vertexShader);
    glAttachShader(shaderProgramFondo6, fragmentShaderFondo6);
    glLinkProgram(shaderProgramFondo6);

    glAttachShader(shaderProgramFondo7, vertexShader);
    glAttachShader(shaderProgramFondo7, fragmentShaderFondo7);
    glLinkProgram(shaderProgramFondo7);

    // set up vertex data (and buffer(s)) and configure vertex attributes
    // ------------------------------------------------------------------

    float firstTriangle[] = {
        -0.5f, 0.4f, 0.0f,  // left 
        -0.05f, 0.4f, 0.0f,  // right
        -0.5f, 0.75f, 0.0f,  // top 
    };
    float secondTriangle[] = {
        0.05f, 0.4f, 0.0f,  // left
        0.5f, 0.4f, 0.0f,  // right
        0.5f, 0.75f, 0.0f   // top 
    };
    float thirdTriangle[] = {
        -0.5f, 0.4f, 0.0f,  // left top
        0.5f, 0.4f, 0.0f,  // right
        -0.53f, 0.0f, 0.0f   // left bottom
    };

    float fourthTriangle[] = {
        -0.53f, 0.0f, 0.0f,  // left
        0.5f, 0.4f, 0.0f,  // right top
        0.53f, 0.0f, 0.0f   // right bottom
    };

    float fifthTriangle[] = {
        -0.53f, 0.0f, 0.0f, 
        0.53f, 0.0f, 0.0f, 
        0.0f, -0.5f, 0.0f  
    };

    float fondoTriangle1[] = {
        -1.0f, -1.0f, 0.0f, 
        -1.0f, 1.0f, 0.0f,  
        1.0f, 1.0f, 0.0f,  
    };

    float fondoTriangle2[] = {
        -1.0f, -1.0f, 0.0f,  
        1.0f, -1.0f, 0.0f, 
        0.0f, 0.0f, 0.0f, 
    };

    float fondoTriangle3[] = {
        -1.0f, 1.0f, 0.0f,
        1.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f,
    };

    float fondoTriangle4[] = {
        1.0f, 0.5f, 0.0f,
        1.0f, -0.5f, 0.0f,
        0.0f, 0.0f, 0.0f,
    };

    float fondoTriangle5[] = {
        -0.5f, 1.0f, 0.0f,
        0.5f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f,
    };

    float fondoTriangle6[] = {
        -1.0f, 0.5f, 0.0f,
        -1.0f, -0.5f, 0.0f,
        0.0f, 0.0f, 0.0f,
    };

    float fondoTriangle7[] = {
    0.5f, -1.0f, 0.0f,
    -0.5f, -1.0f, 0.0f,
    0.0f, 0.0f, 0.0f,
    };

    unsigned int VBOs[12], VAOs[12];
    glGenVertexArrays(12, VAOs); //buffers
    glGenBuffers(12, VBOs);


    // first triangle setup
    // --------------------
    glBindVertexArray(VAOs[0]);	// note that we bind to a different VAO now
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[0]);	// and a different VBO
    glBufferData(GL_ARRAY_BUFFER, sizeof(fondoTriangle1), fondoTriangle1, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0); // because the vertex data is tightly packed we can also specify 0 as the vertex attribute's stride to let OpenGL figure it out
    glEnableVertexAttribArray(0);

    glBindVertexArray(VAOs[1]);	// note that we bind to a different VAO now
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[1]);	// and a different VBO
    glBufferData(GL_ARRAY_BUFFER, sizeof(fondoTriangle2), fondoTriangle2, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0); // because the vertex data is tightly packed we can also specify 0 as the vertex attribute's stride to let OpenGL figure it out
    glEnableVertexAttribArray(0);

    glBindVertexArray(VAOs[2]);	// note that we bind to a different VAO now
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[2]);	// and a different VBO
    glBufferData(GL_ARRAY_BUFFER, sizeof(fondoTriangle3), fondoTriangle3, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0); // because the vertex data is tightly packed we can also specify 0 as the vertex attribute's stride to let OpenGL figure it out
    glEnableVertexAttribArray(0);

    glBindVertexArray(VAOs[3]);	// note that we bind to a different VAO now
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[3]);	// and a different VBO
    glBufferData(GL_ARRAY_BUFFER, sizeof(fondoTriangle4), fondoTriangle4, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0); // because the vertex data is tightly packed we can also specify 0 as the vertex attribute's stride to let OpenGL figure it out
    glEnableVertexAttribArray(0);

    glBindVertexArray(VAOs[4]);	// note that we bind to a different VAO now
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[4]);	// and a different VBO
    glBufferData(GL_ARRAY_BUFFER, sizeof(fondoTriangle5), fondoTriangle5, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0); // because the vertex data is tightly packed we can also specify 0 as the vertex attribute's stride to let OpenGL figure it out
    glEnableVertexAttribArray(0);

    glBindVertexArray(VAOs[5]);	// note that we bind to a different VAO now
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[5]);	// and a different VBO
    glBufferData(GL_ARRAY_BUFFER, sizeof(fondoTriangle6), fondoTriangle6, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0); // because the vertex data is tightly packed we can also specify 0 as the vertex attribute's stride to let OpenGL figure it out
    glEnableVertexAttribArray(0);

    glBindVertexArray(VAOs[6]);	// note that we bind to a different VAO now
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[6]);	// and a different VBO
    glBufferData(GL_ARRAY_BUFFER, sizeof(fondoTriangle7), fondoTriangle7, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0); // because the vertex data is tightly packed we can also specify 0 as the vertex attribute's stride to let OpenGL figure it out
    glEnableVertexAttribArray(0);


    glBindVertexArray(VAOs[7]);
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[7]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(firstTriangle), firstTriangle, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);	// Vertex attributes stay the same
    glEnableVertexAttribArray(0);

    glBindVertexArray(VAOs[8]);	// note that we bind to a different VAO now
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[8]);	// and a different VBO
    glBufferData(GL_ARRAY_BUFFER, sizeof(secondTriangle), secondTriangle, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0); // because the vertex data is tightly packed we can also specify 0 as the vertex attribute's stride to let OpenGL figure it out
    glEnableVertexAttribArray(0);
    // glBindVertexArray(0); // not really necessary as well, but beware of calls that could affect VAOs while this one is bound (like binding element buffer objects, or enabling/disabling vertex attributes)


    glBindVertexArray(VAOs[9]);	// note that we bind to a different VAO now
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[9]);	// and a different VBO
    glBufferData(GL_ARRAY_BUFFER, sizeof(thirdTriangle), thirdTriangle, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0); // because the vertex data is tightly packed we can also specify 0 as the vertex attribute's stride to let OpenGL figure it out
    glEnableVertexAttribArray(0);

    glBindVertexArray(VAOs[10]);	// note that we bind to a different VAO now
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[10]);	// and a different VBO
    glBufferData(GL_ARRAY_BUFFER, sizeof(fourthTriangle), fourthTriangle, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0); // because the vertex data is tightly packed we can also specify 0 as the vertex attribute's stride to let OpenGL figure it out
    glEnableVertexAttribArray(0);

    glBindVertexArray(VAOs[11]);	// note that we bind to a different VAO now
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[11]);	// and a different VBO
    glBufferData(GL_ARRAY_BUFFER, sizeof(fifthTriangle), fifthTriangle, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0); // because the vertex data is tightly packed we can also specify 0 as the vertex attribute's stride to let OpenGL figure it out
    glEnableVertexAttribArray(0);

    // uncomment this call to draw in wireframe polygons.
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    // render loop
    // -----------
    while (!glfwWindowShouldClose(window))
    {
        // input
        // -----
        processInput(window);

        // render
        // ------
        glClearColor(0.9f, 0.7f, 0.4f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);


        glUseProgram(shaderProgramFondo1);
        glBindVertexArray(VAOs[0]);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glUseProgram(shaderProgramFondo2);
        glBindVertexArray(VAOs[1]);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glUseProgram(shaderProgramFondo3);
        glBindVertexArray(VAOs[2]);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glUseProgram(shaderProgramFondo4);
        glBindVertexArray(VAOs[3]);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glUseProgram(shaderProgramFondo5);
        glBindVertexArray(VAOs[4]);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glUseProgram(shaderProgramFondo6);
        glBindVertexArray(VAOs[5]);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glUseProgram(shaderProgramFondo7);
        glBindVertexArray(VAOs[6]);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        // now when we draw the triangle we first use the vertex and orange fragment shader from the first program
        glUseProgram(shaderProgramOrange);
        // draw the first triangle using the data from our first VAO
        glBindVertexArray(VAOs[7]);
        glDrawArrays(GL_TRIANGLES, 0, 3);	

        glUseProgram(shaderProgramYellow);
        glBindVertexArray(VAOs[8]);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glUseProgram(shaderProgramCeleste);
        glBindVertexArray(VAOs[9]);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glUseProgram(shaderProgramCeleste2);
        glBindVertexArray(VAOs[10]);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glUseProgram(shaderProgramNew);
        glBindVertexArray(VAOs[11]);
        glDrawArrays(GL_TRIANGLES, 0, 3);


        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // optional: de-allocate all resources once they've outlived their purpose:
    // ------------------------------------------------------------------------
    glDeleteVertexArrays(12, VAOs);
    glDeleteBuffers(12, VBOs);
    glDeleteProgram(shaderProgramOrange);
    glDeleteProgram(shaderProgramYellow);
    glDeleteProgram(shaderProgramCeleste);
    glDeleteProgram(shaderProgramCeleste2);
    glDeleteProgram(shaderProgramNew);
    glDeleteProgram(shaderProgramFondo1);
    glDeleteProgram(shaderProgramFondo2);
    glDeleteProgram(shaderProgramFondo3);
    glDeleteProgram(shaderProgramFondo4);
    glDeleteProgram(shaderProgramFondo5);
    glDeleteProgram(shaderProgramFondo6);
    glDeleteProgram(shaderProgramFondo7);

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
    return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}
