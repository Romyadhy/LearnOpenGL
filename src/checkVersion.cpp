
// #include "D:/Document/C++/LearnCPP/OPENGL/header/GLFW/glfw3.h"
#include <GLFW/glfw3.h>
#include <iostream>

int main() {
  int major, minor, rev;
  glfwGetVersion(&major, &minor, &rev);

  std::cout << "GLFW Version: " << major << "." << minor << "." << rev
            << std::endl;

  // Optionally, get the full version string (includes platform/compiler info)
  const char *versionString = glfwGetVersionString();
  std::cout << "GLFW Version String: " << versionString << std::endl;

  return 0;
}
