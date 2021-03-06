#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <string.h>
#include <unordered_map>
#include <cstring>

using namespace std;

class Robot;

class RobotBuilder {
    string name;
    int id;
    double mass;
    int flyable;
    friend class Robot;
public:
    RobotBuilder(string nname, int nid): name(nname), id(nid), mass(0), flyable(0) {}
    RobotBuilder& setMass(double nmass) {
        mass = nmass; 
        return *this;
    }
    RobotBuilder& setFlyable(int nflyable) {
        flyable=nflyable;
        return *this;
    }
    Robot* buildRobot();
    

};


class Robot {
public:
    const string name;
    const int id;
    const double mass;
    const int flyable;

    Robot(RobotBuilder* rb): name(rb->name), id(rb->id), mass(rb->mass), flyable(rb->flyable){}
    
};


Robot* RobotBuilder::buildRobot() {
    return new Robot(this);
}


/*int main()
{
    RobotBuilder rb("tom",313);
    Robot* robot =  rb.setFlyable(1).setMass(5555).buildRobot();
    cout<<"I have built the next robot: "<<robot->name<<" "<<robot->id<<" "<<robot->mass<<" "<<robot->flyable<<endl;

    return 0;
}*/
