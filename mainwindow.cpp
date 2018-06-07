#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->ui->comboBox_BaudRates->addItems({"1200", "2400", "4800", "9600", "14400", "19200", "38400", "57600", "115200"});
    this->ui->comboBox_BaudRates->setCurrentIndex(3);
    this->baud = QSerialPort::Baud9600;
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
        {
            consoleLog("ERROR: You must disconnect first!");
            return;
        }
    }

    serialPort = new SerialClient();

    //connecting serial signals
    connect(serialPort, SIGNAL(connectionStatusChanged(bool)), this, SLOT(setSerialPortStatus(bool)));
    connect(serialPort, SIGNAL(readyRead()), this, SLOT(serialDataReceivingSlot()));


    if(serialPort->connect(portName, this->baud))
    {
        this->consoleLog("SUCCESS: CONNECTED!!1");
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
    if(serialPort == Q_NULLPTR || serialPort == 0 || !this->serialPort->isOpen())
    {
        this->consoleLog("FAILED: You're not connected to serial port!");
        return;
    }    

    if(this->serialPort->isOpen())
    {
        if(this->serialPort->disconnect())
        {
            this->consoleLog("SUCCESS: DISCONNECTED!");
            this->setSerialPortStatus(false);
        }
        else
        {
            this->consoleLog("FAILED: " + serialPort->getLastError());
            return;
        }
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

    QByteArray sendStr =  ui->lineEditData->text().toUtf8();

    qint64 bytesWritten = serialPort->write(sendStr);
    if( bytesWritten > 0)
    {
        QString dbgStr = "SEND (" + QString::number(bytesWritten) + "bytes): " + sendStr;
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

void MainWindow::setSerialPortStatus(bool connected)
{
    this->ui->connectionStatusLabel->setText( connected==true?("CONNECTED"):("NOT CONNECTED") );
}

void MainWindow::serialDataReceivingSlot()
{
    char buffer[64] = {0};
    qint64 readBytes = serialPort->read(buffer, sizeof(buffer));

    consoleLog("RECV (" + QString::number(readBytes) + " bytes): " + buffer);
}

void MainWindow::on_comboBox_BaudRates_currentIndexChanged(int index)
{
    this->baud = (SerialClient::BaudRate)index;
}
