#ifndef SNAKE_HPP
#define SNAKE_HPP

#include <vector>
#include "Mesh.hpp"
#include "MeshManager.hpp"
#include "shaderProgram.hpp"

class Snake {
public:
    Snake(MeshManager& meshManager, ShaderProgram& shaderProgram);
    void update(float deltaTime);
    void render();
    void handleInput(int key);

private:
    std::vector<Mesh> body;
    MeshManager& meshManager;
    ShaderProgram& shaderProgram;
    float movementSpeed;
    glm::vec3 direction;

    void move();
    void grow();
};

#endif // SNAKE_HPP
