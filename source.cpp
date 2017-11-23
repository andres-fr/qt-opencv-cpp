/********************************************************************************
** Form generated from reading UI file 'design.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef SOURCE_H
#define SOURCE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *checkBox;
    QLabel *label;
    QPushButton *pushButton;
    QFrame *frame;
    QRadioButton *radioButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(906, 854);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        checkBox = new QCheckBox(centralwidget);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        verticalLayout_2->addWidget(checkBox);

        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_2->addWidget(label);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout_2->addWidget(pushButton);

        frame = new QFrame(centralwidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);

        verticalLayout_2->addWidget(frame);

        radioButton = new QRadioButton(centralwidget);
        radioButton->setObjectName(QStringLiteral("radioButton"));

        verticalLayout_2->addWidget(radioButton);


        gridLayout->addLayout(verticalLayout_2, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        checkBox->setText(QApplication::translate("MainWindow", "CheckBox", 0));
        label->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        pushButton->setText(QApplication::translate("MainWindow", "PushButton", 0));
        radioButton->setText(QApplication::translate("MainWindow", "RadioButton", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow:
    public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // SOURCE_H


// class Ui_MainWindow{
// public:
//     void setupUi(QMainWindow *MainWindow)
//       void retranslateUi(QMainWindow *MainWindow)
