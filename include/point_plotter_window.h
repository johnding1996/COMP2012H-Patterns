//PointPlotterWindow Class
//Inherit form the QWidget class
//The main GUI
#include <QFrame>
#include <QToolBar>
#include <QWidget>
#include <string>

#include "point_plotter_frame.h"
#include "findline.h"

#ifndef POINT_PLOTTER_WINDOW
#define POINT_PLOTTER_WINDOW

class PointPlotterFrame;

class PointPlotterWindow : public QWidget
{
    Q_OBJECT

public:
	//Constructor
	//Pass the file name as argument
	//Default as "input.txt"
    PointPlotterWindow(std::string fn = "input.txt");

private:
	//Instances of the PointerPlotterFrame
    PointPlotterFrame *plotterFrame;
    //QToolBar for controling
    QToolBar *toolbar;
    //QAction for signals
    QAction *runfast;
    QAction *runbrute;
    //Filename
    std::string filename;
};

#endif