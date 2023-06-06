FROM ubuntu:latest

RUN apt-get update && \
    apt-get install -y g++ make

WORKDIR /FFT

COPY . .

RUN make

CMD ["./fftransform"]
