#include "IX.h"
#include "Server.h"
#include "Server2.h"

HRESULT_ CreateInstance(CLSID_ clsid, IID_ iid, void** ppv){
    if (clsid == 1){
        if (iid == 1){
            *ppv = (IX*)(new Server());
            return 0;
        }
    }
    else if (clsid == 2){
        if (iid == 1){
            *ppv = (IX*)(new Server2());
            return 0;
        }
        else if (iid == 2){
            *ppv = (IY*)(new Server2());
            return 0;
        }
    }
    return 1;
}