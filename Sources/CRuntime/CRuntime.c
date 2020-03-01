#import "CRuntime.h"

void * _Nonnull callFunction(void * _Nonnull function,
                             void * _Nonnull data,
                             int size) {

    typedef void * CastedFunction(char data[size]);

    char castedData[size];
    memcpy(&castedData, data, sizeof(castedData));
    CastedFunction *castedFunction = (CastedFunction *)(function);
    return castedFunction(castedData);
}

