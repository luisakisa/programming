#include "ClientWrapper.h"
#include <iostream>

using namespace std;

int main()
{
    try {

        cout << "started" << endl;
        ClientWrapper client1(RunType::ManagerEmulator, false);
        cout << "client1 created" << endl;
        ClientWrapper client2 = client1;
        cout << "client2 created" << endl;
        client1.enterMatrix();
        client1.transposeAndPrintMatrix();
        client2.enterMatrix();
        client2.transposeAndPrintMatrix();

    } catch (exception e) {
        cout << "main::Exception" << e.what() << endl;
    } catch (...) {
        cout << "main::Unknown exception" << endl;
    }

    return 0;	
}
