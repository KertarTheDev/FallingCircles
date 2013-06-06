#include "fcRendererGL.h"
#include "fcFallingCircleGL.h"
//==========================================================================
//! \brief Default auto generated constructor.
//! Currently just sets up a default scene for testing
CfcRendererGL::CfcRendererGL(QWidget *parent) : QGLWidget(parent)
{
    //top left corner of bounding box, unused speed, unsused score, radius
    CfcFallingCircle testCircle(QPointF((float)qrand()/RAND_MAX,(float)qrand()/RAND_MAX), 1.0, 1.0, 0.06);
    CfcFallingCircleGL testCircleGL(&testCircle);

    this->vertexArray = testCircleGL.getVertexArray();
    this->colorArray = testCircleGL.getColorArray();
}
//==========================================================================
//! \brief Does initial set up of general opengl window properties
void CfcRendererGL::initializeGL()
{
    glEnable(GL_POLYGON_SMOOTH); //2d anti-aliasing
    glClearColor(0.3,0.4,0.7,1.0); // default background colour

// could be useful if I ever decide to go 3D
//    glEnable(GL_DEPTH_TEST);

// could be useful if I'll need alpha transparency
//    glEnable(GL_BLEND);
//    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
}
//==========================================================================
//! \brief Resize event handler. Updates viewport geometry.
void CfcRendererGL::resizeGL(int nWidth, int nHeight)
{
    glViewport(0,0,(GLint)nWidth,(GLint)nHeight);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    //The coordinate system should be set up based on the playing field properties
    //This is just a placeholder for now.
    //left right bottom top zNear zFar
    glOrtho(0.0,1.0, 0.0,1.0, 0.0,1.0);
}
//==========================================================================
//! \brief Renders current scene using vertex arrays
void CfcRendererGL::paintGL()
{
//Clear previous frame
    glClear(GL_COLOR_BUFFER_BIT /*| GL_DEPTH_BUFFER_BIT*//*no depth buffer so far*/);

//Set up the vertex array pointer
    glEnableClientState(GL_VERTEX_ARRAY);
    //coordinates format, float values, vertices go directly one after each other, pointer to the first coordinate
    glVertexPointer(coordsPerVertex, GL_FLOAT, 0, this->vertexArray->data());

//Set up the corresponding colour array pointer
    glEnableClientState(GL_COLOR_ARRAY);
    //colour format, float values, no filler data between colours, pointer to the first vertex colour
    glColorPointer(valuesPerColor, GL_FLOAT, 0, this->colorArray->data());

//Send the primitives for rendering
    int numOfPrimitives = this->vertexArray->size()/coordsPerVertex; //count how many triangles are inside
    glDrawArrays(GL_TRIANGLES, 0, numOfPrimitives);

//Restore the drawing context
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_NORMAL_ARRAY);
}
//==========================================================================
