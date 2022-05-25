#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <string>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

const char* vertexShaderCreator()
{
    const char* vertexShader = "#version 330 core\n"
        "layout (location = 0) in vec3 aPos;\n"
        "void main()\n"
        "{\n"
        "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
        "}\0";
    return vertexShader;
}

const char* fragmentShaderCreator(float R, float G, float B)
{
    // concat float to const char
	std::string temp = "#version 330 core\n"
		"out vec4 FragColor;\n"
		"void main()\n"
		"{\n"		
		"   FragColor = vec4(" + std::to_string(R) + "f, " + std::to_string(G) + "f, " + std::to_string(B) + "f, 1.0f);\n"
		"}\0";
	const char* fragmentShader = new char[temp.length() + 1];
	strcpy(const_cast<char*>(fragmentShader), temp.c_str());
	return fragmentShader;
}

const char* vertexShaderSource = vertexShaderCreator();
const char* fragmentShaderSource = fragmentShaderCreator(0.0f, 0.0f, 0.32f);


void prepare_shader(unsigned int &vertexShader, unsigned int &fragmentShader, const char* &vertexShaderSource, const char* &fragmentShaderSource,  unsigned int &shaderProgram)
{
    // vertex shader	
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    // check for shader compile errors
    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
	
    // fragment shader
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
    // check for shader compile errors
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }


    // link shaders
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    // check for linking errors
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}



