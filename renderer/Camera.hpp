#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "include/glad/glad.h"
#include <GLFW/glfw3.h>
#include "include/glm/glm.hpp"
#include "include/glm/gtc/matrix_transform.hpp"
#include "include/glm/gtc/type_ptr.hpp"
#include "include/glm/gtx/rotate_vector.hpp"
#include "include/glm/gtx/vector_angle.hpp"

#include "Shader.hpp"

class Camera
{
public:
  glm::vec3 Position;
  glm::vec3 Orientation{glm::vec3(0.0f, 0.0f, -1.0f)};
  glm::vec3 Up{glm::vec3(0.0f, 1.0f, 0.0f)};
  glm::mat4 cameraMatrix{glm::mat4(1.0f)};
  bool firstClick{true};
  int width;
  int height;
  float speed{0.1f};
  float sensitivity{100.0f};

public:
  Camera() = default;

  Camera(int width, int height, glm::vec3 position);

  void UpdateMatrix(float FOVdeg, float nearPlane, float farPlane);

  void Matrix(Shader &shader, const char *uniform);

  void Inputs(GLFWwindow *window);
};

#endif