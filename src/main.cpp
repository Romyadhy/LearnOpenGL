#include <cstddef>
#include <glad/glad.h>

#include <GLFW/glfw3.h>
#include <iostream>

// NOTE: whenever the window size changed
void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
  glViewport(0, 0, width, height);
}

// NOTE: process all input
void processInput(GLFWwindow *window) {
  if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
    glfwSetWindowShouldClose(window, true);
  }
}

void processTest(GLFWwindow *window) {
  if (glfwGetKey(window, GLFW_KEY_ENTER) == GLFW_PRESS) {
    glfwSetWindowShouldClose(window, true);
  }
}

const char *vertexShaderSource =
    "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";

const char *fragmentShaderSourceDefault =
    "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    " FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
    "}\n";

const char *fragmentShaderSourceBlue =
    "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    " FragColor = vec4(0.0f, 0.0f, 1.0f, 1.0f);\n"
    "}\n";

int main() {
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  // make window
  GLFWwindow *window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
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

  // TODO: build and comile shader
  // shader source
  unsigned int vertexShader;
  vertexShader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
  glCompileShader(vertexShader);

  // fragment yellow color
  unsigned int fragmentShaderYellow;
  fragmentShaderYellow = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragmentShaderYellow, 1, &fragmentShaderSourceDefault, NULL);
  glCompileShader(fragmentShaderYellow);

  unsigned int fragmentShasderBlue;
  fragmentShasderBlue = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragmentShasderBlue, 1, &fragmentShaderSourceBlue, NULL);
  glCompileShader(fragmentShasderBlue);

  // shader program
  // NOTE:Shader program default color
  unsigned int shaderProgramYellow;
  shaderProgramYellow = glCreateProgram();
  glAttachShader(shaderProgramYellow, vertexShader);
  glAttachShader(shaderProgramYellow, fragmentShaderYellow);
  glLinkProgram(shaderProgramYellow);

  // NOTE:Shader program blue color
  unsigned int shaderProgramBlue;
  shaderProgramBlue = glCreateProgram();
  glAttachShader(shaderProgramBlue, vertexShader);
  glAttachShader(shaderProgramBlue, fragmentShasderBlue);
  glLinkProgram(shaderProgramBlue);

  // FIX: check shader and fragment, add for fragmentShader
  int success;
  char infoLog[512];
  glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
  glGetShaderiv(fragmentShaderYellow, GL_COMPILE_STATUS, &success);
  glGetShaderiv(shaderProgramYellow, GL_LINK_STATUS, &success);

  if (!success) {
    glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
    glGetShaderInfoLog(fragmentShaderYellow, 512, NULL, infoLog);
    glGetShaderInfoLog(shaderProgramYellow, 512, NULL, infoLog);
    std::cout << "ERROR::SHADER::VERTEX:COMPILATIONS_FAILED\n"
              << infoLog << std::endl;
    std::cout << "ERROR::SHADER::FRAGMENT:COMPILATIONS_FAILED\n"
              << infoLog << std::endl;
    std::cout << "ERROR::SHADER::PROGRAM:COMPILATIONS_FAILED\n"
              << infoLog << std::endl;
  }
  // delete after drawing
  glDeleteShader(vertexShader);
  glDeleteShader(fragmentShaderYellow);
  glDeleteShader(fragmentShasderBlue);

  // TODO: set vertices
  // triangle vertices
  float vertices[] = {
      // base triangle
      // -0.2f, -0.2f, 0.0f, 0.2f, -0.2f, 0.0f, 0.0f, 0.3f, 0.0f,

      // first triangle
      // 0.5f, 0.5f, 0.0f,  // top right
      // 0.5f, -0.5f, 0.0f, // bottom right
      // -0.5f, 0.5f, 0.0f, // top left

      // second triangle
      // 0.5f, -0.5f, 0.0f,  // bottom right
      // -0.5f, -0.5f, 0.0f, // bottom left
      // -0.5f, 0.5f, 0.0f,   // top left

      // Left Triangle
      -0.9f, -0.5f, 0.0f, // Left
      -0.0f, -0.5f, 0.0f, // Right
      -0.45f, 0.5f, 0.0f, // Top
                          // Right Triangle
      0.0f, -0.5f, 0.0f,  // Left
      0.9f, -0.5f, 0.0f,  // Right
      0.45f, 0.5f, 0.0f   // Top

  };
  float firstTriangle[] = {-0.9f, -0.5f,  0.0f, -0.0f, -0.5f,
                           0.0f,  -0.45f, 0.5f, 0.0f};

  float secondTriangle[] = {0.0f, -0.5f, 0.0f, 0.9f, -0.5f,
                            0.0f, 0.45f, 0.5f, 0.0f};

  // VBO n VAO;
  unsigned int VBO[2], VAO[2];
  glGenVertexArrays(2, VAO);
  glGenBuffers(2, VBO);
  glBindVertexArray(VAO[0]);

  // vertices array for OPGNGL to use
  glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);
  glBufferData(GL_ARRAY_BUFFER, sizeof(firstTriangle), firstTriangle,
               GL_STATIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
  glEnableVertexAttribArray(0);

  // TODO: secondTriangle
  glBindVertexArray(VAO[1]);
  glBindBuffer(GL_ARRAY_BUFFER, VBO[1]);
  glBufferData(GL_ARRAY_BUFFER, sizeof(secondTriangle), secondTriangle,
               GL_STATIC_DRAW);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
  glEnableVertexAttribArray(0);

  // NOTE: safety unbind
  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindVertexArray(0);

  // keep render running
  while (!glfwWindowShouldClose(window)) {

    // close using pressing esp/enter  key
    processInput(window);
    processTest(window);

    // background color
    glClearColor(0.2, 0.3, 0.3, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    // glUseProgram(shaderProgram);
    // glBindVertexArray(VAO);
    // glDrawArrays(GL_TRIANGLES, 0, 6); //NOTE: ANSWER NUMBER 1
    // NOTE: ANSWER NUMBER 2
    // 1
    // NOTE: ANSWER NUMBER 3
    glUseProgram(shaderProgramYellow);
    glBindVertexArray(VAO[0]);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    // 2
    // NOTE: ANSWER NUMBER 3
    glUseProgram(shaderProgramBlue);
    glBindVertexArray(VAO[1]);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    // TODO: check and call event
    glfwSwapBuffers(window);
    glfwPollEvents();
  }
  // TODO: cleaning glfw resource after renderer
  glfwTerminate();
  return 0;
}
