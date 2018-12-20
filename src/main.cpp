#include "All-include.h"
#include "Game.h"
#include "mainwindow.h"
#include <QApplication>

std::string givePath() {
   std::string path;
#ifdef __unix__
   char result[256];
   ssize_t count = readlink("/proc/self/exe", result, 256);
   path = std::string(result , (count > 0) ? count : 0);
   for (int i = path.size() - 1 ; path[i] != '/' ; --i)
       path.pop_back();
#endif

// also for windows
   return path;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.showFullScreen();

    return a.exec();
}