void prepare_VB0_VAO_triangle(unsigned int& VBO, unsigned int& VAO, float vertices[], int size_of_vertices)
{
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glBufferData(GL_ARRAY_BUFFER, size_of_vertices, vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
    // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
    glBindVertexArray(0);
}



void prepare_VB0_VAO_line(unsigned int& VBO, unsigned int& VAO, float vertices[], int size_of_vertices)
{
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glBufferData(GL_ARRAY_BUFFER, size_of_vertices, vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
    // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
    glBindVertexArray(0);
}

void get_rectangle_coords(float x1, float y1, float x2, float y2, float* vertices1, float* vertices2)
{
	vertices1[0] = x1; 	vertices1[1] = y1; 	vertices1[2] = 0.0f;
	vertices1[3] = x2; 	vertices1[4] = y1; 	vertices1[5] = 0.0f;
    vertices1[6] = x1; 	vertices1[7] = y2; 	vertices1[8] = 0.0f;

	
	vertices2[0] = x1; 	vertices2[1] = y2; 	vertices2[2] = 0.0f;
	vertices2[3] = x2; 	vertices2[4] = y2; 	vertices2[5] = 0.0f;
	vertices2[6] = x2; 	vertices2[7] = y1; 	vertices2[8] = 0.0f;
}

void draw_triangle(unsigned int& shaderProgram, unsigned int& VAO)
{
    // draw our first triangle
    glUseProgram(shaderProgram);
    glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
    glDrawArrays(GL_TRIANGLES, 0, 3);
    // glBindVertexArray(0); // no need to unbind it every time 
}

void draw_line(unsigned int& shaderProgram, unsigned int& VAO)
{
	// draw our first triangle
	glUseProgram(shaderProgram);
	glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
	glDrawArrays(GL_LINES, 0, 2);
	// glBindVertexArray(0); // no need to unbind it every time 
}

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
    unsigned int vertexShader, fragmentShader, shaderProgram;
    prepare_shader(vertexShader, fragmentShader, vertexShaderSource, fragmentShaderSource, shaderProgram);

    

    // set up vertex data (and buffer(s)) and configure vertex attributes
    // ------------------------------------------------------------------
    float vertices[]  = { 0.0f,  0.8f, 0.4f, -0.69f};
	float vertices1[] = { 0.4f, -0.69f, -0.69f, 0.4f };
	float vertices2[] = { -0.69f, 0.4f, 0.8f, 0.0f };
	float vertices3[] = { 0.8f, 0.0f, -0.69f, -0.4f };
	float vertices4[] = { -0.69f, -0.4f, 0.4f, 0.69f };
	float vertices5[] = { 0.4f, 0.69f, 0.0f, -0.8f };
	float vertices6[] = { 0.0f, -0.8f, -0.4f, 0.69f };
	float vertices7[] = { -0.4f, 0.69f, 0.69f, -0.4f };
	float vertices8[] = { 0.69f, -0.4f, -0.8f, 0.0f };
	float vertices9[] = { -0.8f, 0.0f, 0.69f, 0.4f };
	float vertices10[] = { 0.69f, 0.4f, -0.4f, -0.69f };
	float vertices11[] = { -0.4f, -0.69f, 0.0f, 0.8f };
	
	
    unsigned int VBO, VAO, VBO1, VAO1, VBO2, VAO2, VBO3, VAO3, VBO4, VAO4, VBO5, VAO5, VBO6, VAO6, VBO7, VAO7, VBO8, VAO8, VBO9, VAO9, VBO10, VAO10, VBO11, VAO11;
    prepare_VB0_VAO_line(VBO, VAO, vertices, sizeof(vertices));
    prepare_VB0_VAO_line(VBO1, VAO1, vertices1, sizeof(vertices1));
    prepare_VB0_VAO_line(VBO2, VAO2, vertices2, sizeof(vertices2));
    prepare_VB0_VAO_line(VBO3, VAO3, vertices3, sizeof(vertices3));
	prepare_VB0_VAO_line(VBO4, VAO4, vertices4, sizeof(vertices4));
	prepare_VB0_VAO_line(VBO5, VAO5, vertices5, sizeof(vertices5));
	prepare_VB0_VAO_line(VBO6, VAO6, vertices6, sizeof(vertices6));
	prepare_VB0_VAO_line(VBO7, VAO7, vertices7, sizeof(vertices7));
	prepare_VB0_VAO_line(VBO8, VAO8, vertices8, sizeof(vertices8));
	prepare_VB0_VAO_line(VBO9, VAO9, vertices9, sizeof(vertices9));
	prepare_VB0_VAO_line(VBO10, VAO10, vertices10, sizeof(vertices10));
	prepare_VB0_VAO_line(VBO11, VAO11, vertices11, sizeof(vertices11));
	
	unsigned int VBO_triangle, VAO_triangle;
	prepare_VB0_VAO_triangle(VBO_triangle, VAO_triangle, vertices, sizeof(vertices));

	

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
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        //draw_triangle(shaderProgram, VAO);
        //draw_triangle(shaderProgram, VAO1);
        draw_line(shaderProgram, VAO);
        //draw_line(shaderProgram, VAO1);
        //draw_line(shaderProgram, VAO2);
        //draw_line(shaderProgram, VAO3);
        //draw_line(shaderProgram, VAO4);
        //draw_line(shaderProgram, VAO5);
        //draw_line(shaderProgram, VAO6);
        //draw_line(shaderProgram, VAO7);
        ////draw_line(shaderProgram, VAO8);
        //draw_line(shaderProgram, VAO9);
        //draw_line(shaderProgram, VAO10);
        //draw_line(shaderProgram, VAO11);
		

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // optional: de-allocate all resources once they've outlived their purpose:
    // ------------------------------------------------------------------------
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
	
	glDeleteVertexArrays(1, &VAO1);
	glDeleteBuffers(1, &VBO1);

	glDeleteVertexArrays(1, &VAO2);
	glDeleteBuffers(1, &VBO2);
	
	glDeleteVertexArrays(1, &VAO3);
	glDeleteBuffers(1, &VBO3);

	glDeleteVertexArrays(1, &VAO4);
	glDeleteBuffers(1, &VBO4);
	
	glDeleteVertexArrays(1, &VAO5);
	glDeleteBuffers(1, &VBO5);
	
	glDeleteVertexArrays(1, &VAO6);
	glDeleteBuffers(1, &VBO6);

	glDeleteVertexArrays(1, &VAO7);
	glDeleteBuffers(1, &VBO7);

	glDeleteVertexArrays(1, &VAO8);
	glDeleteBuffers(1, &VBO8);

	glDeleteVertexArrays(1, &VAO9);
	glDeleteBuffers(1, &VBO9);
	
	glDeleteVertexArrays(1, &VAO10);
	glDeleteBuffers(1, &VBO10);
	
	glDeleteVertexArrays(1, &VAO11);
	glDeleteBuffers(1, &VBO11);
	
    glDeleteProgram(shaderProgram);
	
    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
	
    //  free memory
    delete fragmentShaderSource;
	
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