#include <windows.h>
#include <iostream>

using namespace std;


typedef double (*FunctionType) (double,double);



int main() {	

    
    FunctionType f;
    HINSTANCE h;

    h=LoadLibrary("dll\\main.dll");
    
    if (!h)
    {
           cout << "No dll!!!" << endl;
           return 0;
    }
    f=(FunctionType) GetProcAddress(h,"TestFunction");
    if (!f)
    {
          cout << "No dll function" << endl;
          return 0;
    }        
        
    cout << "Call dll function: " << f(2,8) << endl;
    system("pause");

    return 0;		
}