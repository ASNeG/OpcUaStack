FROM ubuntu:xenial

MAINTAINER Aleksey Timin <atimin@gmail.com>

# Install dependencies
RUN apt-get update \
      && apt-get install -y libboost-all-dev cmake libssl-dev  build-essential


# Prepare workdir
ADD / /tmp
RUN mkdir /tmp/build
WORKDIR /tmp/build

# Build
RUN cmake ../src
RUN make -j2
RUN make install

# Clean source and build files
WORKDIR /
RUN rm /tmp -rf
