#include "stdio.h"

#include "./logger.h"

int main(){
    setLogFile("./main.logsp");
    logElementInt* logEl = (logElementInt*)calloc(1,sizeof(logElementInt)); 

	logEl->logType = debug;
	logEl->value   = 5;
    
	appendLoggerInt(logEl);

	free(logEl);

    return 0;
}

/*enum of types that could be logged
- log values in list 
- log events (with types)
- --> enum with types of loggable events + can be appended by user
- my genius plan:
	- user provides file location
	- we open the file & enter the structure || check if it allready exists
	- for each log the user chooses the provided options 
	- when a variable is logges be provide:
		- [type of log]
		- [variable-name]
		- [unix-timestamp] (could be optional)
		- [pointer / id for list]
		- [value]
*/