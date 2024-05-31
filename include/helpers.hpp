#ifndef HELPER_H
#define HELPER_H
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <sstream>
#include <string>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

void drawCube(GLuint shaderProgram);
void drawTrapezoid(GLuint shaderProgram);
void drawSphere(GLuint shaderProgram);
void drawStar(GLuint shaderProgram);
void drawCylinder(GLuint shaderProgram);
void drawPyramid(GLuint shaderProgram);
#endif