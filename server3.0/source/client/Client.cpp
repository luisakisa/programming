#include "ClientWrapper.h"
#include <windows.h>
#include <iostream>

using namespace std;

typedef double (*FunctionType) (double,double);

int main()
{
    try {

        cout << "started" << endl;
        ClientWrapper client1;
        cout << "client1 created" << endl;
        ClientWrapper client2 = client1;
        cout << "client2 created" << endl;
        client1.enterMatrix();
        client1.transposeAndPrintMatrix();
        client2.enterMatrix();
        client2.transposeAndPrintMatrix();

    } catch (exception e) {
        cout << e.what() << endl;
    }

    return 0;	
}
