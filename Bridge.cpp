#include <iostream>
#include <vector>
#include <math.h>
#include <string>

using namespace std;
class HouseImp{
public:
    virtual void paintDoor()=0;
    virtual void paintWindow()=0;
    virtual void paintRoof()=0;
};
class WoodImp: public HouseImp{
public:
    void paintDoor() {
        cout<<"Painting Door with DarkBrown color as Im Wood"<<endl;
    }
    void paintWindow() {
        cout<<"Painting Window with LightBrown color as Im Wood"<<endl;
    }
    void paintRoof() {
        cout<<"Painting Roof with DarkBrown color as Im Wood"<<endl;
    }
};
class BrickImp: public HouseImp{
public:
    void paintDoor() {
        cout<<"Painting Door with DarkGrey color as Im Brick"<<endl;
    }
    void paintWindow() {
        cout<<"Painting Window with LightGrey color as Im Brick"<<endl;
    }
    void paintRoof() {
        cout<<"Painting Roof with DarkGrey color as Im Brick"<<endl;
    }
};

class House {
protected:
    HouseImp* hI;
public: 
    House(HouseImp* newH): hI(newH) {}
    virtual void paint()=0;
};

class BigHouse: public House{
public:
    BigHouse(HouseImp* newH): House(newH){}
    void paint() {
        cout<<"Painting my 2 doors in my BigHouse"<<endl;
        hI->paintDoor();
    }
};

class SmallHouse: public House{
public:
    SmallHouse(HouseImp* newH): House(newH){}
    void paint() {
        cout<<"Painting my only 1 doors in my SmallHouse"<<endl;
        hI->paintDoor();
    }
};


/*int main()
{
    BigHouse b(new BrickImp());
    b.paint();
    return 0;
}*/
