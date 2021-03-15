#include <iostream>
#include <vector>
#include <math.h>
#include <string>

using namespace std;

class Pizza{
public:
    virtual void print()=0;
};

class BasicPizza: public Pizza{
public:
    void print() {
        cout<<"BasicPizza ";
    }
};

class Addons: public Pizza { //Decorator
    Pizza* p;
public:
    Addons(Pizza* newP): p(newP){}
    void print(){
        p->print();
    }
    
};

class Mushroom: public Addons{
public:
    Mushroom(Pizza* newP):Addons(newP){}
    void print(){
        Addons::print();
        cout<<"Mushroom ";
    }
};

class Olive: public Addons{
public:
    Olive(Pizza* newP):Addons(newP){}
    void print(){
        Addons::print();
        cout<<"Olive ";
    }
};

/*int main()
{
    Pizza* p = new Olive(new Mushroom(new BasicPizza()));
    p->print();
    return 0;
}*/
