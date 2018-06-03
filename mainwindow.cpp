#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_updateList_clicked()
{
    //Cleaning combolist
    ui->comboBox_serialSlots->clear();

    QList<QString> serialPorts = SerialClient::getSerialPorts();

    //Filling combo list
    foreach (QString serialPort, serialPorts)
    {
        ui->comboBox_serialSlots->addItem(serialPort);
    }

    //Send some debug info
    this->consoleLog("SUCCESS: Serial ports list updated!");
}

void MainWindow::on_pushButton_connectSerialPort_clicked()
{
    //Getting portname and baudrate
    QString portName = ui->comboBox_serialSlots->currentText();

    if(serialPort != Q_NULLPTR)
    {
        if(serialPort->isOpen())
            serialPort->disconnect();

        delete serialPort;
        serialPort = Q_NULLPTR;
    }

    serialPort = new SerialClient();

    //connecting serial signals
    connect(serialPort, SIGNAL(connectionStatusChanged(bool)), this, SLOT(setSerialPortStatus(bool)));
    connect(serialPort, SIGNAL(readyRead()), this, SLOT(serialDataReceivingSlot()));


    if(serialPort->connect(portName, this->baud))
    {
        this->consoleLog("SUCCESS: You're now connected to serial port!!");
    }
    else
    {
        this->consoleLog("FAILED2CONN: " + serialPort->getLastError());
        if(serialPort != Q_NULLPTR || serialPort)
        {
            delete serialPort;
            serialPort = Q_NULLPTR;
        }
    }
}

void MainWindow::on_pushButton_disconnectSerialPort_clicked()
{
    if(serialPort == Q_NULLPTR || !serialPort)
    {
        this->consoleLog("FAILED: You're not connected to serial port!");
        return;
    }

    if(this->serialPort->disconnect())
    {
        this->consoleLog("SUCCESS: DISCONNECTED!");
    }
    else
    {
        this->consoleLog("FAILED: " + serialPort->getLastError());
    }
}

void MainWindow::consoleLog(QString str)
{
    this->ui->testEditSerialConsole->append("[" + QTime::currentTime().toString() + "] " +  str);
}

void MainWindow::on_pushButton_Send_clicked()
{
    if(serialPort == Q_NULLPTR)
    {
        this->consoleLog("SEND FAILED: Please connect to serial port first!");
        return;
    }

    QString sendStr = ui->lineEditData->text();

    qint64 bytesWritten = serialPort->write(sendStr);
    if( bytesWritten > 0)
    {
        QString dbgStr = "SUCCESS SEND (" + QString::number(bytesWritten) + "bytes): " + sendStr;
        this->consoleLog(dbgStr);
    }
    else
    {
        this->consoleLog("FAILED: " + serialPort->getLastError());
    }
}

void MainWindow::on_pushButton_Clear_clicked()
{
    ui->lineEditData->clear();
}
