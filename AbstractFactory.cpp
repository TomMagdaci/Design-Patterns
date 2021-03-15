#include <iostream>
#include <unordered_map>

using namespace std;

class sword {
public:
    virtual void identify()=0;
};

class woodsword: public sword {
public:
    virtual void identify() {
        cout<<"Wood Sword ";
    }
};

class lightsword: public sword {
public:
    virtual void identify() {
        cout<<"Light Sword ";
    } 
};

class shield {
public:
    virtual void identify()=0;
};

class woodshield: public shield {
public:
    virtual void identify() {
        cout<<"Wood Shield ";
    } 
};

class lightshield: public shield {
public:
    virtual void identify() {
        cout<<"Light Shield ";
    } 
};

class abstractFactory {
public:
    virtual sword* createSword()=0;
    virtual shield* createshield()=0;
};

class factoryWood: public abstractFactory {
public:
    virtual sword* createSword() {
        return new woodsword();
    }
    virtual shield* createshield() {
        return new woodshield();
    }
};

class factoryLight: public abstractFactory {
public:
    virtual sword* createSword() {
        return new lightsword();
    }
    virtual shield* createshield() {
        return new lightshield();
    }
};

/*int main()
{
    cout<<"Hello World"<<endl;;
    abstractFactory* fac = new factoryWood();
    fac->createSword()->identify();
    fac->createshield()->identify();
    fac = new factoryLight();
    fac->createSword()->identify();
    fac->createshield()->identify();

    return 0;
}*/
