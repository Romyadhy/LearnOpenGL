#include <cstddef>
#include <glad/glad.h>

#include <GLFW/glfw3.h>
#include <iostream>

// NOTE: whenever the window size changed
void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
  glViewport(0, 0, width, height);
}

// NOTE: ABOUT SHADERS
const char *vertexShaderr = "#version 330 core\n"
                            "layout (location = 0) in vec3 aPos;\n"
                            "out vec4 vertexColor;\n"
                            "void main()\n"
                            "{\n"
                            "gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
                            "vertexColor = vec4(0.5, 0.0, 0.0, 1.0);\n"
                            "}\n";

const char *fragmentShaderr = "#version 330 core\n"
                              "out vec4 FragColor;\n"
                              "in vec4 vertexColor;\n"
                              "void main()\n"
                              "{\n"
                              "FragColor = vertexColor;\n"
                              "}\n";

int main() {
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  // make window
  GLFWwindow *window =
      glfwCreateWindow(800, 600, "LearnOpenGL-shaderthings", NULL, NULL);
  if (window == NULL) {
    std::cout << "Failed to create a window" << std::endl;
    glfwTerminate();
    return -1;
  }
  glfwMakeContextCurrent(window);
  // NOTE: every window rezise
  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
  // NOTE: Glad load
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    std::cout << "Failed to initialize GLAD" << std::endl;
    return -1;
  }

  // TODO: -SHADERS SECTIONS- Build and Compile shader
  // shader source
  unsigned int vertexShader_shader;
  vertexShader_shader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertexShader_shader, 1, &vertexShaderr, NULL);
  glCompileShader(vertexShader_shader);
  // fragment source
  unsigned int fragmentShader_shader;
  fragmentShader_shader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragmentShader_shader, 1, &fragmentShaderr, NULL);
  glCompileShader(fragmentShader_shader);

  // NOTE: -SHADERS SECTIONS- Shader program
  unsigned int shaderProgramShader;
  shaderProgramShader = glCreateProgram();
  glAttachShader(shaderProgramShader, vertexShader_shader);
  glAttachShader(shaderProgramShader, fragmentShader_shader);
  glLinkProgram(shaderProgramShader);

  // FIX: check shader and fragment, add for fragmentShader
  int success;
  char infoLog[512];

  // NOTE: -SHADER SECTIONS-
  glGetShaderiv(vertexShader_shader, GL_COMPILE_STATUS, &success);

  if (!success) {
    glGetShaderInfoLog(shaderProgramShader, 512, NULL, infoLog);
    std::cout << "ERROR::SHADER::PROGRAM:COMPILATIONS_FAILED\n"
              << infoLog << std::endl;
  }
  glDeleteShader(fragmentShader_shader);

  // TODO: triangle vertices
  float vertices[] = {-0.5f, -0.5f, 0.0f, 0.5f, -0.5f,
                      0.0f,  0.0f,  0.5f, 0.0f

  };
  // VBO n VAO;
  unsigned int VBO, VAO;
  glGenVertexArrays(1, &VAO);
  glGenBuffers(1, &VBO);
  glBindVertexArray(VAO);

  // default triangle
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
  glEnableVertexAttribArray(0);

  // NOTE: safety unbind
  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindVertexArray(0);

  // keep render running
  while (!glfwWindowShouldClose(window)) {
    // background color
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    // glUseProgram(shaderProgramDefault);
    glUseProgram(shaderProgramShader);
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    // TODO: check and call event
    glfwSwapBuffers(window);
    glfwPollEvents();
  }
  // TODO: cleaning glfw resource after renderer
  glfwTerminate();
  return 0;
}
