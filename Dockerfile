FROM ubuntu:xenial

MAINTAINER Aleksey Timin <atimin@gmail.com>

# Install dependencies
RUN apt-get update \
      && apt-get install -y libboost-all-dev cmake libssl-dev  build-essential


# Prepare workdir
ADD / /OpcUaStack
WORKDIR /OpcUaStack

# Build
RUN sh build.sh -t local -i / -j 2 -B Release

# Clean build files
RUN sh build.sh -t clean
