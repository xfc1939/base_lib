#ifndef _LOG_H_
#define _LOG_H_
#include <iostream>
#include <sstream>
#include <string>

class Log {
public:
    enum LogType {
        Debug,
        Trace,
        Error
    };

public:
    Log(LogType log_level):log_level_(log_level){}
    ~Log() {
        if(log_level_ == Error) {
            std::cerr << str_stream_.rdbuf()->str() << std::endl;
        } else {
            std::cout << str_stream_.rdbuf()->str() << std::endl;
        }
    }
  
    template<class T>
    Log& operator<<(const T &value) {
        str_stream_ << " " << value;
        return *this;
    }
private:
    std::stringstream str_stream_;

    LogType log_level_{LogType::Debug};
};

#define LOG_DEBUG() Log(Log::Debug) << "[Debug]" << "[" << __LINE__ << "]" << __FUNCTION__
#define LOG_ERROR() Log(Log::Error) << "[Error]" << "[" << __LINE__ << "]" << __FUNCTION__

#endif