//The main cpp file for compling the PointPlotter program
#include <QtGui>
#include <iostream>
#include <stdlib.h>

#include "point_plotter_window.h"

//Main program
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    PointPlotterWindow* window;

    //Check if input the user specified filename
    if (argc<2) window = new PointPlotterWindow;
    //If then, pass it to the window
    else window = new PointPlotterWindow(argv[1]);

    window->show();
    
    return app.exec();
}