#pragma once

#include <QGLWidget>

//! \brief This class is responsible for all OpenGL interactions
//! necessary to render the game world on screen
class CfcRendererGL : public QGLWidget
{
    Q_OBJECT
public:
    explicit CfcRendererGL(QWidget *parent = 0);

    void setVertexArray(QSharedPointer<QVector<float> > vArray){this->vertexArray = vArray;}
    void setColorArray(QSharedPointer<QVector<float> > cArray){this->colorArray = cArray;}

protected:

    /*virtual*/ void initializeGL();
    /*virtual*/ void resizeGL(int nWidth, int nHeight);
    /*virtual*/ void paintGL();

protected:
    //! These arrays must be set up to point to the scene data
    //! since they are used for constructing OpenGL primitives
    //! QSharedPointers are used to avoid adding a destructor and
    //! enable safe passing of array pointers from outside :)
    QSharedPointer<QVector<float> > vertexArray;
    QSharedPointer<QVector<float> > colorArray;
};
