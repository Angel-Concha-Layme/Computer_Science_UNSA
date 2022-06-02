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
                  
		//CDE 
            -0.71f, 0.08f, 0.0f,    0.0f,1.0f,0.0f, //C 
            -0.75f, -0.05f, 0.0f,   0.0f,1.0f,0.0f, //D
            -0.67f, -0.03f, 0.0f,   0.0f,1.0f,0.0f, //E		
        
        //DEM
            -0.75f, -0.05f, 0.0f,   0.0f,0.0f,1.0f, //D
            -0.39f,-0.22f, 0.0f,    0.0f,0.0f,1.0f, //M
            -0.67f, -0.03f, 0.0f,   0.0f,0.0f,1.0f, //E
			
        //EDF 
            -0.67f, -0.03f, 0.0f,   1.0f, 0.0f, 0.0f,  //E
            -0.75f, -0.05f, 0.0f,   1.0f, 0.0f, 0.0f,  //D
            -0.56f, 0.02f, 0.0f,    1.0f, 0.0f, 0.0f,  //F
			
        //CEF 
            -0.71f, 0.08f, 0.0f,    0.0f,0.0f,1.0f, //C
            -0.67f, -0.03f, 0.0f,   0.0f,0.0f,1.0f, //E
            -0.56f, 0.02f, 0.0f,    0.0f,0.0f,1.0f, //F
  
        //EFM 
            -0.67f, -0.03f, 0.0f,   0.0f,0.0f,0.0f, //E
            -0.56f, 0.02f, 0.0f,    0.0f,0.0f,0.0f, //F
            -0.39f,-0.22f, 0.0f,    0.0f,0.0f,0.0f, //M
			
        //FNM 
            -0.56f, 0.02f, 0.0f,    0.0f,0.0f,1.0f, //F
            -0.48f, 0.02f, 0.0f,    0.0f,0.0f,1.0f, //N
            -0.39f,-0.22f, 0.0f,    0.0f,0.0f,1.0f, //M	
			
        //FNL 
            -0.56f, 0.02f, 0.0f,    1.0f, 0.0f, 0.0f,  //F
			-0.48f, 0.02f, 0.0f,    1.0f, 0.0f, 0.0f,  //N
            -0.5f, 0.05f, 0.0f,     1.0f, 0.0f, 0.0f,  //L

        //FLG 
           -0.56f, 0.02f, 0.0f,     0.0f,1.0f,0.0f, //F
           -0.5f, 0.05f, 0.0f,      0.0f,1.0f,0.0f, //L		
           -0.51f, 0.11f, 0.0f,     0.0f,1.0f,0.0f, //G
        
        //NLJ
            -0.48f, 0.02f, 0.0f,    0.0f,0.0f,0.0f, //N
            -0.45f, 0.03f, 0.0f,    0.0f,0.0f,0.0f, //J
            -0.5f, 0.05f, 0.0f,    0.0f,0.0f,0.0f, //L
		
        //CFG 
            -0.71f, 0.08f, 0.0f,    1.0f, 0.0f, 0.0f,  //C
            -0.51f, 0.11f, 0.0f,    1.0f, 0.0f, 0.0f,  //G
            -0.56f, 0.02f, 0.0f,    1.0f, 0.0f, 0.0f,  //F

        //GLK 
            -0.51f, 0.11f, 0.0f,    0.0f,0.0f,1.0f, //G
            -0.5f, 0.05f, 0.0f,     0.0f,0.0f,1.0f, //L
            -0.46f, 0.07f, 0.0f,    0.0f,0.0f,1.0f, //K
			
        //KLJ
            -0.46f, 0.07f, 0.0f,    1.0f,0.0f,0.0f, //K
            -0.5f, 0.05f, 0.0f,     1.0f,0.0f,0.0f, //L
            -0.45f, 0.03f, 0.0f,    1.0f,0.0f,0.0f, //J
		   
        //JNO 
            -0.45f, 0.03f, 0.0f,    0.0f,0.0f,1.0f, //J
            -0.48f, 0.02f, 0.0f,    0.0f,0.0f,1.0f, //N
            -0.4F,0.02f,0.0f,       0.0f,0.0f,1.0f, //o
		
        //GIO
            -0.51f, 0.11f, 0.0f,    1.0f, 0.0f, 0.0f,  //G
            -0.42f, 0.1f, 0.0f,     1.0f, 0.0f, 0.0f,  //I
			-0.4F,0.02f,0.0f,       1.0f, 0.0f, 0.0f,  //o
			
        //NOM 
		    -0.48f, 0.02f, 0.0f,    0.0f,1.0f,0.0f, //N
			-0.4F,0.02f,0.0f,       0.0f,1.0f,0.0f, //o
			-0.39f,-0.22f, 0.0f,    0.0f,1.0f,0.0f, //M
        
        //JKI 
            -0.45f, 0.03f, 0.0f,   1.0f, 0.0f, 0.0f,  //J
            -0.46f, 0.07f, 0.0f,    1.0f, 0.0f, 0.0f,  //K
            -0.42f, 0.1f, 0.0f,     1.0f, 0.0f, 0.0f,  //I
        		
        //IJO 
            -0.42f, 0.1f, 0.0f,     0.0f,1.0f,0.0f, //I
            -0.45f, 0.03f, 0.0f,    0.0f,1.0f,0.0f, //J
            -0.4F,0.02f,0.0f,       0.0f,1.0f,0.0f, //o
			
        //ONM 
            -0.4F,0.02f,0.0f,       1.0f, 0.0f, 0.0f,  //o
            -0.48f, 0.02f, 0.0f,    1.0f, 0.0f, 0.0f,  //N
            -0.39f,-0.22f, 0.0f,    1.0f, 0.0f, 0.0f,  //M
        
        //CGH 
            -0.71f, 0.08f, 0.0f,    0.0f,0.0f,1.0f, //C
            -0.51f, 0.11f, 0.0f,    0.0f,0.0f,1.0f, //G
            -0.35f, 0.25f, 0.0f,    0.0f,0.0f,1.0f, //H
			
        //GIH 
            -0.51f, 0.11f, 0.0f,    0.0f,1.0f,0.0f, //G
            -0.42f, 0.1f, 0.0f,     0.0f,1.0f,0.0f, //I			
            -0.35f, 0.25f, 0.0f,    0.0f,1.0f,0.0f, //H
         
		//HIP 
            -0.35f, 0.25f, 0.0f,    0.0f,0.0f,0.0f, //H
            -0.42f, 0.1f, 0.0f,     0.0f, 0.0f, 0.0f, //I	
            -0.29f, 0.16f, 0.0f,    0.0f, 0.0f, 0.0f, //p	
        
        //IPO 
            -0.42f, 0.1f, 0.0f, 0.0f, 1.0f, 0.0f, //I	
            -0.29f, 0.16f, 0.0f, 0.0f, 1.0f, 0.0f, //p	
            -0.4F, 0.02f, 0.0f, 0.0f, 1.0f, 0.0f, //o
			
        //HPQ 
            -0.35f, 0.25f, 0.0f, 0.0f, 1.0f, 0.0f, //H
            -0.29f, 0.16f, 0.0f, 0.0f, 1.0f, 0.0f, //p
            -0.14f, 0.29f, 0.0f, 0.0f, 1.0f, 0.0f, //q
			
        //QRS
            -0.14f, 0.29f, 0.0f,    0.0f, 0.0f, 1.0f, //q
            0.21f, 0.32f, 0.0f,     0.0f, 0.0f, 1.0f, //S
            0.18f, 0.48f, 0.0f,     0.0f, 0.0f, 1.0f, //r
				
        //QTS 
            -0.14f, 0.29f, 0.0f, 0.0f, 1.0f, 0.0f, //q
            0.21f, 0.32f, 0.0f, 0.0f, 1.0f, 0.0f, //S
            0.12f, 0.18f, 0.0f, 0.0f, 1.0f, 0.0f, //T
				
        //TSU 
            0.21f, 0.32f, 0.0f,     1.0f, 0.0f, 0.0f, //S
            0.12f, 0.18f, 0.0f,     1.0f, 0.0f, 0.0f, //T
            0.29f, 0.18f, 0.0f,     1.0f, 0.0f, 0.0f, //U
			
        //TUV 
            0.12f, 0.18f, 0.0f, 0.0f, 1.0f, 0.0f, //T
            0.29f, 0.18f, 0.0f, 0.0f, 1.0f, 0.0f, //U
            0.28f, 0.06f, 0.0f, 0.0f, 1.0f, 0.0f, //V	
			
        //TVW 
            0.12f, 0.18f, 0.0f, 1.0f, 0.0f, 0.0f,  //T
            0.28f, 0.06f, 0.0f, 1.0f, 0.0f, 0.0f,  //V        
            0.27f, -0.01f, 0.0f, 1.0f, 0.0f, 0.0f,  //W
			
        //TWZ
            0.12f, 0.18f, 0.0f, 0.0f, 0.0f, 1.0f, //T
            0.27f, -0.01f, 0.0f, 0.0f, 0.0f, 1.0f, //W
            0.1f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, //Z

        //QTZ 
            -0.14f, 0.29f, 0.0f,    0.0f, 0.0f, 1.0f, //q
			0.12f, 0.18f, 0.0f,     0.0f, 0.0f, 1.0f, //T	
            0.1f, 0.0f, 0.0f,       0.0f, 0.0f, 1.0f, //Z	

        //QPZ 
            -0.14f, 0.29f, 0.0f, 0.0f, 1.0f, 0.0f, //q	
            -0.29f, 0.16f, 0.0f, 0.0f, 1.0f, 0.0f, //p
            0.1f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, //Z	
        
        //QA1Z 
            -0.14f, 0.29f, 0.0f,    1.0f, 0.0f, 0.0f, //q	
            -0.22f, 0.05f, 0.0f,    1.0f, 0.0f, 0.0f, //A1
            0.1f, 0.0f, 0.0f,       1.0f, 0.0f, 0.0f, //Z
	    		    
        //POA1
            -0.29f, 0.16f, 0.0f, 0.0f, 1.0f, 0.0f, //p
            -0.4F, 0.02f, 0.0f, 0.0f, 1.0f, 0.0f, //o
            -0.22f, 0.05f, 0.0f, 0.0f, 1.0f, 0.0f, //A1
				
        //OMB1 
            -0.4F, 0.02f, 0.0f, 0.0f, 0.0f, 1.0f, //o
            -0.39f, -0.22f, 0.0f, 0.0f, 0.0f, 1.0f, //M	
            -0.22f, -0.09f, 0.0f, 0.0f, 0.0f, 1.0f, //B1

        //OA1B1 
                -0.4F, 0.02f, 0.0f, 1.0f, 1.0f, 1.0f, //o
                -0.22f, 0.05f, 0.0f, 1.0f, 1.0f, 1.0f, //A1
                -0.22f, -0.09f, 0.0f, 1.0f, 1.0f, 1.0f, //B1
				
        //MB1C1
                -0.39f, -0.22f, 0.0f, 0.0f, 1.0f, 0.0f, //M	
                -0.22f, -0.09f, 0.0f, 0.0f, 1.0f, 0.0f, //B1
                -0.11f, -0.31f, 0.0f, 0.0f, 1.0f, 0.0f, //C1
		
        //MD1E1 
                -0.39f, -0.22f, 0.0f, 0.0f, 0.0f, 1.0f, //M	
                -0.27f, -0.26f, 0.0f, 0.0f, 0.0f, 1.0f, //D1	
                -0.33f, -0.34f, 0.0f, 0.0f, 0.0f, 1.0f, //E1
				
				
        //B1C1F1
                -0.22f, -0.09f, 0.0f, 0.0f, 1.0f, 0.0f, //B1
                -0.11f, -0.31f, 0.0f, 0.0f, 1.0f, 0.0f, //C1
                0.1f, -0.2f, 0.0f, 0.0f, 1.0f, 0.0f, //F1
				
		//A1B1F1 
                -0.22f, 0.05f, 0.0f, 0.0f, 0.0f, 0.0f, //A1
                -0.22f, -0.09f, 0.0f, 0.0f, 0.0f, 0.0f, //B1
                0.1f, -0.2f, 0.0f, 0.0f, 0.0f, 0.0f, //F1
				
        //A1F1Z
                -0.22f, 0.05f, 0.0f, 0.0f, 0.0f, 0.0f, //A1
                0.1f, -0.2f, 0.0f, 0.0f, 0.0f, 0.0f, //F1
                0.1f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, //Z
				
        //F1C1G1 
                0.1f, -0.2f, 0.0f, 0.0f, 0.0f, 0.0f, //F1
                -0.11f, -0.31f, 0.0f, 0.0f, 0.0f, 0.0f, //C1
                0.3f, -0.35f, 0.0f, 0.0f, 0.0f, 0.0f, //G1
				
        //C1G1H1 
                -0.11f, -0.31f, 0.0f, 0.0f, 0.0f, 1.0f, //C1
                0.3f, -0.35f, 0.0f, 0.0f, 0.0f, 1.0f, //G1
                0.22f, -0.4f, 0.0f, 0.0f, 0.0f, 1.0f, //H1
				
		
        //M1K1L1
                0.55f, -0.06f, 0.0f, 0.0f, 1.0f, 0.0f, //M1
                0.69f, -0.45f, 0.0f, 0.0f, 1.0f, 0.0f, //K1
                0.7f, -0.25f, 0.0f, 0.0f, 1.0f, 0.0f, //L1

        //VWO1
                0.28f, 0.06f, 0.0f, 0.0f, 0.0f, 1.0f, //V	
                0.27f, -0.01f, 0.0f, 0.0f, 0.0f, 1.0f, //W
                0.69f, 0.23f, 0.0f, 0.0f, 0.0f, 1.0f, //O1

        //WO1N1 
                0.27f, -0.01f, 0.0f, 0.0f, 0.0f, 0.0f, //W
                0.69f, 0.23f, 0.0f, 0.0f, 0.0f, 0.0f, //O1
                0.67f, 0.14f, 0.0f, 0.0f, 0.0f, 0.0f, //N1
				
        //WN1M1
                0.27f, -0.01f, 0.0f,    0.0f, 0.0f, 0.0f, //W
                0.67f, 0.14f, 0.0f,     0.0f, 0.0f, 0.0f, //N1
                0.55f, -0.06f, 0.0f,    0.0f, 0.0f, 0.0f, //M1

        // A1ZP
                -0.22f, 0.05f, 0.0f,    0.0f, 0.0f, 0.0f, //A1
                0.1f, 0.0f, 0.0f,       0.0f, 0.0f, 0.0f, //Z
                -0.29f, 0.16f, 0.0f,    0.0f, 0.0f, 0.0f, //p
	
	    // I1J1Q1
                0.42f, -0.19f, 0.0f, 0.0f, 1.0f, 0.0f, //I1
                0.4f, -0.44f, 0.0f, 0.0f, 1.0f, 0.0f,  //J1
				0.32f, -0.24f,0.0f, 0.0f, 1.0f, 0.0f,  //Q1
				
	    //Q1 I1 P1
                0.32f, -0.24f, 0.0f, 0.0f, 0.0f, 1.0f,  //Q1
                0.42f, -0.19f, 0.0f, 0.0f, 0.0f, 1.0f, //I1
				0.22f, -0.11f, 0.0f, 0.0f, 0.0f, 1.0f, //P1
				
	    //I1P1W
                0.42f, -0.19f, 0.0f,    0.0f, 0.0f, 0.0f, //I1
                0.22f, -0.11f, 0.0f,    0.0f, 0.0f, 0.0f, //P1	
                0.27f, -0.01f, 0.0f,    0.0f, 0.0f, 0.0f, //W


	    //F1 Z P1
                0.1f, -0.2f, 0.0f, 0.0f, 1.0f, 0.0f, //F1
                0.1f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, //Z
                0.22f, -0.11f, 0.0f, 0.0f, 1.0f, 0.0f, //P1
				
		//P1 W Z
                0.22f, -0.11f, 0.0f, 0.0f, 0.0f, 1.0f, //P1
                0.27f, -0.01f, 0.0f, 0.0f, 0.0f, 1.0f, //W
                0.1f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, //Z
		//P1 I1 W
                0.22f, -0.11f, 0.0f,        0.0f, 0.0f, 0.0f, //P1
                0.42f, -0.19f, 0.0f,       0.0f, 0.0f, 0.0f, //I1
                0.27f, -0.01f, 0.0f,        0.0f, 0.0f, 0.0f, //W

        // M1 K1 I1 
                0.55f, -0.06f, 0.0f, 0.0f, 0.0f, 1.0f, //M1
                0.69f, -0.45f, 0.0f, 0.0f, 0.0f, 1.0f,//K1	
                0.42f, -0.19f, 0.0f, 0.0f, 0.0f, 1.0f, //I1
				
		// I1 M1 W
                0.42f, -0.19f, 0.0f, 0.0f, 1.0f, 0.0f, //I1
                0.55f, -0.06f, 0.0f, 0.0f, 1.0f, 0.0f, //M1
                0.27f, -0.01f, 0.0f, 0.0f, 1.0f, 0.0f, //W
        /*
        * 
         -0.45f, 0.03f, 0.0f,   0.0f,0.0f,0.0f, //J
        -0.46f, 0.07f, 0.0f,    0.0f,0.0f,0.0f, //K
        - 0.5f, 0.05f, 0.0f,    0.0f,0.0f,0.0f, //L
        -0.39f,-0.22f, 0.0f,    0.0f,0.0f,0.0f, //M
        -0.48f, 0.02f, 0.0f,    0.0f,0.0f,0.0f, //N
        -0.4F,0.02f,0.0f,       0.0f,0.0f,0.0f, //o
        -0.29f, 0.16f, 0.0f,    0.0f,0.0f,0.0f, //p
        -0.14f, 0.29f, 0.0f,    0.0f,0.0f,0.0f, //q
        0.18f, 0.48f, 0.0f,     0.0f,0.0f,0.0f, //r
        0.21f, 0.32f, 0.0f,     0.0f,0.0f,0.0f, //S
        0.12f, 0.18f, 0.0f,     0.0f,0.0f,0.0f, //T
        0.29f, 0.18f, 0.0f,     0.0f,0.0f,0.0f, //U
        0.28f, 0.06f, 0.0f,     0.0f,0.0f,0.0f, //V
        0.27f,-0.01f, 0.0f,     0.0f,0.0f,0.0f, //W
        0.1f, 0.0f, 0.0f,       0.0f,0.0f,0.0f, //Z

        -0.22f, 0.05f, 0.0f,    0.0f,0.0f,0.0f, //A1
        -0.22f,-0.09f, 0.0f,    0.0f,0.0f,0.0f, //B1
        -0.11f,-0.31f, 0.0f,    0.0f,0.0f,0.0f, //C1
        -0.27f, -0.26f, 0.0f,   0.0f,0.0f,0.0f, //D1
        -0.33f, -0.34f, 0.0f,   0.0f,0.0f,0.0f, //E1
        0.1f, -0.2f, 0.0f,      0.0f,0.0f,0.0f, //F1
        0.3f, -0.35f, 0.0f,     0.0f,0.0f,0.0f, //G1
        0.22f, -0.4f, 0.0f,     0.0f,0.0f,0.0f, //H1
        0.42, - 0.19f, 0.0f,    0.0f,0.0f,0.0f, //I1
        0.4f,-0.44f, 0.0f,      0.0f,0.0f,0.0f, //J1
        0.69f, -0.45f, 0.0f,    0.0f,0.0f,0.0f, //K1
        0.7f,-0.25f, 0.0f,      0.0f,0.0f,0.0f, //L1
        0.55f, - 0.06f, 0.0f,   0.0f,0.0f,0.0f, //M1
        0.67f, 0.14f, 0.0f,     0.0f,0.0f,0.0f, //N1
        0.69f, 0.23f, 0.0f,     0.0f,0.0f,0.0f, //O1*/

	
    }; 

    int numTriangles = 80;

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