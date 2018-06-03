#include "SerialClient.h"

SerialClient::SerialClient()
{
}

SerialClient::~SerialClient()
{
	if(pSerialPort != Q_NULLPTR)
	{
		if(pSerialPort->isOpen())
			pSerialPort->close();

		delete pSerialPort;
		pSerialPort = Q_NULLPTR;
	}
}

QString SerialClient::getLastError()
{
	return this->lastError;
}

void SerialClient::setLastError(QString error)
{
	this->lastError = error;
}

bool SerialClient::connect(QString portName, BaudRate baudRate)
{
	//Make sure we are not already connected
	if(pSerialPort != Q_NULLPTR || pSerialPort)
	{
		if(pSerialPort && pSerialPort->isOpen())
			pSerialPort->close();

		delete pSerialPort;
		pSerialPort = Q_NULLPTR;
	}

	if(portName.isEmpty())	//If you pass an empty name, pSerialPort will crash!
	{
		this->setLastError("Empty name!!!!! I HATE!!! empty names!!! Don't ever send me an empty name again! Empty names crash me :(!!!");
		return false;
	}

	//Create a new instance
	pSerialPort = new QSerialPort();

	//Connecting signals to slots
	QObject::connect(pSerialPort, SIGNAL(error(QSerialPort::SerialPortError)), this, SLOT(connectionStatusChanged(QSerialPort::SerialPortError)));
	QObject::connect(pSerialPort, SIGNAL(readyRead()), this, SIGNAL(readyRead()));

	//Setting connection params
	pSerialPort->setPortName(portName);
	pSerialPort->setBaudRate(baudRate);

	try
	{
		//Open RW Sessions
		pSerialPort->open(QIODevice::ReadWrite);

		//Check if connection succeed
		if(pSerialPort->isOpen())
		{
			//Clean buffers to throw away garbage from the wires - but it is now working :(
			pSerialPort->flush();
			pSerialPort->clear();
			return true;
		}
		else
		{
			this->setLastError(pSerialPort->errorString());
			return false;
		}
	}
	catch(...)
	{
		this->setLastError("Fatal error when called serialPort.open() function");
		return false;
	}
}

bool SerialClient::disconnect()
{
	if(!pSerialPort)
		return true;

	pSerialPort->close();

	if(!pSerialPort->isOpen())
		return true;

	return false;
}

void SerialClient::connectionStatusChanged(QSerialPort::SerialPortError errNo)
{
	if(errNo == 0)
	{
		emit connectionStatusChanged(true);
	}
	else
	{
		emit connectionStatusChanged(false);
	}
}

qint64 SerialClient::write(QString str)
{
	if(pSerialPort == Q_NULLPTR)
	{
		this->setLastError("Not connected to serial port!");
		return -1;
	}

	if( pSerialPort->isOpen() )
	{
		QByteArray writeData = str.toUtf8();
		return pSerialPort->write( writeData );
	}
	else
	{
		this->setLastError(pSerialPort->errorString());
		return -1;
	}
}

QList<QString> SerialClient::getSerialPorts()
{
	QList<QString> ports;

	//Get serial ports info
	QSerialPortInfo *portsInfo = new QSerialPortInfo;

	//Fetching available ports into a list
	QList<QSerialPortInfo> serialPorts = portsInfo->availablePorts();

	//Filling combo list
	foreach (QSerialPortInfo serialPort, serialPorts)
	{
		ports.push_back(serialPort.portName());
	}

	//clearing pointer we just created
	delete portsInfo;

	return ports;
}

QString SerialClient::readString()
{
	// Read data
	static QByteArray byteArray;
	byteArray += pSerialPort->readAll();

	//we want to read all message not only chunks
	if(!QString(byteArray).contains("\n"))
		return "^_^";

	//sanitize data
	QString data = QString( byteArray ).remove("\r").remove("\n");
	byteArray.clear();

	//Send it to visual console too
	return data;
}

bool SerialClient::isOpen()
{
	if(pSerialPort->isOpen() && pSerialPort->isWritable() && pSerialPort->isReadable())
		return true;
	return false;
}
