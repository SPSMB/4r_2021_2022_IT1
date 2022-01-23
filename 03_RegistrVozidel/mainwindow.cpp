#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->registr->addItem("Fiat");

    for(int i = 1; i < 10; i++){
        ui->registr->addItem(QString::number(i) + ". auto");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_registr_currentItemChanged(
        QListWidgetItem *current, QListWidgetItem *previous)
{
    QString text;
    if(current == NULL){
        text = "Uz neni co zobrazit.";
    } else {
        text = current->text();
    }

    ui->label_vyber->setText(text);
}

void MainWindow::on_btn_odstranit_clicked()
{
    int radek = ui->registr->currentRow();
    QListWidgetItem * polozka = ui->registr->takeItem(radek);
    if(polozka == NULL){
        return;
    }
    delete polozka; // odstranim polozku z pameti
}

void MainWindow::on_btn_prejmenovat_clicked()
{
    QString novytext = QInputDialog::getText(
                this, "Info", "Prosim, zadejte nove jmeno auta.");
    if(novytext.isEmpty()){
        QMessageBox::warning(this, "Upozorneni",
                             "Text nemuze byt prazdny, nic se nestane.");
        return;
    }
    QListWidgetItem * polozka = ui->registr->currentItem();
    if(polozka != NULL){
        QMessageBox::StandardButton btn = QMessageBox::question(this,
                                          "Otazka", "Skutecne chcete prejmenovat?");
        if(btn == QMessageBox::Yes){
            polozka->setText(novytext);
        } else {
            QMessageBox::warning(this, "Upozorneni", "Nic se nestalo.");
        }
    }
}
