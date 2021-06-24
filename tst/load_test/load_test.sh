#!/bin/bash

export ENDPOINT="opc.tcp://127.0.0.1:8889"
export NUMBER_SERVER_NODES=20000
export MAX_NODES_PER_REQUEST=2000
export NUMBER_MONITOR_PROCESS=10
export NUMBER_WRITE_PROCESS=10

function start_asneg_server()
{
    echo "start asneg server"
    cp OpcUaServer.xml ~/.ASNeG/etc/OpcUaStack/ASNeG-Demo/
    gnome-terminal --tab --title="Server" -- bash -c "OpcUaServer4 ~/.ASNeG/etc/OpcUaStack/ASNeG-Demo/OpcUaServer.xml"
}

function stop_asneg_server()
{
    echo "stop asneg server"
    kill `ps waux | grep -v 'grep' | grep OpcUaServer | awk '{print $2}'`
}

function start_add_nodes()
{
    local endpoint=$1
    local startNode=$2
    local numberServerNodes=$3
    local maxNodesPerRequest=$4

    echo "start add nodes"
    gnome-terminal --tab --title="Add Nodes" -- bash -c "python3 create_test_nodes.py ${endpoint} ${startNode} ${numberServerNodes} ${maxNodesPerRequest}"
    echo "done"
}

function stop_add_nodes()
{
    echo "stop add nodes"
    kill `ps waux | grep -v 'grep' | grep create_test_nodes.py | awk '{print $2}'`
}

function start_write_nodes()
{
    local endpoint=$1
    local startNode=$2
    local numberServerNodes=$3
    local maxNodesPerRequest=$4

    echo "start write nodes"
    gnome-terminal --tab --title="Write Nodes" -- bash -c "python3 write_test_nodes.py ${endpoint} ${startNode} ${numberServerNodes} ${maxNodesPerRequest} 1000000"
}

function stop_write_nodes()
{
    echo "stop write nodes"
    kill `ps waux | grep -v 'grep' | grep write_test_nodes.py | awk '{print $2}'`
}

function start_monitor_nodes()
{
    local endpoint=$1
    local startNode=$2
    local numberServerNodes=$3

    echo "start monitor nodes"
    gnome-terminal --tab --title="Mon Nodes" -- bash -c "python3 monitor_test_nodes.py ${endpoint} ${startNode} ${numberServerNodes} 1000000"
}

function stop_monitor_nodes()
{
    echo "stop monitor nodes"
    kill `ps waux | grep -v 'grep' | grep monitor_test_nodes.py | awk '{print $2}'`
}

function usage()
{
    echo "$0 [start | stop]"
}

if [ $# -ne 1 ];
then
    usage
    exit 1
fi

if [ $1 == "start" ];
then
    echo "start"
    start_asneg_server

    sleep 2
    start_add_nodes ${ENDPOINT} 100000 ${NUMBER_SERVER_NODES} ${MAX_NODES_PER_REQUEST}

    sleep 10
    number_monitor_server_nodes=$(( ${NUMBER_SERVER_NODES} / ${NUMBER_MONITOR_PROCESS}))
    i=0
    while [ $i -lt ${NUMBER_MONITOR_PROCESS} ];
    do
	start_node=$((100000 + $i * ${number_monitor_server_nodes=}))
	i=$(($i+1))
        start_monitor_nodes ${ENDPOINT} ${start_node} ${number_monitor_server_nodes} 
	sleep 5
    done

    sleep 10
    number_write_server_nodes=$(( ${NUMBER_SERVER_NODES} / ${NUMBER_WRITE_PROCESS}))
    i=0
    while [ $i -lt ${NUMBER_WRITE_PROCESS} ];
    do
	start_node=$((100000 + $i * ${number_write_server_nodes=}))
	i=$(($i+1))
        start_write_nodes ${ENDPOINT} ${start_node} ${number_write_server_nodes} ${MAX_NODES_PER_REQUEST}
	sleep 5
    done

else
    echo "stop"
    stop_asneg_server

    stop_add_nodes

    stop_write_nodes

    stop_monitor_nodes
fi
exit 0
