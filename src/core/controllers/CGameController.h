#pragma once

#include <memory>

#include <QObject>
#include <QQmlApplicationEngine>

#include "Engine/CGameEngine.h"
#include "implementations/CEnemyTank.h"
#include "implementations/CPlayerTank.h"
#include "interfaces/IController.h"
#include "pod/Point.h"

class CGameController : public QObject, public IController
{
    Q_OBJECT

public:
    explicit CGameController(std::shared_ptr<CGameEngine> engine, QObject *parent = nullptr);
    ~CGameController() override = default;

    void initialize(QQmlApplicationEngine *engine) override;

    Q_INVOKABLE void startGame();
    Q_INVOKABLE void endGame();

private:
    std::shared_ptr<CGameEngine> gameEngine;
};
