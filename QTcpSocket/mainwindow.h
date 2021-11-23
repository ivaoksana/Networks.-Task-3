#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork>
#include <QTcpSocket>
#include <QTcpServer>
#include <QObject>
#include <QByteArray>
#include <QDebug>
#include <QMessageBox>
#include <QDesktopServices>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QTcpSocket* TcpSocket;
    QFile* file;

private slots:

    void socketReady();
    void sockesDisconect();

    void on_ConectToServer_clicked();
    void on_ServerPort_LE_editingFinished();
    void on_OpenTheFile_clicked();

private:
    Ui::MainWindow *ui;
};
QFile *openFileForWrite(const QString &fileName);
#endif // MAINWINDOW_H
