#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setSceneRect(0,0,900,700);

    QLineF line1 = QLine(0,0,100,200);
    scene->addLine(line1, QPen(QColor::fromRgb(10,20,30)));

    automobil = scene->addRect(500,100,100,100,QPen(),QBrush(Qt::green));

    // vytvoreni letadla
    airbus = new Letadlo();
    scene->addItem(airbus);
    airbus->setPos(0,190);

    // obsluha casovace
    timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &MainWindow::obsluhaCasovace);
    timer->setInterval(20);
    //timer->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    qDebug() << "Stisknuto tlacitko " << event->key();
    if(event->key() == Qt::Key_W){
        // nahoru
        airbus->setY(airbus->y()-10);
    } else if(event->key() == Qt::Key_S){
        // dolu
        airbus->setY(airbus->y()+10);
    } else if(event->key() == Qt::Key_A){
        // doleva
        airbus->setX(airbus->x()-10);
    } else if(event->key() == Qt::Key_D){
        // doprava
        if(airbus->x() != ui->graphicsView->width() - airbus->height()){
            airbus->setX(airbus->x()+10);
        }
    }
}

void MainWindow::obsluhaCasovace()
{
    if(airbus->x() == ui->graphicsView->width() - airbus->boundingRect().width()
        || airbus->collidesWithItem(automobil)){
        timer->stop();
    } else {
        airbus->setX(airbus->x()+5);
        QString s = ui->console->toPlainText();
        QString novy("\nX Pozice letadla:");
        novy.append(QString::number(airbus->x()));
        s.append(novy);

        qDebug() << "X Pozice letadla: " << airbus->x();

        ui->console->setText(s);
    }
}


void MainWindow::on_tlacitko1_clicked()
{
    timer->start();
    automobil->setBrush(QBrush(Qt::yellow));
}
