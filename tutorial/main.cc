#include <iostream>
#include <array>
#include <utility>

// Include glew before freeglut !!
#include <GL/glew.h>
#include <GL/freeglut.h>

#include "NonEuclidean/Vector.h"

struct WindowDimensions
{
    int width;
    int height;
    int x_position;
    int y_position;

    std::pair<float, float> toClipSpace(int x, int y) const
    {
        float x_clip = 2.0 * (double)x / (double)width - 1.0;
        float y_clip = -2.0 * (double)y / (double)height + 1.0;
        return std::make_pair<>(x_clip, y_clip);
    }
};

/* global const as I dont' know how to capture this info in callbacks that are passed to glut. */
WindowDimensions WINDOW_PROPERTIES{1920, 1080, 0, 0};

int setupWindow(int *argc, char **argv)
{
    glutInit(argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(WINDOW_PROPERTIES.width, WINDOW_PROPERTIES.height);
    glutInitWindowPosition(WINDOW_PROPERTIES.x_position, WINDOW_PROPERTIES.y_position);

    return glutCreateWindow("Non euclidean test.");
}

GLuint VBO;
bool IS_MOUSE_PRESSED{false};
float MOUSE_X{0.0};
float MOUSE_Y{0.0};

static void createAndFillVertexBuffer()
{
    // Vector3 vertices[3];
    std::array<Vector3, 3> vertices;
    vertices[0] = Vector3(-0.5, 0.0, 0.0);
    vertices[1] = Vector3(0.5, 0.0, 0.0);
    vertices[2] = Vector3(0.0, 1.0, 0.0);

    glGenBuffers(1, &VBO);              // create handle
    glBindBuffer(GL_ARRAY_BUFFER, VBO); // bind handle to array buffer target
    // write data to the array buffer
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices.data(), GL_STATIC_DRAW);
}

void updateVertexBuffer(float x_pos, float y_pos)
{
    // Vector3 vertices[3];
    std::array<Vector3, 3> vertices;
    vertices[0] = Vector3(-0.5, 0.0, 0.0);
    vertices[1] = Vector3(x_pos, y_pos, 0.0);
    vertices[2] = Vector3(0.0, 1.0, 0.0);

    // glGenBuffers(1, &VBO);              // create handle
    // glBindBuffer(GL_ARRAY_BUFFER, VBO); // bind handle to array buffer target
    // write data to the array buffer
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices.data(), GL_STATIC_DRAW);
}

static void processMouseInput(int key, int state, int x, int y)
{
    if (key == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        auto [xc, yc] = WINDOW_PROPERTIES.toClipSpace(x, y);
        std::cout << "Mouse pressed at " << xc << ", " << yc << "\n";
        // updateVertexBuffer(MOUSE_X, MOUSE_Y);
        // IS_MOUSE_PRESSED = trfloatue;
    }
}

static void windowIsResized(int w, int h)
{
    WINDOW_PROPERTIES.width = w;
    WINDOW_PROPERTIES.height = h;
    std::cout << "window resized to " << w << ", " << h << "\n";
}

static void updateMouseCoordinates(int x, int y)
{
    auto [xc, yc] = WINDOW_PROPERTIES.toClipSpace(x, y);
    updateVertexBuffer(xc, yc);
}

static void render()
{
    // update background color
    static GLclampf c = 0.0;
    glClearColor(0.0, 0.0, c, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glutPostRedisplay();
    c += (1.0 / 256.0);
    if (c >= 1)
        c = 0.0;

    // draw vertex buffer data
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glEnableVertexAttribArray(0);
    // specify how to interpret vertex buffer data
    // index, number of elements, type, normalize, stride, offset
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

    // primitive type, index of the first vertex to draw, number of vertices to process
    glDrawArrays(GL_TRIANGLES, 0, 3);

    glDisableVertexAttribArray(0);

    glutSwapBuffers();
}

int main(int argc, char **argv)
{

    int window = setupWindow(&argc, argv);
    std::cout << "Window create with id: " << window << "\n";

    GLenum res = glewInit();
    if (res != GLEW_OK)
    {
        std::cout << "Failed to initialize glew.\n";
        return 1;
    }

    glClearColor(0.0, 0.0, 1.0, 1.0);
    glEnable(GL_CULL_FACE);
    // change culling settings
    // glFrontFace(GL_CW);
    // glCullFace(GL_FRONT);

    createAndFillVertexBuffer();

    glutDisplayFunc(render);
    glutReshapeFunc(windowIsResized);

    glutMouseFunc(processMouseInput);
    glutMotionFunc(updateMouseCoordinates);

    glutMainLoop();

    return 0;
}