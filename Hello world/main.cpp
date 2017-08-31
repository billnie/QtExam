#include "mainwindow.h"
#include <QApplication>
#include <QLabel>
#include <QtWidgets>
#include <QHBoxLayout>
#include <QSpinBox>
#include <QSlider>
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    //exam1-hellowrold
    QLabel label("Hello Qt!");
     label.show();
    //exam2-按钮退出
//    QWidget window;
//    window.resize(200, 150);
//    window.setWindowTitle("Button");
//    window.show();

//    QPushButton *btn = new QPushButton("Quit", &window);
//    QObject::connect(btn, SIGNAL(clicked()), &app, SLOT(quit()));
//    btn->move(50,50);
//    btn->show();

    QWidget window;
        window.setWindowTitle("Enter Your Age");

        QSpinBox *spin = new QSpinBox;
        QSlider *slider = new QSlider(Qt::Horizontal);
        spin->setRange(0,130);
        slider->setRange(0,130);

        QObject::connect(spin, SIGNAL(valueChanged(int)), slider, SLOT(setValue(int)));
        QObject::connect(slider, SIGNAL(valueChanged(int)), spin, SLOT(setValue(int)));
        spin->setValue(35);

        QVBoxLayout *layout = new QVBoxLayout;
        layout->addWidget(spin);
        layout->addWidget(slider);

        window.setLayout(layout);
        window.show();

    return app.exec();
}
