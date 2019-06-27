/*
    DataTypeClass: DatagramConnectionTransportDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_DatagramConnectionTransportDataType_h__
#define __OpcUaStackCore_DatagramConnectionTransportDataType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/StandardDataTypes/ConnectionTransportDataType.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaExtensibleParameter.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT DatagramConnectionTransportDataType
    : public ConnectionTransportDataType
    {
      public:
        typedef boost::shared_ptr<DatagramConnectionTransportDataType> SPtr;
        typedef std::vector<DatagramConnectionTransportDataType::SPtr> Vec;
    
        DatagramConnectionTransportDataType(void);
        DatagramConnectionTransportDataType(const DatagramConnectionTransportDataType& value);
        virtual ~DatagramConnectionTransportDataType(void);
        
        OpcUaExtensibleParameter& discoveryAddress(void);
        
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
        
        void copyTo(DatagramConnectionTransportDataType& value);
        bool operator==(const DatagramConnectionTransportDataType& value);
        bool operator!=(const DatagramConnectionTransportDataType& value);
        DatagramConnectionTransportDataType& operator=(const DatagramConnectionTransportDataType& value);
    
      private:
        OpcUaExtensibleParameter discoveryAddress_;
    
    };
    
    class DLLEXPORT DatagramConnectionTransportDataTypeArray
    : public OpcUaArray<DatagramConnectionTransportDataType::SPtr, SPtrTypeCoder<DatagramConnectionTransportDataType> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<DatagramConnectionTransportDataTypeArray> SPtr;
    };

}

#endif
