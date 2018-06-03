/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGroupBox *groupBox_SerialConnection;
    QPushButton *pushButton_updateList;
    QComboBox *comboBox_serialSlots;
    QPushButton *pushButton_disconnectSerialPort;
    QLabel *statusLabel;
    QLabel *arduinoConnectionStatusLabel;
    QPushButton *pushButton_connectSerialPort;
    QGroupBox *groupBox_Console;
    QTextEdit *testEditSerialConsole;
    QGroupBox *groupBox_Data;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QLineEdit *lineEditData;
    QPushButton *pushButton_Send;
    QPushButton *pushButton_Clear;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(753, 445);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        groupBox_SerialConnection = new QGroupBox(centralWidget);
        groupBox_SerialConnection->setObjectName(QStringLiteral("groupBox_SerialConnection"));
        groupBox_SerialConnection->setGeometry(QRect(20, 10, 221, 221));
        pushButton_updateList = new QPushButton(groupBox_SerialConnection);
        pushButton_updateList->setObjectName(QStringLiteral("pushButton_updateList"));
        pushButton_updateList->setGeometry(QRect(10, 60, 181, 21));
        comboBox_serialSlots = new QComboBox(groupBox_SerialConnection);
        comboBox_serialSlots->setObjectName(QStringLiteral("comboBox_serialSlots"));
        comboBox_serialSlots->setGeometry(QRect(10, 30, 181, 21));
        pushButton_disconnectSerialPort = new QPushButton(groupBox_SerialConnection);
        pushButton_disconnectSerialPort->setObjectName(QStringLiteral("pushButton_disconnectSerialPort"));
        pushButton_disconnectSerialPort->setGeometry(QRect(10, 150, 181, 21));
        statusLabel = new QLabel(groupBox_SerialConnection);
        statusLabel->setObjectName(QStringLiteral("statusLabel"));
        statusLabel->setGeometry(QRect(10, 180, 51, 21));
        arduinoConnectionStatusLabel = new QLabel(groupBox_SerialConnection);
        arduinoConnectionStatusLabel->setObjectName(QStringLiteral("arduinoConnectionStatusLabel"));
        arduinoConnectionStatusLabel->setGeometry(QRect(70, 180, 121, 21));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        arduinoConnectionStatusLabel->setFont(font);
        pushButton_connectSerialPort = new QPushButton(groupBox_SerialConnection);
        pushButton_connectSerialPort->setObjectName(QStringLiteral("pushButton_connectSerialPort"));
        pushButton_connectSerialPort->setGeometry(QRect(10, 120, 181, 21));
        groupBox_Console = new QGroupBox(centralWidget);
        groupBox_Console->setObjectName(QStringLiteral("groupBox_Console"));
        groupBox_Console->setGeometry(QRect(250, 10, 491, 221));
        testEditSerialConsole = new QTextEdit(groupBox_Console);
        testEditSerialConsole->setObjectName(QStringLiteral("testEditSerialConsole"));
        testEditSerialConsole->setGeometry(QRect(0, 20, 491, 201));
        testEditSerialConsole->setReadOnly(true);
        groupBox_Data = new QGroupBox(centralWidget);
        groupBox_Data->setObjectName(QStringLiteral("groupBox_Data"));
        groupBox_Data->setGeometry(QRect(20, 240, 721, 141));
        radioButton = new QRadioButton(groupBox_Data);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(20, 30, 61, 23));
        radioButton->setChecked(true);
        radioButton_2 = new QRadioButton(groupBox_Data);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setGeometry(QRect(90, 30, 61, 23));
        lineEditData = new QLineEdit(groupBox_Data);
        lineEditData->setObjectName(QStringLiteral("lineEditData"));
        lineEditData->setGeometry(QRect(10, 60, 701, 25));
        pushButton_Send = new QPushButton(groupBox_Data);
        pushButton_Send->setObjectName(QStringLiteral("pushButton_Send"));
        pushButton_Send->setGeometry(QRect(10, 90, 101, 25));
        pushButton_Clear = new QPushButton(groupBox_Data);
        pushButton_Clear->setObjectName(QStringLiteral("pushButton_Clear"));
        pushButton_Clear->setGeometry(QRect(120, 90, 101, 25));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 753, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Simple Serial Terminal", Q_NULLPTR));
        groupBox_SerialConnection->setTitle(QApplication::translate("MainWindow", "Serial connection", Q_NULLPTR));
        pushButton_updateList->setText(QApplication::translate("MainWindow", "Update list", Q_NULLPTR));
        pushButton_disconnectSerialPort->setText(QApplication::translate("MainWindow", "Disconnect", Q_NULLPTR));
        statusLabel->setText(QApplication::translate("MainWindow", "Status:", Q_NULLPTR));
        arduinoConnectionStatusLabel->setText(QApplication::translate("MainWindow", "NOT CONNECTED", Q_NULLPTR));
        pushButton_connectSerialPort->setText(QApplication::translate("MainWindow", "Connect", Q_NULLPTR));
        groupBox_Console->setTitle(QApplication::translate("MainWindow", "Console", Q_NULLPTR));
        groupBox_Data->setTitle(QApplication::translate("MainWindow", "Data", Q_NULLPTR));
        radioButton->setText(QApplication::translate("MainWindow", "String", Q_NULLPTR));
        radioButton_2->setText(QApplication::translate("MainWindow", "Hex", Q_NULLPTR));
        pushButton_Send->setText(QApplication::translate("MainWindow", "Send", Q_NULLPTR));
        pushButton_Clear->setText(QApplication::translate("MainWindow", "Clear", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
