/*
    VariableTypeClass: ConnectionTransportType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardObjectType/ConnectionTransportType.h"
using namespace OpcUaStackCore;

namespace OpcUaStackServer
{
    
    ConnectionTransportType::ConnectionTransportType(void)
    : ObjectBase()
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)17721);
    }
    
    ConnectionTransportType::ConnectionTransportType(const ConnectionTransportType& value)
    : ObjectBase()
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)17721);
    }
    
    ConnectionTransportType::~ConnectionTransportType(void)
    {
    }

}
