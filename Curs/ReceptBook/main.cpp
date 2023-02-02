#include "mainwindow.h"

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QApplication>
#include <QtWidgets>

void loadModules(QSplashScreen *psplash)
{

    for (int i = 0; i < 100; i++ )
    {
        psplash->showMessage("Loading modules: "
                             + QString::number(i) + "%",
                             Qt::AlignCenter|Qt::AlignBottom,
                             QColor(252, 238, 251)
                             );
        qApp->processEvents();
        Sleep(40);
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QSplashScreen splash(QPixmap("C:\\ProjectsQt\\Curs\\src\\loading.png"));
    splash.show();
    w.setWindowTitle("RecipeBook");
    loadModules(&splash);
    splash.finish(&w);

    w.show();
    return a.exec();
}
