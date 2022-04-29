# Install script for directory: C:/Users/aconc/Desktop/Mis_archivos/Computer_Science_UNSA/Computación Gráfica/Laboratorio/GLFW_GLAD_GLUT_GLEW_cmake_project/src

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Users/aconc/Desktop/Mis_archivos/Computer_Science_UNSA/Computación Gráfica/Laboratorio/GLFW_GLAD_GLUT_GLEW_cmake_project/out/install/x64-Debug")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("C:/Users/aconc/Desktop/Mis_archivos/Computer_Science_UNSA/Computación Gráfica/Laboratorio/GLFW_GLAD_GLUT_GLEW_cmake_project/out/build/x64-Debug/src/Tutorial_01/cmake_install.cmake")
  include("C:/Users/aconc/Desktop/Mis_archivos/Computer_Science_UNSA/Computación Gráfica/Laboratorio/GLFW_GLAD_GLUT_GLEW_cmake_project/out/build/x64-Debug/src/Tutorial_02/cmake_install.cmake")
  include("C:/Users/aconc/Desktop/Mis_archivos/Computer_Science_UNSA/Computación Gráfica/Laboratorio/GLFW_GLAD_GLUT_GLEW_cmake_project/out/build/x64-Debug/src/Hello_Triangle/cmake_install.cmake")
  include("C:/Users/aconc/Desktop/Mis_archivos/Computer_Science_UNSA/Computación Gráfica/Laboratorio/GLFW_GLAD_GLUT_GLEW_cmake_project/out/build/x64-Debug/src/hw0/cmake_install.cmake")

endif()

