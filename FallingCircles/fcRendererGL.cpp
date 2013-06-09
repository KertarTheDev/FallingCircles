#include "fcRendererGL.h"
#include "fcGameSettings.h"
#include <QMouseEvent>
#include <GL/glu.h>


using namespace NfcGameSettings;

//==========================================================================
//! \brief Default auto generated constructor.
//! Currently just sets up a default scene for testing
CfcRendererGL::CfcRendererGL(QWidget *parent) : QGLWidget(parent)
{
    this->vertexArray = QSharedPointer<QVector<float> >(new QVector<float>);
    this->colorArray = QSharedPointer<QVector<float> >(new QVector<float>);
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
    int widthToUse = nHeight*gameFieldWidth/gameFieldHeight;
    int halfOfUnusedWidth = (nWidth-widthToUse)/2;

    glViewport(halfOfUnusedWidth,0,(GLint)widthToUse,(GLint)nHeight);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    //The coordinate system should be set up based on the playing field properties
    //This is just a placeholder for now.
    //left right bottom top zNear zFar
    glOrtho(0.0,gameFieldWidth, gameFieldHeight,0.0, 0.0,1.0);
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
void CfcRendererGL::mouseReleaseEvent(QMouseEvent *mouseEvent)
{
    QPoint pixelPos = mouseEvent->pos();

    GLdouble modelView[16];
    glGetDoublev(GL_MODELVIEW_MATRIX, modelView);

    GLdouble projection[16];
    glGetDoublev(GL_PROJECTION_MATRIX, projection);

    GLint viewport[4];
    glGetIntegerv(GL_VIEWPORT, viewport);

    GLdouble posX,posY,posZ;
    gluUnProject(pixelPos.rx(),viewport[3]-pixelPos.ry(),0,modelView,projection,viewport,&posX,&posY,&posZ);

    emit signalClicked(QPointF(posX,posY));
}
//==========================================================================
