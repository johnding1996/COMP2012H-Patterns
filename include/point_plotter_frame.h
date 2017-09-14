//PointPlotterFrame Class
//Inherit from the QFrame
//The frame to draw all the points and lines
#include <QFrame>
#include <string>
#include <vector>

#include "findline.h"

#ifndef POINT_PLOTTER_FRAME
#define POINT_PLOTTER_FRAME

class PointPlotterFrame : public QFrame
{
    Q_OBJECT

public:
    //Constructor
    PointPlotterFrame(QWidget *parent = 0);
    //Reading from file with certain filename
    void readFromFile(std::string);

public slots:
    //Slots to respond the QAction trigger signal
    //Calling the corresponding methods in FindLine class 
	void fastFind();
	void bruteFind();

protected:
    //Painting event
    //Handled by update()
    //Data from the FindLine instance
    void paintEvent(QPaintEvent*);

private:
    //The instance of FindLine class
    //Finishing all the non-GUI part
    FindLine fl;
    //Flags for painting
	bool hasPoint;
	bool hasLine;
};

#endif
