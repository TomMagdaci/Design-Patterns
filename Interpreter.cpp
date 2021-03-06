#include <iostream>
#include <vector>
#include <list>

using namespace std;

class expression {
public:
    virtual int val()=0;
};

class num: public expression{
    int x;
public:
    num(int newX): x(newX){}
    virtual int val() {
        return x;
    }
};

class binaryexp: public expression {
protected:
    pair<expression*,expression*> p;
public:
    binaryexp(expression* e1, expression* e2) {
        p.first = e1;
        p.second = e2;
    }
    virtual void addExps(expression* e1, expression* e2){
        p.first = e1;
        p.second = e2;
    }
    virtual int val()=0;
};

class plusi: public binaryexp {
public:
    plusi(expression* e1, expression* e2): binaryexp(e1, e2) {}
    virtual int val() {
        return p.first->val() + p.second->val();
    }
};

/*int main()
{
    cout<<"Hello World"<<endl;
    expression* e1 = new num(5);
    expression* e2 = new plusi(new num(7),new num(10));
    expression* e3 = new plusi(e1,e2);
    expression* e4 = new plusi(e3,new num(9));
    cout<<e4->val()<<endl;

    return 0;
}*/
