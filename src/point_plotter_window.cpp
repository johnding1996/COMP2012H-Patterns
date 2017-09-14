//PointPlotterWindow CLass
#include <QtGui>

#include "point_plotter_window.h"

PointPlotterWindow::PointPlotterWindow (std::string fn): filename(fn) {
    //Initialize the frame and toolbar
    plotterFrame = new PointPlotterFrame;
    toolbar = new QToolBar;
    runfast = toolbar->addAction("Run Fast");
    runbrute = toolbar->addAction("Run Brute");

    //Connect the toolbar signals with the slots of the frame
    connect(runfast, SIGNAL(triggered()), plotterFrame, SLOT(fastFind()));
    connect(runbrute, SIGNAL(triggered()), plotterFrame, SLOT(bruteFind()));

    //Set the layout
    QGridLayout *layout = new QGridLayout;
    layout->addWidget(toolbar, 0, 0, 1, 1);
    layout->addWidget(plotterFrame, 1, 0, 1, 1);
    setLayout(layout);

    //Set the title and size
    setWindowTitle(tr("PointPlotter"));
    resize(600, 600);

    plotterFrame->readFromFile(filename);
}
