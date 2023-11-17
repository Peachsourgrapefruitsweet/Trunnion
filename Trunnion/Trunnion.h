#pragma once

#include <QtWidgets/QDialog>
#include "ui_Trunnion.h"

class Trunnion : public QDialog
{
    Q_OBJECT

public:
    Trunnion(QWidget *parent = nullptr);
    ~Trunnion();

private:
    Ui::TrunnionClass ui;
};
