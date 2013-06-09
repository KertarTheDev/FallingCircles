#pragma once

#include "fcGameFieldGL.h"
#include <QTimer>

class CfcRendererGL;

class CfcGameEngine : QObject
{
    Q_OBJECT

private:
    CfcGameEngine(){}

public:
    CfcGameEngine(QSharedPointer<CfcRendererGL> renderer);

    void start();

    CfcFallingObjectSP generateCircle();
protected:
    void updateExistingObjects();
    void renderCurrentState();

protected slots:
    void slotUpdateGameState();
    void slotSpawnNewObjects();

protected:
    QTimer mUpdateTimer;
    QTimer mSpawnTimer;
    CfcGameField mGameField;
    QSharedPointer<CfcGameFieldGL> mGameFieldGL;
    QSharedPointer<CfcRendererGL> mRenderer;
};
