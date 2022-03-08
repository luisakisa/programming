#include "IX.h"
#include "Server.h"
#include "Server2.h"
IX* CreateInstance(int Iid)
{
    if(Iid==2){
        return new Server2();
    }
    if(Iid==1){
        return new Server();
    }
    
}