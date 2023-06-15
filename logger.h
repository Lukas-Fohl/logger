#ifndef LOGGER_FILE
#define LOGGER_FILE

#include <stdlib.h>
#include <time.h>

char* logFile;

enum loggerTypes {
    error = 0,
    panic,
    warning,
    info,
    debug
};

typedef struct logElementFloat
{
    enum loggerTypes logType;
    float value;
} logElementFloat;

typedef struct logElementStr
{
    enum loggerTypes logType;
    char* value;
} logElementStr;

typedef struct logElementInt
{
    enum loggerTypes logType;
    int value;
} logElementInt;

void setLogFile(char* logFile_){
    logFile = (char*)calloc((sizeof(logFile)/sizeof(char)),sizeof(char));
    logFile = logFile_;
}

char* loggerTypesToString(enum loggerTypes e){
    switch(e)
    {
        case error: 
            return "error";
            break;
        case panic:
            return "panic";
            break;
        case warning:
            return "warning";
            break;
        case info:
            return "info";
            break;
        case debug:
            return "debug";
            break;
        default:
            return (char*)calloc(1,sizeof(char)); break;
    }
}

void appendLoggerStr(logElementStr* elementIn){
    FILE* openLoggerFile = fopen(logFile,"a+");
    fprintf(openLoggerFile,"[%s][%ld]%s\n",loggerTypesToString(elementIn->logType),(time(NULL)),elementIn->value);
    fclose(openLoggerFile);
}

void appendLoggerFloat(logElementFloat* elementIn){
    FILE* openLoggerFile = fopen(logFile,"a+");
    fprintf(openLoggerFile,"[%s][%ld]%f\n",loggerTypesToString(elementIn->logType),(time(NULL)),elementIn->value);
    fclose(openLoggerFile);
}

void appendLoggerInt(logElementInt* elementIn){
    FILE* openLoggerFile = fopen(logFile,"a+");
    fprintf(openLoggerFile,"[%s][%ld]%i\n",loggerTypesToString(elementIn->logType),(time(NULL)),elementIn->value);
    fclose(openLoggerFile);
}

#endif