#ifndef _BUFFER_H_
#define _BUFFER_H_

#include <stdint.h>

struct Buffer {
    Buffer(int _size):size(_size){
        buf = new char[size];
    }
    ~Buffer(){
        delete[] buf;
    }
    char* buf{nullptr};
    size_t size{0};
    int64_t pts;
    int64_t dts;
};

#endif