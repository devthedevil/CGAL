using namespace std;

#include <bits/stdc++.h>
#include <fstream> //cpp header for file handling
#include <QtGui>
#include <CGAL/Qt/GraphicsViewNavigation.h>
#include <QApplication> 
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsTextItem> 
#include <QPen> //QT header for colors and styles
#include <CGAL/Cartesian.h> //CGAL header for Cartesian coordinates
#include <CGAL/Point_2.h> //CGAL header for 2D points

typedef CGAL::Cartesian<double> K;
typedef K::Point_2 Point_2;

double AreaOfTriangle(Point_2 p1, Point_2 p2, Point_2 p3) 
{
    return (p2.x() - p1.x()) * (p3.y() - p1.y()) - (p3.x() - p1.x()) * (p2.y() - p1.y()); 
	
}

int main(int argc, char **argv)
{
    Point_2 p1,p2,p3; // declaration of variable of type Point_2;
    std::ifstream iFile("input.txt", std::ios::in); //open the file for reading

    QApplication app(argc, argv);
    QGraphicsScene scene; 
    scene.setSceneRect(0,0, 600, 500);

    QPen pen; //variable of type pen
    pen.setColor(Qt::blue); //setting the color as blue

    iFile >> p1; iFile >> p2; iFile >> p3;
    scene.addLine(QLine(p1.x(), p1.y(), p2.x(), p2.y()), pen);
    scene.addLine(QLine(p2.x(), p2.y(), p3.x(), p3.y()), pen);
    scene.addLine(QLine(p3.x(), p3.y(), p1.x(), p1.y()), pen);
    
    double area = AreaOfTriangle(p1, p2, p3);
    if(area < 0.0)
        area = -area;
    area = area / 2.0;
    ostringstream str1;
    str1<<area;
    string str = "Area = " + str1.str();

    QGraphicsTextItem *text = scene.addText(str.c_str());
    text->setPos(5, 280);

    QGraphicsView* view = new QGraphicsView(&scene);
    CGAL::Qt::GraphicsViewNavigation navigation;
    view->installEventFilter(&navigation);
    view->viewport()->installEventFilter(&navigation);
    view->setRenderHint(QPainter::Antialiasing);

    view->show();
    return app.exec();
}


