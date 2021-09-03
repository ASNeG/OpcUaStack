
RELEASE="release-4"

docker image rm asneg/opcuastack:${RELEASE}
docker image build -t asneg/opcuastack:${RELEASE} .
docker image push asneg/opcuastack:${RELEASE}
docker image rm asneg/opcuastack:${RELEASE}
