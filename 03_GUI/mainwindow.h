#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <letadlo.h>
#include <QKeyEvent>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QGraphicsScene * scene;
    Letadlo * airbus;
    QTimer * timer;
    QGraphicsRectItem * automobil;

private slots:
    void keyPressEvent(QKeyEvent *event);
    void obsluhaCasovace();
    void on_tlacitko1_clicked();
};
#endif // MAINWINDOW_H
