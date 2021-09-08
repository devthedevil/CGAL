#include <iostream>
#include <fstream> //cpp header for file handling
#include <QtGui>
#include <QApplication>
#include <QGraphicsScene>
#include <QPen>  //QT header for colors and styles
#include <QGraphicsView>
#include <CGAL/Qt/GraphicsViewNavigation.h>
#include <CGAL/Cartesian.h>  //CGAL header for Cartesian coordinates
#include <CGAL/Point_2.h>    //CGAL header for 2D points

//Define datatype Point_2
typedef CGAL::Cartesian<double> K;  // define type K as Cartesian coordinate
typedef K::Point_2 Point_2;     // define type Point_2 as 2D Cartesian point

int main(int argc, char **argv)
{
std::ifstream iFile("input.txt", std::ios::in); //Open file for reading
Point_2 p1, p2;    //Declare a variable of type Point_2


//iFile >> p1;
//iFile >> p2;


QApplication app(argc, argv);
QGraphicsScene scene;
scene.setSceneRect(0,0, 300, 300); //Set window size of your choice

 
QPen pen; //Declare a variable of type Pen
pen.setColor(Qt::green); // Set the color of pen as GREEN


while(iFile >> p1 && iFile >> p2) //read input points into variable p
scene.addLine(QLineF(p1.x(),p1.y(),p2.x(),p2.y()), pen);


QGraphicsView* view = new QGraphicsView(&scene);
CGAL::Qt::GraphicsViewNavigation navigation;
view->installEventFilter(&navigation);
view->viewport()->installEventFilter(&navigation);
view->setRenderHint(QPainter::Antialiasing);
view->show();
return app.exec();
}
