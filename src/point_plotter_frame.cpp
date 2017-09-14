//PointPlotterFrame Class
#include <QtGui>

#include "point_plotter_frame.h"

//COnstructor
PointPlotterFrame::PointPlotterFrame(QWidget *parent)
    : QFrame(parent)
{
    //Set the style and focus policy
    setFrameStyle(QFrame::Panel | QFrame::Sunken);
    setFocusPolicy(Qt::StrongFocus);
    //Set the width and height of the resacle function
    fl.setScale(550,550);
    //Set the flags
    hasLine = false;
    hasPoint = false;
}

//Painting event
//Handled by update()
//Data from the FindLine instance
void PointPlotterFrame::paintEvent(QPaintEvent* event) {
	QFrame::paintEvent(event);
    //Set the width and height of the resacle function
    fl.setScale(frameRect().width(),frameRect().height());
    //Define a painter
    QPainter paint(this);

    //Set the pen for painting points
    paint.setPen(QPen(Qt::black, 1));
    //If hasPoint then paint the points
    if (hasPoint) {
        //For loop for painting each points
    	for (int i=0; i<fl.getPointSize(); ++i) {
    		paint.drawEllipse(fl.pointX(i),fl.pointY(i),3,3);
    	}
    }

    //Set the pen for painting lines
    paint.setPen(QPen(Qt::black, 1));
    //If hasLine then paint the lines
    if (hasLine) {
        //For loop for painting each line segments
        //There may be overlaps since the points in a line are not sorted
        //But this does not matter
    	for (int i=0; i<fl.getLineSize(); ++i){
    		for (int j=1; j<fl.lineLength(i); ++j) {
    			paint.drawLine(fl.linePointX(i,j-1),fl.linePointY(i,j-1),fl.linePointX(i,j),fl.linePointY(i,j));
    		}
    	}
    }

}

//Reading from file with certain filename
void PointPlotterFrame::readFromFile(std::string fn) {
    //Call the readFromFile function in the FindLine class
	fl.readFromFile(fn);
    //Set the flag
	hasPoint = true;
	update();
}

//Calling the corresponding methods in FindLine class 
void PointPlotterFrame::fastFind() {
	double t;
    //Call and collect the time
    t = fl.fastFind();
    //Show the time by message box
    QMessageBox timeReminder;
    timeReminder.setWindowTitle("Time");
    timeReminder.setText(QString("Time Used: ")+QString::number(t)+QString("ms."));
    timeReminder.exec();
    //Set the flag
    hasLine = true;
	update();
}

//Calling the corresponding methods in FindLine class 
void PointPlotterFrame::bruteFind() {
	double t;
    //Call and collect the time
    t = fl.bruteFind();
    //Show the time by message box
    QMessageBox timeReminder;
    timeReminder.setWindowTitle("Time");
    timeReminder.setText(QString("Time Used: ")+QString::number(t)+QString("ms."));
    timeReminder.exec();
    //Set the flag
    hasLine = true;
	update();
}
