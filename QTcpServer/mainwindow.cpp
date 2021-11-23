#include "mainwindow.h"
#include "ui_mainwindow.h"

QFile *openFileForRead (const QString &fileName)
{
    std::unique_ptr<QFile> file(new QFile(fileName));
    if (!file->open(QIODevice::ReadOnly)) {
        QMessageBox::information(new QMessageBox, QMessageBox::tr("Error"),
                                 QMessageBox::tr("Unable to open the file %1: %2.")
                                 .arg(QDir::toNativeSeparators(fileName),
                                      file->errorString()));
        return nullptr;
    }
    return file.release();
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}
MainWindow::~MainWindow()
{
    delete ui;
    ServerStatus = 0;
    file->close();
}

void MainWindow::on_starting_clicked()
{

    tcpServer = new QTcpServer(this);
    connect(tcpServer, SIGNAL(newConnection()), this, SLOT(NewUser()));
    if (!tcpServer->listen(QHostAddress::Any, 33333) && ServerStatus == 0)
    {
        ui->textinfo->append("Unable to start the server:" + tcpServer->errorString());
    }
    else
    {
        ServerStatus = 1;
        ui->textinfo->append("Server is working! TCPSocket listen on port 33333");
    }
}

void MainWindow::on_stoping_clicked()
{
    if(ServerStatus == 1){
        foreach(int i,SClients.keys())
        {
            SClients[i]->close();
            SClients.remove(i);
        }
        tcpServer->close();
        ui->textinfo->append("Server has been stoped!");
        ServerStatus = 0;
    }
}

void MainWindow::NewUser()
{
    if(ServerStatus == 1)
    {
        QTcpSocket* clientSocket = tcpServer->nextPendingConnection();
        int idusersocs = clientSocket->socketDescriptor();
        clientSocket->waitForReadyRead(500);
        SClients[idusersocs] = clientSocket;
        ui->textinfo->append("New conection! Socket descriptor = " + QString::number(idusersocs));
        if(SClients[idusersocs]->state() == QAbstractSocket::ConnectedState)
        {
            file = openFileForRead ("responce.txt");
            ui->textinfo->append( "Sending file to the client! Socket descriptor = " + QString::number(idusersocs));
            QFileInfo fileInfo(*file);
            QString fileName(fileInfo.fileName());
            qDebug() << fileName;
            QByteArray rawFile;
            rawFile = file->readAll();
               SClients[idusersocs]->write(rawFile);

            SClients[idusersocs]->close();
            SClients.remove(idusersocs);
            ui->textinfo->append("Socket is disconected! Socket descriptor = " + QString::number(idusersocs));
        }

//        connect(clientSocket,SIGNAL(readyRead()),this, SLOT(slotReadClient()));
    }
}

