#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QFileDialog>
#include <fstream> // para arquivos
#include <sstream> // writing to memory (a string)
#include <ordena.h>
#include <pessoa.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionAbrir_triggered();

    void on_actionNovo_triggered();

    void on_actionLimpar_triggered();

    void on_pushButtonAdicionar_clicked();

    void on_comboBoxPorTipo_activated(int index);

    void on_comboBoxPorAlfabeto_activated(int index);

private:
    Ui::MainWindow *ui;
    minhaNamespace::Ordena *ordena;
};
#endif // MAINWINDOW_H
