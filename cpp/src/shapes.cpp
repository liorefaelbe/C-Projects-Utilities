#include <list> // list

#include "shapes.hpp" //Shapes

using namespace std;

namespace ilrd_166_7
{
void Foo(void)
{
    Line l;
    l.SetLine();
    Circle c;
    c.SetCircle();
    Triangle t;
    t.SetTriangle();
    Square s;
    s.SetSquare();
    Rectangle r;
    r.SetRectangle();

    list<Shape*> shapes_list;

    shapes_list.push_back(&l);
    shapes_list.push_back(&c);
    shapes_list.push_back(&t);
    shapes_list.push_back(&s);
    shapes_list.push_back(&r);

    
    list<Shape*>::iterator iter = shapes_list.begin();

    for(; iter != shapes_list.end(); ++iter)
    {
        for(int i = 0; i < 10; ++i)
        {
            (*iter)->Draw();
            (*iter)->Move();
        }
    }
}
}