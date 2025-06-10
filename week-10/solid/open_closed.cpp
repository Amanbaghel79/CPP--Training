/*This principle states that “Software entities (classes, modules, functions, etc.) 
should be open for extension, but closed for modification” which means you should be
 able to extend a class behavior, without modifying it.*/
//  Definition:
// Software entities (classes, modules, functions) should be open for extension but closed for modification.

//  Focuses On:
// Extending behavior without changing existing code.

// Preventing breakage in working code when adding new features
//  #include<iostream>
//  using namespace std;
//  class shape{
//     public:
//     int type;
//  };
//  class circle : public shape{
//     public:
//     circle(){
//         type=1;
//     }
//  };
//  class square: public shape{
//     public:
//     square(){type=2;}
//  };
//  class shapes_maker{
//     public:
//     void draw(shape* shape){
//         if(shape->type==1){
//             cout<<" processing to make a circle"<<endl;
//         }
//         else if(shape->type==2){
//             cout<<"processing to make a square"<<endl;
//         }
//     }
//  };
//  int main(){
//      shape* ptr;
//      circle obj;
//      ptr=&obj;
//      shapes_maker maker;
//      maker.draw(ptr);
//  }

//this above code have some problems like----:
 /*
 You must modify GraphicEditor every time you add a new shape.
 Breaks OCP — not closed for modification.
 */
//-------------------------------------------------------------------
// Good Design (OCP Compliant using Polymorphism) 
#include <iostream>
#include <vector>
#include <memory>

using namespace std;
class Shape {
public:
    virtual void draw() const = 0; // Pure virtual method
    virtual ~Shape() = default;
};


class Circle : public Shape {
public:
    void draw()  {
        cout << "Drawing Circle\n";
    }
};

class Rectangle : public Shape {
public:
    void draw()  {
        cout << "Drawing Rectangle\n";
    }
};


class GraphicEditor {
public:
    void drawShape(const Shape& shape) {
        shape.draw(); // Polymorphic behavior
    }
};

int main() {
    GraphicEditor editor;

    vector<shared_ptr<Shape>> shapes;
     shapes.push_back(make_shared<Circle>());
     shapes.push_back(make_shared<Rectangle>());
     for(auto &it: shapes){
        editor.drawShape(*it);
     }
    return 0;
}


/*
✅ Advantages of this Design:
--GraphicEditor is closed for modification — we don’t touch it again.
--To add a new shape like Triangle, you just add a new class — open for extension.
--Uses abstraction and polymorphism for clean design.*/


 