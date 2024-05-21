#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

using namespace std;


int main(){

    
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

 /* Make the window's context current */
    glfwMakeContextCurrent(window);
    //burdan sonra glew kodu yazýyoruz.

    if (glewInit() != GLEW_OK) {
        std::cout << "GLEW ERROR!!" << std::endl;
        return 1;
    }
     
    std::cout <<"Version: ";
    std::cout << glGetString(GL_VERSION) << std::endl;


    float positions[6] = {
    -0.5f, -0.5f,
     0.0f, 0.5f,
     0.5f, -0.5f
    };
    // Gluint vas;
    //vertex buffer initializing
    unsigned int buffer = 0;
    glGenBuffers(1, &buffer); //buffer id'si
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positions, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, buffer);

    /* Loop until the user closes the window */
    //game loop
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        glDrawArrays(GL_TRIANGLES, 0, 3);


        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();


    return 0;
}