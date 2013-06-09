#include "fcGameFieldGL.h"
#include "fcFallingObjectGL.h"

//==========================================================================
CfcGameFieldGL::CfcGameFieldGL(CfcGameField* gameField)
{
    this->mField = gameField;

    this->mVertexArray  = QSharedPointer<QVector<float> >(new QVector<float>);
    this->mColorArray   = QSharedPointer<QVector<float> >(new QVector<float>);

    this->mVertexArray->reserve(10000);
    this->mColorArray->reserve(15000);
}
//==========================================================================
void CfcGameFieldGL::updateArrays()
{
    int objectCount=this->mField->objectCount();

    this->mVertexArray->clear();
    this->mColorArray->clear();
    for(int i=0;i<objectCount;++i)
    {
        CfcFallingObjectGlSP objectGL = this->mField->object(i)->renderingData();
        //make sure geometry corresponds to current object state
        objectGL->prepareArrays();
        //add the geometry for rendering
        (*this->mVertexArray)+=(*objectGL->getVertexArray());
        (*this->mColorArray)+=(*objectGL->getColorArray());
    }
}
//==========================================================================
