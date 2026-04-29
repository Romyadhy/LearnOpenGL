#ifndef SHADER_H
#define SHADER_H

#include <cstddef>
#include <glad/glad.h>

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

class Shader {
public:
  unsigned int ID;
  Shader(const char *vertexPath, const char *fragmentPath) {
    // NOTE: get vertex/fragment sc from filepath
    std::string vertexCode;
    std::string fragmentCode;
    std::ifstream vShaderFile;
    std::ifstream fShaderFile;

    // ensure ifstream object can trow expectations for trycatch
    vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try {
      // open file
      vShaderFile.open(vertexPath);
      fShaderFile.open(vertexPath);
      std::stringstream vShaderSteam, fShaderSteam;
      vShaderFile << vShaderFile.rdbuf();
      fShaderFile << fShaderFile.rdbuf();
      vShaderFile.close();
      fShaderFile.close();

      vertexCode = vShaderSteam.str();
      fragmentCode = fShaderSteam.str();

    } catch (const std::ifstream::failure &e) {
      std::cout << "ERROR::SHADER::FILE_NOT_READ: " << e.what() << std::endl;
    }
    const char *vShaderCode = vertexCode.c_str();
    const char *fShaderCode = fragmentCode.c_str();
    // NOTE: compile and link the shader
    unsigned int vertex, fragment;

    vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vShaderCode, NULL);
    glCompileShader(vertex);
    chekCompileErros(vertex, "VERTEX");

    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fShaderCode, NULL);
    glCompileShader(fragment);
    chekCompileErros(fragment, "FRAGMENT");

    ID = glCreateProgram();
    glAttachShader(ID, vertex);
    glAttachShader(ID, fragment);
    glLinkProgram(ID);
    chekCompileErros(ID, "PROGRAM");

    glDeleteShader(vertex);
    glDeleteShader(fragment);
  }
  void use() { glUseProgram(ID); }
  void setBool(const std::string &name, bool value) const {
    glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
  }
  void setInt(const std::string &name, int value) const {
    glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
  }
  void setFloat(const std::string &name, float value) const {
    glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
  }

private:
  void chekCompileErros(unsigned int shader, std::string type) {
    int success;
    char infoLog[1024];
    if (type != "PROGRAM") {
      glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
      if (!success) {
        glGetShaderInfoLog(shader, 1024, NULL, infoLog);
        std::cout
            << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n"
            << infoLog
            << "\n -- --------------------------------------------------- -- "
            << std::endl;
      }
    } else {
      glGetProgramiv(shader, GL_LINK_STATUS, &success);
      if (!success) {
        glGetProgramInfoLog(shader, 1024, NULL, infoLog);
        std::cout
            << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n"
            << infoLog
            << "\n -- --------------------------------------------------- -- "
            << std::endl;
      }
    }
  }
};
#endif
