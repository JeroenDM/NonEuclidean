#include <iostream>
#include <stdio.h>

#include "NonEuclidean/Vector.h"

#include <GL/glew.h>
#include <GL/glut.h>

int main(int argc, char** argv) {
    std::cout << "Hello bazel\n";

    Vector3 v(0.0);
    Vector3 v2(1.0, 2.0, 3.0);
    v2.Normalize();
    std::cout << "result: " << v + v2 << "\n";

    glutInit(&argc, argv);
    glutCreateWindow("GLEW Test");
    GLenum err = glewInit();
    if (GLEW_OK != err)
    {
    /* Problem: glewInit failed, something is seriously wrong. */
    fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
    }
    fprintf(stdout, "Status: Using GLEW %s\n", glewGetString(GLEW_VERSION));
}