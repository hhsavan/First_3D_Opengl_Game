#include "../include/helpers.hpp"
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glad/glad.h>

// Function to draw a 3D cube
// Function to draw a 3D cube
void drawCube(GLuint shaderProgram) {
    static const GLfloat vertices[] = {
        // Positions          // Colors           // Texture Coords
        -0.5f, -0.5f, -0.5f,  1.0f, 0.0f, 0.0f,   0.0f, 0.0f,
         0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 0.0f,   1.0f, 0.0f,
         0.5f,  0.5f, -0.5f,  0.0f, 0.0f, 1.0f,   1.0f, 1.0f,
        -0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 0.0f,   0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,  1.0f, 0.0f, 1.0f,   0.0f, 0.0f,
         0.5f, -0.5f,  0.5f,  0.0f, 1.0f, 1.0f,   1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 0.5f, 0.0f,   1.0f, 1.0f,
        -0.5f,  0.5f,  0.5f,  0.5f, 0.5f, 0.5f,   0.0f, 1.0f
    };

    static const GLuint indices[] = {
        0, 1, 2, 2, 3, 0,
        4, 5, 6, 6, 7, 4,
        0, 1, 5, 5, 4, 0,
        2, 3, 7, 7, 6, 2,
        0, 3, 7, 7, 4, 0,
        1, 5, 6, 6, 2, 1
    };

    static GLuint VBO, VAO, EBO;
    static bool isInitialized = false;

    if (!isInitialized) {
        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);
        glGenBuffers(1, &EBO);

        glBindVertexArray(VAO);

        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

        // Position attribute
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)0);
        glEnableVertexAttribArray(0);

        // Color attribute
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
        glEnableVertexAttribArray(1);

        // Texture Coord attribute
        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
        glEnableVertexAttribArray(2);

        glBindVertexArray(0);

        isInitialized = true;
    }

    glUseProgram(shaderProgram);
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}

