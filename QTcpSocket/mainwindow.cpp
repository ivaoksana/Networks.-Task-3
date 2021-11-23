#include "mainwindow.h"
#include "ui_mainwindow.h"
QFile *openFileForWrite(const QString &fileName)
{
   std::unique_ptr <QFile> file(new QFile(fileName));
    if (!file->open(QIODevice::WriteOnly)) {
        QMessageBox::information(new QMessageBox, QMessageBox::tr("Error"),
                                 QMessageBox::tr("Unable to save the file %1: %2.")
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
    this->ui->OpenTheFile->setEnabled(false);
    TcpSocket = new QTcpSocket(this);
    connect(TcpSocket, SIGNAL(readyRead()), this, SLOT(socketReady()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::sockesDisconect()
{
    TcpSocket->deleteLater();
}

void MainWindow::socketReady()
{
    if (TcpSocket->waitForConnected(500))
    {
        TcpSocket->waitForReadyRead(500);
        ui->textinfo->append( "Ready to receive a file from the server!");
        QByteArray rawFile;
        rawFile = TcpSocket->readAll();
        file = openFileForWrite("responce.txt");
        if(rawFile.size() == 0) ui->textinfo->append( "The file is empty!");
        else
        {
            ui->textinfo->append( "The file \"responce.txt\" has been resived from the server!");
            file->write(rawFile);
            ui->textinfo->append( "The file is ready for opening!");
            this->ui->OpenTheFile->setEnabled(true);
        }
        file->close();
    }
}

void MainWindow::on_ConectToServer_clicked()
{
    int ServerPort = this->ui->ServerPort_LE->text().toInt();
    TcpSocket->connectToHost("127.0.0.1", ServerPort);
    ui->textinfo->append( "You are conected to the server. Server port = " + QString::number(ServerPort));
}

void MainWindow::on_ServerPort_LE_editingFinished()
{
    if( this->ui->ServerPort_LE->text().isEmpty())
        this->ui->ConectToServer->setEnabled(false);
}

void MainWindow::on_OpenTheFile_clicked()
{
        if(!file->open(QIODevice::ReadOnly | QIODevice::Text))
        {
            ui->textinfo->append( "Unable to open the file \"responce.txt\"!");
        }
        else
        {
            QDesktopServices::openUrl(QUrl::fromLocalFile("responce.txt"));
            ui->textinfo->append( "The file \"responce.txt\" has been open successfully!");
        }
}

