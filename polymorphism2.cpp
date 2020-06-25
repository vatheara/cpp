#include <iostream>
using namespace std;
//=====CLASS========
class Base
{
    public:
        virtual void Input()=0;
        virtual void Output()=0;
        virtual float Area()=0;
};
class Rectangle: public Base
{
    float Lenght, Width;
    public:
    Rectangle();
    Rectangle(float,float);
    virtual void Input();
    virtual void Output();
    virtual float Area();
};
class Circle: public Base
{
    float raduis;
    public:
    Circle (float =2.5);
    void Input();
    void Output();
    float Area();
};
//=========CLASS DEFINITION===================
//=========Rectangle==================
Rectangle::Rectangle():Lenght(3.6), Width(1.2){}
Rectangle::Rectangle(float l, float w){
    Lenght=1;
    Width=w;
}
void Rectangle::Input(){
    cout << "Enter Lenght:";cin >> Lenght;
    cout << "Enter Width:";cin >> Width;
}
void Rectangle::Output(){
    cout << "Lenght of Rectangle: " << Lenght << endl;
    cout << "Width of Rectangle: " << Width << endl;
    cout << "Area of Rectangle: " << Area() << endl;
}
float Rectangle::Area(){
    return Lenght*Width;
}
//========Circle======================
Circle::Circle(float R) {raduis = R;}
void Circle::Input(){
    cout << "Enter Radius: "; cin >> raduis;
}
void Circle::Output(){
    cout << "Radius of Circle : " << raduis << endl;
    cout <<  "Area of Circle : " << Area() << endl;
}
float Circle::Area(){
    return (6.28 *raduis*raduis);
}
//=============================================
int main()
{
    //======== How it work? ===========
    Base *Obj[5] = {
        new Rectangle(3.5, 1.5),
        new Circle(4.5), new Circle(0.5),
        new Rectangle(2.2, 0.5),
        new Rectangle(1.7, 0.8)
    };
    //======== Understood =============
    int i,n;
   cout << n << endl;  //Why n = 1 ?
   for(i=0;i<n;i++){
       Obj[i]->Output();cout <<endl;
   }
   cout << "Enter integer n:"; cin >> n;
   //==== How it Work?=====
   //https://www.learncpp.com/cpp-tutorial/6-14-pointers-to-pointers/
   Base **pt= new Base*[n];
   //=====================
   for(i=0; i<n; i++){
       //========= How it work? =========
       if(i%2==0) pt[i]=new Circle;
       else pt[i] = new Rectangle;
       //================================
       pt[i]->Input();
   }
   for(i=0; i<n; i++){
       pt[i]->Output();cout<<endl;
   }
   delete [] pt;
    return 0;
}
