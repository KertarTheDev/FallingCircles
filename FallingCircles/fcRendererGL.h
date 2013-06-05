#pragma once

#include <QGLWidget>

//! \brief This class is responsible for all OpenGL interactions
//! necessary to render the game world on screen
class CfcRendererGL : public QGLWidget
{
    Q_OBJECT
public:
    explicit CfcRendererGL(QWidget *parent = 0);

protected:

    /*virtual*/ void initializeGL();
    /*virtual*/ void resizeGL(int nWidth, int nHeight);
    /*virtual*/ void paintGL();

protected:
    static const int verticesPerPrimitive = 3; //triangles
    static const int coordsPerVertex = 2;      // 2d vertex coordinates
    static const int valuesPerColor = 3;       // RGB color format

    //! These arrays must be set up to point to the scene data
    //! since they are used for constructing OpenGL primitives
    //! QSharedPointers are used to avoid adding a destructor and
    //! enable safe passing of array pointers from outside :)
    QSharedPointer<QVector<float> > vertexArray;
    QSharedPointer<QVector<float> > colorArray;
};