void drawTrapezoid(GLuint shaderProgram) {
    static const GLfloat vertices[] = {
        // Positions          // Colors           // Texture Coords
        -0.5f, -0.5f, -0.5f,  0.5f, 0.0f, 0.5f,   0.0f, 0.0f,
         0.5f, -0.5f, -0.5f,  0.0f, 0.5f, 0.5f,   1.0f, 0.0f,
         0.3f,  0.5f, -0.5f,  0.5f, 0.5f, 0.0f,   0.875f, 1.0f,
        -0.3f,  0.5f, -0.5f,  0.5f, 0.5f, 0.5f,   0.125f, 1.0f,
        -0.5f, -0.5f,  0.5f,  0.5f, 0.0f, 0.0f,   0.0f, 0.0f,
         0.5f, -0.5f,  0.5f,  0.0f, 0.5f, 0.0f,   1.0f, 0.0f,
         0.3f,  0.5f,  0.5f,  0.0f, 0.0f, 0.5f,   0.875f, 1.0f,
        -0.3f,  0.5f,  0.5f,  0.0f, 0.5f, 0.5f,   0.125f, 1.0f,
    };

    static const GLuint indices[] = {
        0, 1, 2, 2, 3, 0,
        4, 5, 6, 6, 7, 4,
        0, 1, 5, 5, 4, 0,
        2, 3, 7, 7, 6, 2,
        0, 3, 7, 7, 4, 0,
        1, 5, 6, 6, 2, 1
    };

    static GLuint VBO, VAO, EBO;
    static bool isInitialized = false;

    if (!isInitialized) {
        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);
        glGenBuffers(1, &EBO);

        glBindVertexArray(VAO);

        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

        // Position attribute
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)0);
        glEnableVertexAttribArray(0);

        // Color attribute
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
        glEnableVertexAttribArray(1);

        // Texture Coord attribute
        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
        glEnableVertexAttribArray(2);

        glBindVertexArray(0);

        isInitialized = true;
    }

    glUseProgram(shaderProgram);
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}
void drawSphere(GLuint shaderProgram) {
    const int latitudeBands = 30;
    const int longitudeBands = 30;
    const float radius = 0.5f;

    std::vector<GLfloat> vertices;
    std::vector<GLuint> indices;

    for (int latNumber = 0; latNumber <= latitudeBands; ++latNumber) {
        float theta = latNumber * M_PI / latitudeBands;
        float sinTheta = sin(theta);
        float cosTheta = cos(theta);

        for (int longNumber = 0; longNumber <= longitudeBands; ++longNumber) {
            float phi = longNumber * 2 * M_PI / longitudeBands;
            float sinPhi = sin(phi);
            float cosPhi = cos(phi);

            float x = cosPhi * sinTheta;
            float y = cosTheta;
            float z = sinPhi * sinTheta;
            float u = (float)longNumber / longitudeBands;
            float v = (float)latNumber / latitudeBands;

            vertices.push_back(radius * x);
            vertices.push_back(radius * y);
            vertices.push_back(radius * z);
            vertices.push_back(u);
            vertices.push_back(v);
            vertices.push_back(1.0f); // Placeholder for color
        }
    }

    for (int latNumber = 0; latNumber < latitudeBands; ++latNumber) {
        for (int longNumber = 0; longNumber < longitudeBands; ++longNumber) {
            int first = (latNumber * (longitudeBands + 1)) + longNumber;
            int second = first + longitudeBands + 1;

            indices.push_back(first);
            indices.push_back(second);
            indices.push_back(first + 1);

            indices.push_back(second);
            indices.push_back(second + 1);
            indices.push_back(first + 1);
        }
    }

    static GLuint VBO, VAO, EBO;
    static bool isInitialized = false;

    if (!isInitialized) {
        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);
        glGenBuffers(1, &EBO);

        glBindVertexArray(VAO);

        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(GLfloat), &vertices[0], GL_STATIC_DRAW);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), &indices[0], GL_STATIC_DRAW);

        // Position attribute
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
        glEnableVertexAttribArray(0);

        // Texture Coord attribute
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
        glEnableVertexAttribArray(1);

        glBindVertexArray(0);

        isInitialized = true;
    }

    glUseProgram(shaderProgram);
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}
// Function to draw a 3D star
void drawStar(GLuint shaderProgram) {
    const GLfloat vertices[] = {
        // Positions          // Colors
        0.0f,  0.5f, 0.0f,  1.0f, 1.0f, 0.0f, // Top
        0.2f,  0.2f, 0.0f,  1.0f, 0.5f, 0.0f, // Right Upper
        0.5f,  0.2f, 0.0f,  1.0f, 0.0f, 0.0f, // Right Far
        0.3f, -0.1f, 0.0f,  0.5f, 0.5f, 0.5f, // Right Lower
        0.4f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f, // Bottom Right
        0.0f, -0.3f, 0.0f,  0.0f, 0.5f, 1.0f, // Bottom
       -0.4f, -0.5f, 0.0f,  0.0f, 0.0f, 1.0f, // Bottom Left
       -0.3f, -0.1f, 0.0f,  0.5f, 0.0f, 0.5f, // Left Lower
       -0.5f,  0.2f, 0.0f,  0.5f, 0.5f, 0.0f, // Left Far
       -0.2f,  0.2f, 0.0f,  0.0f, 1.0f, 1.0f  // Left Upper
    };

    static GLuint VBO, VAO;
    static bool isInitialized = false;

    if (!isInitialized) {
        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);

        glBindVertexArray(VAO);

        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
        glEnableVertexAttribArray(0);

        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
        glEnableVertexAttribArray(1);

        glBindVertexArray(0);

        isInitialized = true;
    }

    glUseProgram(shaderProgram);
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLE_FAN, 0, 10);
    glBindVertexArray(0);
}


