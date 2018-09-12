#include "request.h"

void Request::process(){
    outFnc("starting request "+std::to_string(value)+"...");
}

void Request::finish(){
    outFnc("Finished request " + std::to_string(value));
}