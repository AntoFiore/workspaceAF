#include "MainWindow.h"

#include <QApplication>
#include "Controller.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Controller c;
   if ( ! c.init_All() ){
       exit (-1);
   }
  //  MainWindow w;
  //  w.show();
    return a.exec();
}
