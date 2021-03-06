/******************************************************************************

Singleton Example

*******************************************************************************/

#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <string.h>
#include <cstring>

using namespace std;

class DataBase {
    static DataBase* d;
    DataBase(){}
public:
    int lines;
    static DataBase* getAccessToDataBase() {
        if (d == nullptr){
            cout<<"Creating the DataBase.."<<endl;
            d = new DataBase();
        }
        return d;
    }
};

DataBase* DataBase::d = nullptr;

/*int main()
{
    DataBase* d = DataBase::getAccessToDataBase();
    d->lines = 1111;
    DataBase* d2 = DataBase::getAccessToDataBase();
    cout<<"The number of lines in the data base is: "<<d2->lines<<endl;

    return 0;
}*/
