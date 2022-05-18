#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionAbrir_triggered()
{
    try {
        std::ifstream arquivo;

        QString nomeDoArquivo = QFileDialog::getOpenFileName(this, "Abrir arquivo",
                                                             QDir::currentPath(), "Arquivos texto (*.csv *.txt)");

        if(nomeDoArquivo.isEmpty()) throw QString("Arquivo não selecionado.");

        arquivo.open(nomeDoArquivo.toStdString().c_str());

        if(!arquivo.is_open()) throw QString("Erro: arquivo não pode ser aberto.");

        std::string linha = "";
        QString texto = "";

        std::getline(arquivo, linha);

        //        while(!arquivo.eof()) {
        //            texto += QString::fromStdString(linha);
        //            texto += "\n";

        //            std::getline(arquivo, linha);
        //        }

        while(!arquivo.eof()) {
            ordena.setListaPessoas(ordena.splitPessoa(QString::fromStdString(linha)));
        }

        arquivo.close();

        ui->textEditSaida->setText(ordena.getListaPessoas());
    }  catch (QString &erro) {
        QMessageBox::information(this, "Erro", erro);
    }
}

void MainWindow::on_actionNovo_triggered()
{
    try {
        QString texto = ui->textEditSaida->toPlainText();

        if(texto.isEmpty()) throw QString("Arquivo vazio.");

        std::ofstream arquivo;

        QString nomeDoArquivo = QFileDialog::getSaveFileName(this, "Novo arquivo",
                                                             QDir::currentPath(), "Arquivos texto (*.csv *.txt)");

        if(nomeDoArquivo.isEmpty()) throw QString("Arquivo não selecionado.");


        arquivo.open(nomeDoArquivo.toStdString().c_str());

        if(!arquivo.is_open()) throw QString("Erro: arquivo não pode ser criado.");

        arquivo << texto.toStdString().c_str() << std::endl;

        arquivo.close();

        ui->textEditSaida->clear();
    }  catch (QString &erro) {
        QMessageBox::information(this, "Erro", erro);
    }
}


void MainWindow::on_actionLimpar_triggered()
{
    try {
        ui->textEditSaida->clear();
    }  catch (QString &erro) {
        QMessageBox::information(this, "Erro", erro);
    }
}

void MainWindow::on_pushButtonAdicionar_clicked()
{
    try {
        QString texto = ui->textEditSaida->toPlainText();

        if(texto.isEmpty()) throw QString("Arquivo vazio.");

        std::fstream arquivo;

        QString nomeDoArquivo = QFileDialog::getOpenFileName(this, "Novo Arquivo",
                                                             QDir::currentPath(), "Arquivos texto (*.csv *.txt)");

        if(nomeDoArquivo.isEmpty()) throw QString("Arquivo não selecionado.");

        arquivo.open(nomeDoArquivo.toStdString().c_str(), std::ios::out | std::ios::app);

        if(!arquivo.is_open()) throw QString("Erro: arquivo não pode ser criado.");

        arquivo<< "\n" << texto.toStdString().c_str() << std::endl;

        arquivo.close();

        ui->textEditSaida->clear();
    }  catch (QString &erro) {
        QMessageBox::information(this, "Erro", erro);
    }
}


void MainWindow::on_comboBoxPorTipo_activated(int index)
{
    if(index == 0) ordena.setPorNome(true);
    if(index == 1) ordena.setPorNome(false);
}


void MainWindow::on_comboBoxPorAlfabeto_activated(int index)
{

}