// Function to draw a 3D cylinder
void drawCylinder(GLuint shaderProgram) {
    const int segments = 36;
    const float radius = 0.5f;
    const float height = 1.0f;

    std::vector<GLfloat> vertices;
    std::vector<GLuint> indices;

    // Top circle
    for (int i = 0; i <= segments; ++i) {
        float theta = i * 2.0f * M_PI / segments;
        float x = radius * cos(theta);
        float y = height / 2;
        float z = radius * sin(theta);
        float u = (float)i / segments;
        vertices.push_back(x);
        vertices.push_back(y);
        vertices.push_back(z);
        vertices.push_back(u);
        vertices.push_back(1.0f);
    }

    // Bottom circle
    for (int i = 0; i <= segments; ++i) {
        float theta = i * 2.0f * M_PI / segments;
        float x = radius * cos(theta);
        float y = -height / 2;
        float z = radius * sin(theta);
        float u = (float)i / segments;
        vertices.push_back(x);
        vertices.push_back(y);
        vertices.push_back(z);
        vertices.push_back(u);
        vertices.push_back(0.0f);
    }

    // Indices for top circle
    for (int i = 0; i < segments; ++i) {
        indices.push_back(i);
        indices.push_back(i + 1);
        indices.push_back(segments);
    }

    // Indices for bottom circle
    for (int i = 0; i < segments; ++i) {
        indices.push_back(segments + 1 + i);
        indices.push_back(segments + 2 + i);
        indices.push_back(2 * segments + 1);
    }

    // Indices for side surface
    for (int i = 0; i < segments; ++i) {
        indices.push_back(i);
        indices.push_back(i + 1);
        indices.push_back(segments + 1 + i);

        indices.push_back(i + 1);
        indices.push_back(segments + 2 + i);
        indices.push_back(segments + 1 + i);
    }

    static GLuint VBO, VAO, EBO;
    static bool isInitialized = false;

    if (!isInitialized) {
        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);
        glGenBuffers(1, &EBO);

        glBindVertexArray(VAO);

        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(GLfloat), &vertices[0], GL_STATIC_DRAW);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), &indices[0], GL_STATIC_DRAW);

        // Position attribute
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)0);
        glEnableVertexAttribArray(0);

        // Texture Coord attribute
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
        glEnableVertexAttribArray(1);

        glBindVertexArray(0);

        isInitialized = true;
    }

    glUseProgram(shaderProgram);
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}


// Function to draw a 3D pyramid
void drawPyramid(GLuint shaderProgram) {
    static const GLfloat vertices[] = {
        // Positions           // Colors           // Texture Coords
        // Base
        -0.5f, 0.0f, -0.5f,    1.0f, 0.0f, 0.0f,   0.0f, 0.0f,
         0.5f, 0.0f, -0.5f,    0.0f, 1.0f, 0.0f,   1.0f, 0.0f,
         0.5f, 0.0f,  0.5f,    0.0f, 0.0f, 1.0f,   1.0f, 1.0f,
        -0.5f, 0.0f,  0.5f,    1.0f, 1.0f, 0.0f,   0.0f, 1.0f,
        // Apex
         0.0f, 0.5f,  0.0f,    1.0f, 0.0f, 1.0f,   0.5f, 0.5f,
    };

    static const GLuint indices[] = {
        // Base
        0, 1, 2, 2, 3, 0,
        // Sides
        0, 1, 4,
        1, 2, 4,
        2, 3, 4,
        3, 0, 4
    };

    static GLuint VBO, VAO, EBO;
    static bool isInitialized = false;

    if (!isInitialized) {
        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);
        glGenBuffers(1, &EBO);

        glBindVertexArray(VAO);

        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

        // Position attribute
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)0);
        glEnableVertexAttribArray(0);

        // Color attribute
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
        glEnableVertexAttribArray(1);

        // Texture Coord attribute
        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
        glEnableVertexAttribArray(2);

        glBindVertexArray(0);

        isInitialized = true;
    }

    glUseProgram(shaderProgram);
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 18, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}

