#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , ordena(new minhaNamespace::Ordena)
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

        std::getline(arquivo, linha);

        if(ui->comboBoxPorTipo->currentIndex() == 0) ordena->setPorNome(true);

        while(!arquivo.eof()) {
            ordena->setListaPessoas(ordena->splitPessoa(QString::fromStdString(linha)));

            std::getline(arquivo, linha);
        }

        arquivo.close();

        ui->textEditSaida->setText(ordena->getListaPessoasSemFormatacao());
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
    try {
        if(index == 0) {
            ordena->ordenarListaPorNome();

            ui->textEditSaida->setText(ordena->getListaPessoas());
        }

        if(index == 1) {
            ordena->ordenarListaPorMatricula();

            ui->textEditSaida->setText(ordena->getListaPessoas());
        }
    }  catch (QString &erro) {
        QMessageBox::information(this, "Erro", erro);
    }
}

void MainWindow::on_comboBoxPorAlfabeto_activated(int index)
{
    try {
        if(index == 0) {
            ui->textEditSaida->clear();
            ui->textEditSaida->setText(ordena->getListaAsc());
        }

        if(index == 1) {
            ui->textEditSaida->clear();
            ui->textEditSaida->setText(ordena->getListaDesc());
        }
    }  catch (QString &erro) {
        QMessageBox::information(this, "Erro", erro);
    }
}
