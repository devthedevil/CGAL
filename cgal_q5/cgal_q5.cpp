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

double AreaOfTriangle(Point_2 p1, Point_2 p2, Point_2 p3) {
    return (p2.x() - p1.x()) * (p3.y() - p1.y()) -
	   (p3.x() - p1.x()) * (p2.y() - p1.y()); 
	
}

int main(int argc, char **argv)
{
    Point_2 v0,p1,p2; // DEclaration variable of type Point_2;
    std::ifstream iFile("input.txt", std::ios::in); //open the file for reading

    QApplication app(argc, argv);


    QGraphicsScene scene; 
    scene.setSceneRect(0,0, 600, 400);

    QPen pen; // DEclaration of  variable of type pen
    pen.setColor(Qt::blue); //setting the color as Blue

    QPolygonF polygon;
   
    
    iFile >> v0;
    polygon << QPointF(v0.x(), v0.y());
    iFile >> p1;
    polygon << QPointF(p1.x(), p1.y());

    double areaOfPolygon = 0.0;
    while(iFile >> p2) {
	
	areaOfPolygon += AreaOfTriangle(v0, p1, p2);
	polygon << QPointF(p2.x(), p2.y());
	p1 = p2;

    }
    scene.addPolygon(polygon, pen);
    if(areaOfPolygon < 0.0)
       areaOfPolygon = -areaOfPolygon;
    areaOfPolygon = areaOfPolygon / 2.0;
    ostringstream str1;
    str1 << areaOfPolygon;
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
