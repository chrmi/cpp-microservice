APP_NAME=cppsvc

CPPVER=c++14
CFLAGS=-Wall
PFLAGS=-lboost_system -lcrypto -lssl -lcpprest
SRC=./src/http_ctrl.cpp ./src/logger.cpp 

FRAMEWORK_TESTS=./tests/test_result.cpp ./tests/test.cpp ./tests/test_registry.cpp ./tests/failure.cpp
APP_TESTS=./tests/logger.cpp
MAIN_TEST=./tests/main.cpp

URLA?=http://0.0.0.0:
PORT?=8998
URLB?=/health

default:
	make clean ; make test && make install && make run

install:
	mkdir bin ; g++ -std=${CPPVER} ${CFLAGS} ${SRC} ./src/main.cpp -o ./bin/${APP_NAME} ${PFLAGS}

run:
	./bin/${APP_NAME} 

clean:
	rm -rf ./bin ./debug

test:
	clear
	rm -rf ./debug && mkdir debug
	g++ -std=${CPPVER} ${CFLAGS} ${FRAMEWORK_TESTS} ${APP_TESTS} ${MAIN_TEST} ${SRC} -o ./debug/${APP_NAME}_tests ${PFLAGS} ; ./debug/${APP_NAME}_tests 

demo:
	curl ${URLA}${PORT}${URLB}
	curl -X POST -d '{"key1":"value1", "key2":"value2"}' -H "Content-Type: application/json" ${URLA}${PORT}${URLB}
	curl -X PUT -d '{"key1":"value1", "key2":"value2"}' -H "Content-Type: application/json" ${URLA}${PORT}${URLB}
	curl -X DELETE ${URLA}${PORT}${URLB}

