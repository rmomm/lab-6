FROM ubuntu:22.04

RUN apt-get update && \
    DEBIAN_FRONTEND=noninteractive apt-get install -y \
    g++ cmake make git libgtest-dev && \
    apt-get clean

RUN cd /usr/src/gtest && cmake . && make && cp lib/*.a /usr/lib

WORKDIR /app

COPY lab6.cpp Test.cpp ./

RUN g++ -std=c++17 -o my_program Test.cpp lab6.cpp -lgtest -lgtest_main -pthread

CMD ["./my_program"]
