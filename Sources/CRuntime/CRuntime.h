#ifndef cruntime_h
#define cruntime_h

const void * _Nullable swift_getTypeByMangledNameInContext(
                        const char * _Nullable typeNameStart,
                        int typeNameLength,
                        const void * _Nullable context,
                        const void * _Nullable const * _Nullable genericArgs);

const void * _Nullable swift_allocObject(
                    const void * _Nullable type,
                    int requiredSize,
                    int requiredAlignmentMask);

void * callFunction(void *function,
                    void *data,
                    int size) {

    typedef void * CastedFunction(u_char data[size]);

    u_char castedData[size];
    memcpy(&castedData, data, sizeof(castedData));
    CastedFunction *castedFunction = (CastedFunction *)(function);
    return castedFunction(castedData);
}

#endif
