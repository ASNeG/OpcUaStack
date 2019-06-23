/*
    DataTypeClass: ConnectionTransportDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_ConnectionTransportDataType_h__
#define __OpcUaStackCore_ConnectionTransportDataType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT ConnectionTransportDataType
    : public Object
    , public ExtensionObjectBase
    {
      public:
        typedef boost::shared_ptr<ConnectionTransportDataType> SPtr;
        typedef std::vector<ConnectionTransportDataType::SPtr> Vec;
    
        ConnectionTransportDataType(void);
        ConnectionTransportDataType(const ConnectionTransportDataType& value);
        virtual ~ConnectionTransportDataType(void);
        
        
        //- ExtensionObjectBase -----------------------------------------------
        virtual ExtensionObjectBase::SPtr factory(void);
        virtual std::string namespaceName(void);
        virtual std::string typeName(void);
        virtual OpcUaNodeId typeId(void);
        virtual OpcUaNodeId binaryTypeId(void);
        virtual OpcUaNodeId xmlTypeId(void);
        virtual OpcUaNodeId jsonTypeId(void);
        virtual void opcUaBinaryEncode(std::ostream& os) const;
        virtual void opcUaBinaryDecode(std::istream& is);
        virtual bool xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns);
        virtual bool xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns);
        virtual bool xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns);
        virtual bool xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns);
        virtual void copyTo(ExtensionObjectBase& extensionObjectBase);
        virtual bool equal(ExtensionObjectBase& extensionObjectBase) const;
        virtual void out(std::ostream& os);
        //- ExtensionObjectBase -----------------------------------------------
        
        virtual bool jsonEncodeImpl(boost::property_tree::ptree& pt) const;
        virtual bool jsonDecodeImpl(const boost::property_tree::ptree& pt);
        
        void copyTo(ConnectionTransportDataType& value);
        bool operator==(const ConnectionTransportDataType& value);
        bool operator!=(const ConnectionTransportDataType& value);
        ConnectionTransportDataType& operator=(const ConnectionTransportDataType& value);
    
      private:
    
    };
    
    class DLLEXPORT ConnectionTransportDataTypeArray
    : public OpcUaArray<ConnectionTransportDataType::SPtr, SPtrTypeCoder<ConnectionTransportDataType> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<ConnectionTransportDataTypeArray> SPtr;
    };

}

#endif
