
#include <iostream>
#include <fstream>
#include <vector>
#include <tuple>
#include <QPolygonF>
#include <QRectF>
#include <QtGui>
#include <CGAL/Qt/GraphicsViewNavigation.h>
#include <QLineF>
#include <QPen>
#include <QApplication> 
#include <QGraphicsScene>
#include <QGraphicsView> 
#include <CGAL/Cartesian.h>
#include <CGAL/Point_2.h>

using namespace std;

typedef CGAL::Cartesian<double> K;
typedef K::Point_2 Point_2;


typedef struct tVertexStructure tsVertex;
typedef tsVertex* tVertex;
struct tVertexStructure
{
    int vnum;
    Point_2 v;
    tVertex prev,next;
    bool ear;

    
};


tVertex head=NULL;
int nvertices=0;

tVertex addVertex(tVertex& tv)
{
   

    if(head==NULL){
        head=tv;
        head->next=head->prev=tv;
    }
    else
  {
        tv->next=head;
        tv->prev=head->prev;
        head->prev=tv;
        tv->prev->next=tv;
    }
    return head;
}



int Area2Triangle(Point_2 a,Point_2 b,Point_2 c)
{
    return ((b.x()-a.x())*(c.y()-a.y()))-((c.x()-a.x())*(b.y()-a.y()));
}

int PolygonArea(){
    int ar=0,i=1;
    tVertex plist=head;
    tVertex vlistref=plist->next;
    do{
        ar+=Area2Triangle(plist->v,vlistref->v,vlistref->next->v);
        vlistref=vlistref->next;
    }while(vlistref->next!=head);
    return ar;
}



bool Left(Point_2 a,Point_2 b,Point_2 c){
    return Area2Triangle(a,b,c)<0;
}

bool Lefton(Point_2 a,Point_2 b,Point_2 c){
    return Area2Triangle(a,b,c)<=0;
}

bool Collinear(Point_2 a,Point_2 b,Point_2 c){
    return Area2Triangle(a,b,c)==0;
}




bool Xor(bool x,bool y){
    return !x^!y;
}

bool intersectProp(Point_2 a,Point_2 b,Point_2 c,Point_2 d){
    if(Collinear(a,b,c) || Collinear(a,b,d) || Collinear(c,d,a) || Collinear(c,d,b)){
        return false;
    }

    return Xor(Left(a,b,c),Left(a,b,d)) && Xor(Left(c,d,a),Left(c,d,b));
}

bool Between(Point_2 a,Point_2 b,Point_2 c){
    if(!Collinear(a,b,c)){
        return false;
    }

    if(a.x()!=b.x()){
        return (a.x()<=c.x() && c.x()<=b.x()) || (c.x()<=a.x() && b.x()<=c.x());
    }
    else{
        return (a.y()<=c.y() && c.y()<=b.y()) || (c.y()<=a.y() && b.y()<=c.y());
    }
}


bool intersect(Point_2 a,Point_2 b,Point_2 c,Point_2 d){
    if(intersectProp(a,b,c,d)){
        return true;
    }
    else if(Between(a,b,c) || Between(a,b,d) || Between(c,d,a) || Between(c,d,b)){
        return true;
    }
    else{
        return false;
    }
}



bool Diagonalie(tVertex a,tVertex b){
    tVertex c,c1;
    c=head;
    do{
        c1=c->next;

        if((c!=a) && (c1!=a) && (c!=b) && (c1!=b) && intersect(a->v,b->v,c->v,c1->v)){
            return false;
        }
        c=c->next;
    }while(c!=head);
    return true;
}

bool inCone(tVertex a,tVertex b){
    tVertex a0,a1;

    a0=a->prev;
    a1=a->next;

    if(Lefton(a->v,a1->v,a0->v)){
        return Left(a->v,b->v,a0->v) && Left(b->v,a->v,a1->v);
    }
    else{
        return !(Lefton(b->v,a->v,a0->v) && Lefton(a->v,b->v,a1->v));
    }
}

