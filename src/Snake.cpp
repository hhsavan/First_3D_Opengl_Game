// #include "../include/Snake.hpp"
// #include "glm/glm.hpp"
// #include "glm/gtc/matrix_transform.hpp"

// Snake::Snake(MeshManager& meshManager, ShaderProgram& shaderProgram)
//     : meshManager(meshManager), shaderProgram(shaderProgram), movementSpeed(1.0f), direction(1.0f, 0.0f, 0.0f) {
//     // Initialize snake with 3 cubes
//     for (int i = 0; i < 3; ++i) {
//         Mesh cube = meshManager.createCube();
//         cube.setPosition(glm::vec3(-i, 0, 0));
//         body.push_back(cube);
//     }
// }

// void Snake::update(float deltaTime) {
//     move();
// }

// void Snake::render() {
//     for (auto& segment : body) {
//         segment.render(shaderProgram);
//     }
// }

// void Snake::handleInput(int key) {
//     switch (key) {
//         case 'W': direction = glm::vec3(0, 1, 0); break;
//         case 'A': direction = glm::vec3(-1, 0, 0); break;
//         case 'S': direction = glm::vec3(0, -1, 0); break;
//         case 'D': direction = glm::vec3(1, 0, 0); break;
//     }
// }

// void Snake::move() {
//     // Move body
//     for (size_t i = body.size() - 1; i > 0; --i) {
//         body[i].setPosition(body[i - 1].getPosition());
//     }
//     body[0].setPosition(body[0].getPosition() + direction * movementSpeed);
// }

// void Snake::grow() {
//     Mesh newSegment = meshManager.createCube();
//     newSegment.setPosition(body.back().getPosition());
//     body.push_back(newSegment);
// }
