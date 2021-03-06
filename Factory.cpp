#include <iostream>
#include <typeinfo>
#include <list>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;


class Worker {
public:
    virtual void print() =0;
};
class WorkerA: public Worker{
public:
    void print() {
        cout<<"I am WorkerA"<<endl;
    }
};
class WorkerB: public Worker{
public:
    void print() {
        cout<<"I am WorkerB"<<endl;
    }  
};
class WorkerC: public Worker{
public:
    void print() {
        cout<<"I am WorkerC"<<endl;
    } 
};

class WorkerFactory{
    //need to check whether it is legal to write private class
    class Factory {
    public:
        virtual Worker* create() =0;
    };
    unordered_map<string, Factory*> umap;
public:
    WorkerFactory() {
        umap["WorkerACreator"] = new FactoryWorkerA();
        umap["WorkerBCreator"] = new FactoryWorkerB();
        umap["WorkerCCreator"] = new FactoryWorkerC();
    }
    Worker* createWorker(string s){
        unordered_map<string, Factory*>::const_iterator it = umap.find(s);
        if (it==umap.end()){
            return nullptr;
        }
        Factory* f = it->second;
        return f->create();
    }
    
private:

    class FactoryWorkerA: public Factory{
    public:
        Worker* create(){
            return new WorkerA();
        }
    };
    class FactoryWorkerB: public Factory{
    public:
        Worker* create(){
            return new WorkerB();
        }
    };
    class FactoryWorkerC: public Factory{
    public:
        Worker* create(){
            return new WorkerC();
        }
    };
};
int main(){
    WorkerFactory wf;
    Worker* w = wf.createWorker("WorkerBCreator");
    w->print();
    w =  wf.createWorker("WorkerCCreator");
    w->print();
    w = wf.createWorker("sss");
    if (w == nullptr){
        cout<<"there is no factory for worker sss"<<endl;
    }
    
}
