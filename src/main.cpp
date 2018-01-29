#include "mainwindow.hpp"

#include <iostream>

#include <QApplication>
#include <QLibraryInfo>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    auto currLocale = QLocale::system();

    QTranslator qtTranslator;
    qtTranslator.load("qt_" + currLocale.name(),
                      QLibraryInfo::location(QLibraryInfo::TranslationsPath));
    app.installTranslator(&qtTranslator);

    QTranslator appTranslator;
    appTranslator.load("hello-qt5-" + currLocale.name());
    app.installTranslator(&appTranslator);

    MainWindow w;
    w.show();

    return app.exec();
}
