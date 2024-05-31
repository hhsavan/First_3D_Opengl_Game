#include <iostream>
#include <thread>
#include <chrono>
#include <glad/glad.h>
#include <glm/vec3.hpp>
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>
#include <vector>
#include <cmath>
#include <glm/gtc/matrix_transform.hpp>
#include "../include/shaderProgram.hpp"
#include "../include/texturemanager.hpp"
#include "../include/helpers.hpp"
// #include "../include/MeshManager.hpp"
// #include "../include/Mesh.hpp"

// Mesh *mesh;
float angle;
glm::vec3 position;
float scale;

unsigned int texture1, texture2, texture3, texture4;

// Mouse control variables
float lastX = 400, lastY = 400;
float yaw = -90.0f, pitch = 0.0f;
float fov = 45.0f;
bool firstMouse = true;

glm::vec3 camPosition(2.0f, 2.0f, 2.0f);
glm::vec3 camFront(0.0f, 0.0f, -1.0f);
glm::vec3 camUp(0.0f, 1.0f, 0.0f);

void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE)
        glfwSetWindowShouldClose(window, true);

    glm::vec3 camRight = glm::normalize(glm::cross(camFront, camUp));

    if (key == GLFW_KEY_W)
        camPosition += camFront * 0.1f;
    if (key == GLFW_KEY_S)
        camPosition -= camFront * 0.1f;
    if (key == GLFW_KEY_A)
        camPosition -= camRight * 0.1f;
    if (key == GLFW_KEY_D)
        camPosition += camRight * 0.1f;
}

void mouse_callback(GLFWwindow *window, double xpos, double ypos)
{
    if (firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos;
    lastX = xpos;
    lastY = ypos;

    float sensitivity = 0.1f;
    xoffset *= sensitivity;
    yoffset *= sensitivity;

    yaw += xoffset;
    pitch += yoffset;

    if (pitch > 89.0f)
        pitch = 89.0f;
    if (pitch < -89.0f)
        pitch = -89.0f;

    glm::vec3 front;
    front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    front.y = sin(glm::radians(pitch));
    front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    camFront = glm::normalize(front);
}

void scroll_callback(GLFWwindow *window, double xoffset, double yoffset)
{
    if (fov >= 1.0f && fov <= 45.0f)
        fov -= yoffset;
    if (fov <= 1.0f)
        fov = 1.0f;
    if (fov >= 45.0f)
        fov = 45.0f;
}

int main(int argc, char **argv)
{
    if (!glfwInit())
        return -1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow *window = glfwCreateWindow(800, 800, "My First Program", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwSetKeyCallback(window, key_callback);
    glfwSetCursorPosCallback(window, mouse_callback);
    glfwSetScrollCallback(window, scroll_callback);

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    texture1 = TextureManager::getInstance()->loadTexture("./images/brick.jpg");
    texture2 = TextureManager::getInstance()->loadTexture("./images/soil2.jpg");
    texture3 = TextureManager::getInstance()->loadTexture("./images/container.jpg");
    texture4 = TextureManager::getInstance()->loadTexture("./images/soilTexture.jpg");

    // MeshManager *manager = MeshManager::getInstance();
    // mesh = manager->createGameArea();

    ShaderProgram program;
    program.attachShader("./shaders/vshader.glsl", GL_VERTEX_SHADER);
    program.attachShader("./shaders/fshader.glsl", GL_FRAGMENT_SHADER);
    program.link();

    program.addUniform("uColor");
    program.addUniform("uMtxTransform");

    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    // zbuffer
    glEnable(GL_DEPTH_TEST);
    const std::chrono::duration<double> targetFrameDuration(1.0 / 30.0);
    while (!glfwWindowShouldClose(window))
    {
        auto frameStartTime = std::chrono::high_resolution_clock::now();
        glClearColor(0.0f, 0.4f, 0.7f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Handle input events
        glfwPollEvents();

        glm::mat4 view = glm::lookAt(camPosition, camPosition + camFront, camUp);
        glm::mat4 projection = glm::perspective(glm::radians(fov), 800.0f / 800.0f, 0.1f, 100.0f);

        program.use();

        
        for (int i = 0; i < 3; ++i)
        {
            glm::vec3 position = glm::vec3(-1.0f + i * 2.0f, 0.0f, -1.0f);
            float scale = 0.5f + i * 0.5f;
            glm::mat4 model = glm::translate(glm::mat4(1.0f), position) * glm::scale(glm::mat4(1.0f), glm::vec3(scale));
            glm::mat4 mtxTransform = projection * view * model;
            program.setVec4("uColor", glm::vec4(1.0f, 0.0f, 0.0f, 1.0f));
            program.setMat4("uMtxTransform", &mtxTransform);
            TextureManager::getInstance()->activateTexture(GL_TEXTURE0, texture1);
            drawCube(program.getShader());
        }

        float timeValue = glfwGetTime();
        glm::vec3 rotationAxis = glm::vec3(0.0f, 1.0f, 0.0f);
        glm::mat4 model = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -3.0f)) * glm::rotate(glm::mat4(1.0f), timeValue, rotationAxis);
        glm::mat4 mtxTransform = projection * view * model;
        program.setVec4("uColor", glm::vec4(1.0f, 0.0f, 0.0f, 1.0f));
        program.setMat4("uMtxTransform", &mtxTransform);
        TextureManager::getInstance()->activateTexture(GL_TEXTURE0, texture1);
        drawCube(program.getShader());

        model = glm::translate(glm::mat4(1.0f), glm::vec3(6.0f, 0.0f, -1.0f));
        mtxTransform = projection * view * model;
        program.setVec4("uColor", glm::vec4(0.0f, 1.0f, 0.0f, 1.0f));
        program.setMat4("uMtxTransform", &mtxTransform);
        TextureManager::getInstance()->activateTexture(GL_TEXTURE0, texture2);
        drawTrapezoid(program.getShader());

        model = glm::translate(glm::mat4(1.0f), glm::vec3(-1.0f, 0.0f, 1.0f));
        mtxTransform = projection * view * model;
        program.setVec4("uColor", glm::vec4(0.0f, 0.0f, 1.0f, 1.0f));
        program.setMat4("uMtxTransform", &mtxTransform);
        TextureManager::getInstance()->activateTexture(GL_TEXTURE0, texture3);
        drawPyramid(program.getShader());

        model = glm::translate(glm::mat4(1.0f), glm::vec3(1.0f, 0.0f, 1.0f));
        mtxTransform = projection * view * model;
        program.setVec4("uColor", glm::vec4(1.0f, 1.0f, 0.0f, 1.0f));
        program.setMat4("uMtxTransform", &mtxTransform);
        TextureManager::getInstance()->activateTexture(GL_TEXTURE0, texture4);
        drawCylinder(program.getShader());

        glfwSwapBuffers(window);

        auto frameEndTime = std::chrono::high_resolution_clock::now();
        auto frameDuration = std::chrono::duration<double>(frameEndTime - frameStartTime);
        if (frameDuration < targetFrameDuration)
        {
            std::this_thread::sleep_for(targetFrameDuration - frameDuration);
        }
    }

    glfwTerminate();
    return 0;
}
