/*
    DataTypeClass: DatagramConnectionTransportDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

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
        virtual ExtensionObjectBase::SPtr factory(void) override;
        virtual std::string namespaceName(void) override;
        virtual std::string typeName(void) override;
        virtual OpcUaNodeId typeId(void) override;
        virtual OpcUaNodeId binaryTypeId(void) override;
        virtual OpcUaNodeId xmlTypeId(void) override;
        virtual OpcUaNodeId jsonTypeId(void) override;
        virtual void opcUaBinaryEncode(std::ostream& os) const override;
        virtual void opcUaBinaryDecode(std::istream& is) override;
        virtual bool xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns) override;
        virtual bool xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns) override;
        virtual bool xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns) override;
        virtual bool xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns) override;
        virtual void copyTo(ExtensionObjectBase& extensionObjectBase) override;
        virtual bool equal(ExtensionObjectBase& extensionObjectBase) const override;
        virtual void out(std::ostream& os) override;
        //- ExtensionObjectBase -----------------------------------------------
        
        virtual bool jsonEncodeImpl(boost::property_tree::ptree& pt) const override;
        virtual bool jsonDecodeImpl(const boost::property_tree::ptree& pt) override;
        
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
