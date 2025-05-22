FROM ubuntu:22.04

RUN apt-get update && \
    DEBIAN_FRONTEND=noninteractive apt-get install -y \
    g++ cmake make git libgtest-dev && \
    apt-get clean

RUN cd /usr/src/gtest && cmake . && make && cp lib/*.a /usr/lib

WORKDIR /usr/src/mya

COPY lab6.h lab6.cpp Test.cpp ./

RUN g++ -std=c++17 -c lab6.cpp -o lab6.o
RUN g++ -std=c++17 -c Test.cpp -o Test.o

RUN g++ lab6.o Test.o -o test_program -lgtest -lgtest_main -pthread

CMD ["./test_program"]


CMD ["./my_program"]