bool diagonal(tVertex a,tVertex b){
    return inCone(a,b) && inCone(b,a) && Diagonalie(a,b);
}



void earInit(){
    tVertex v0,v1,v2;
    v1=head;

    do{
        v0=v1->prev;
        v2=v1->next;
        v1->ear=diagonal(v0,v2);
        v1=v1->next;
    }while(v1!=head);
}


void printDiagonal(tVertex a,tVertex b){
    cout<<"("<<a->vnum<<" , "<<b->vnum<<")"<<endl;
}



vector<tuple<Point_2,Point_2,Point_2>> triangulate(){
    tVertex v0,v1,v2,v3,v4;
    bool earf;
    int n=nvertices;
    earInit();
    // tVertex headref=head;
    vector<tuple<Point_2,Point_2,Point_2>> v;
    // tuple<Point_2,Point_2> returnmap;

    while(n>3){
        v2=head;
        earf=false;
        do{
            if(v2->ear){
                earf=true;
                v3=v2->next;v4=v3->next;
                v1=v2->prev;v0=v1->prev;

                // cout<<"("<<v1->v.x()<<" , "<<v1->v.y()<<") - ("<<v3->v.x()<<" , "<<v3->v.y()<<")"<<endl;
                v.push_back(make_tuple(v1->v,v2->v,v3->v));
                // scene.addLine(LineF(v1->v.x(),v1->v.y(), v3->v.x(), v3->v.y()));

                v1->ear=diagonal(v0,v3);
                v3->ear=diagonal(v1,v4);

                v1->next=v3;
                v3->prev=v1;
                head=v3;

                n--;
                break;
            }
            v2=v2->next;
        }while(v2!=head);
        if(n==3)
        {
        	v.push_back(make_tuple(v1->v,v3->next->v,v3->v));
        }  
    }
    return v;
}





int main(int argc, char **argv)
{

    ifstream iFile("input6.txt",ios::in);
    QApplication app(argc, argv);

    Point_2 pd;
    QPolygonF polygon;

    nvertices=0;
    while(iFile>>pd){
    	polygon<<QPointF(pd.x(),pd.y());
        tVertex tv=new tsVertex();
        tv->vnum=nvertices;
        tv->v=pd;

        head=addVertex(tv);
        nvertices++;
    }
    QGraphicsScene scene;
    scene.addPolygon(polygon);
    

    vector<tuple<Point_2,Point_2,Point_2>> v2;
    v2=triangulate();
    QPen pen;
    pen.setColor(Qt::black);
    for(vector<tuple<Point_2,Point_2,Point_2> >::const_iterator it = v2.begin();it!=v2.end();it++){
		QPolygonF tri;
		tri<<QPointF(get<0>(*it).x(),get<0>(*it).y());
		tri<<QPointF(get<1>(*it).x(),get<1>(*it).y());
		tri<<QPointF(get<2>(*it).x(),get<2>(*it).y());
		QBrush brush(QColor( qrand() % 256, qrand() % 256, qrand() % 256 ));
		scene.addPolygon(tri,pen,brush);
        cout << get<0>(*it)<<" "<<get<1>(*it) <<" "<<get<2>(*it)<< endl;
    }
    //tvertex 

    //GOT DIAGONAL VERTEX PAIRS, MAKE LINKAGES AFTER DRAWING POLYGON



    // scene.addLine(QLineF(p1.x(),p1.y(), p2.x(), p2.y()));
    // scene.addLine(QLineF(p3.x(),p3.y(), p4.x(), p4.y()));

    // cout<<boolalpha<<intersect(p1,p2,p3,p4);
	scene.setSceneRect(0,0,500,500);
    QGraphicsView* view = new QGraphicsView(&scene);
    //CGAL::Qt::GraphicsViewNavigation navigation;
    //view->installEventFilter(&navigation);
    //view->viewport()->installEventFilter(&navigation);
    //view->setRenderHint(QPainter::Antialiasing);

    view->show();
    return app.exec();
}






