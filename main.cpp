#include <QApplication>
#include <QQmlApplicationEngine>
#include <QDeclarativeView>
#include <QDeclarativeContext>
#include <QFile>
#include <QTextStream>

//Reading CpuInfo File by using the QFile-class
QString readfile() {
    QFile file("/proc/cpuinfo");

    if (file.exists() && file.open(QIODevice::ReadOnly))
    {

       QString line = file.readAll();
            return line;
    }
       return "File not found";
}


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QDeclarativeView view;

    QString fileContent = readfile();
    view.rootContext()->setContextProperty("cpuinfo", fileContent);
    view.setSource(QUrl("qrc:/main.qml"));
    view.show();

    return app.exec();
}
