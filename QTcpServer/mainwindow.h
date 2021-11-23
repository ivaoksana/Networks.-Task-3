#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork>
#include <QTcpSocket>
#include <QTcpServer>
#include <QObject>
#include <QByteArray>
#include <QMessageBox>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_starting_clicked();
    void on_stoping_clicked();
    void NewUser();



private:
    Ui::MainWindow *ui;
    QTcpServer *tcpServer;
    int ServerStatus;// 1 if server listen, 0 if not
    QMap<int, QTcpSocket *> SClients;
    QFile* file;
};
QFile *openFileForRead (const QString &fileName);
#endif // MAINWINDOW_H
