#pragma once

#include "fcGameFieldGL.h"
#include <QTimer>

class CfcRendererGL;

class CfcGameEngine : public QObject
{
    Q_OBJECT

private:
    CfcGameEngine(QObject *parent = 0):QObject(parent){}

public:
    CfcGameEngine(QSharedPointer<CfcRendererGL> renderer, QObject *parent = 0);

    void start();

signals:
    void signalCurrentScore(int score);

protected:
    void updateExistingObjects();
    void renderCurrentState();
    CfcFallingObjectSP generateCircle();
    void increaseScore(int pointsToAdd);
    void decreaseScore(int pointsToAdd);

protected slots:
    void slotUpdateGameState();
    void slotSpawnNewObjects();
    void slotHandleClick(QPointF pos);

protected:
    QTimer mUpdateTimer;
    QTimer mSpawnTimer;
    CfcGameField mGameField;
    QSharedPointer<CfcGameFieldGL> mGameFieldGL;
    QSharedPointer<CfcRendererGL> mRenderer;
    int mScore;
};
