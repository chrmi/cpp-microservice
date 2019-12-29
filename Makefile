URLA?=http://0.0.0.0:
PORT?=8998
URLB?=/health

default:
	make install && make run

install:
	rm ./cppsvc ; g++ -std=c++14 main.cpp HttpCtrl.cpp Logger.cpp -o ./cppsvc -lboost_system -lcrypto -lssl -lcpprest

run:
	./cppsvc 

test:
	curl ${URLA}${PORT}${URLB}
	curl -X POST -d '{"key1":"value1", "key2":"value2"}' -H "Content-Type: application/json" ${URLA}${PORT}${URLB}
	curl -X PUT -d '{"key1":"value1", "key2":"value2"}' -H "Content-Type: application/json" ${URLA}${PORT}${URLB}
	curl -X DELETE ${URLA}${PORT}${URLB}

