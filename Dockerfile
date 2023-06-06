FROM ubuntu:latest

RUN apt-get update && \
    apt-get install -y g++ && \
    apt-get install -y cmake && \
    apt-get install -y git && \
    apt-get install -y libjsoncpp-dev

WORKDIR /FFT

COPY example/example_2.json /FFT/data/example_2.json

RUN git clone https://github.com/nlohmann/json.git && \
    cd json && \
    mkdir build && \
    cd build && \
    cmake .. && \
    make && \
    make install

COPY . .

RUN make

CMD ["./fftransform"]
