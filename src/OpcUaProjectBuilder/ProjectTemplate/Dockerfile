FROM asneg/opcuastack:DockerTag

# Prepare workdir
ADD / /tmp
RUN mkdir /build
WORKDIR /build

# Build
RUN cmake /tmp/src
RUN make
RUN make install

# Start ProjectName
EXPOSE ProjectPort 4840
CMD ["OpcUaServer4", "/etc/OpcUaStack/ProjectName/OpcUaServer.xml"]
