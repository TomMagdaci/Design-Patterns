/******************************************************************************

Flyweight design pattern example. Only concrete shared flyweights are being used

*******************************************************************************/

#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <string.h>
#include <unordered_map>
#include <cstring>

using namespace std;

class Flyweight{ //Flyweight
public:
    virtual void identify()=0;
    virtual void printPosition(int r, int c)=0;
    //int getHealth()=0;
};

class Soldier: public Flyweight{
public:
    void identify() {
        cout<<"I am a Soldier"<<endl;
    }
    void printPosition(int r, int c){
        cout<<"Soldier at "<<r<<","<<c<<" on the map"<<endl;
    }
};
class Tank: public Flyweight {
public:
    void identify() {
        cout<<"I am a Tank"<<endl;
    }
    void printPosition(int r, int c){
        cout<<"Tank at "<<r<<","<<c<<" on the map"<<endl;
    }
};

class FlyweightFactory {
    unordered_map<string, Flyweight*> sharedfw;
public:
    FlyweightFactory(){};
    Flyweight* getFlyweight(string s){
        unordered_map<string, Flyweight*>::iterator it = sharedfw.find(s);
        if (it!=sharedfw.end()){
            return it->second;
        }
        //no key s in the map
        Flyweight* f;
        if (strcmp("Tank",s.c_str())==0){
            cout<<"new Tank is created"<<endl;
            f = new Tank();
        }
        if (strcmp("Soldier",s.c_str())==0){
            cout<<"new Soldier is created"<<endl;
            f = new Soldier();
        }
        std::pair<string, Flyweight*> newP (s,f);
        sharedfw.insert(newP);
        
        return f;
        
    }
    
};

int main()
{
    auto arrFlys = new Flyweight*[4][4];
    FlyweightFactory fac;
    for(int i=0;i<4;++i){
        for(int j=0;j<4;++j){
            arrFlys[i][j]=nullptr;
        }
    }
    for(int i=0;i<4;++i){
        for(int j=0;j<4;++j){
            if (i%2==0){
                if (j%2==0){
                    arrFlys[i][j] = fac.getFlyweight("Tank");
                }
                if ((j%2)==1){
                    arrFlys[i][j] = fac.getFlyweight("Soldier");
                }
            }
        }
    }
    
    for(int i=0;i<4;++i){
        for(int j=0;j<4;++j){
            if (i%2==0){
                if (j%2==0){
                    arrFlys[i][j]->printPosition(i,j);
                }
                if ((j%2)==1){
                    arrFlys[i][j]->printPosition(i,j);
                }   
            }
        }
    }
    return 0;
}
