/*
    DataTypeClass: UadpWriterGroupMessageDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_UadpWriterGroupMessageDataType_h__
#define __OpcUaStackCore_UadpWriterGroupMessageDataType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/StandardDataTypes/WriterGroupMessageDataType.h"
#include "OpcUaStackCore/StandardDataTypes/DataSetOrderingType.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT UadpWriterGroupMessageDataType
    : public WriterGroupMessageDataType
    {
      public:
        typedef boost::shared_ptr<UadpWriterGroupMessageDataType> SPtr;
        typedef std::vector<UadpWriterGroupMessageDataType::SPtr> Vec;
    
        UadpWriterGroupMessageDataType(void);
        UadpWriterGroupMessageDataType(const UadpWriterGroupMessageDataType& value);
        virtual ~UadpWriterGroupMessageDataType(void);
        
        OpcUaUInt32& groupVersion(void);
        DataSetOrderingType& dataSetOrdering(void);
        OpcUaUadpNetworkMessageContentMask& networkMessageContentMask(void);
        OpcUaDuration& samplingOffset(void);
        OpcUaDurationArray& publishingOffset(void);
        
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
        
        void copyTo(UadpWriterGroupMessageDataType& value);
        bool operator==(const UadpWriterGroupMessageDataType& value);
        bool operator!=(const UadpWriterGroupMessageDataType& value);
        UadpWriterGroupMessageDataType& operator=(const UadpWriterGroupMessageDataType& value);
    
      private:
        OpcUaUInt32 groupVersion_;
        DataSetOrderingType dataSetOrdering_;
        OpcUaUadpNetworkMessageContentMask networkMessageContentMask_;
        OpcUaDuration samplingOffset_;
        OpcUaDurationArray publishingOffset_;
    
    };
    
    class DLLEXPORT UadpWriterGroupMessageDataTypeArray
    : public OpcUaArray<UadpWriterGroupMessageDataType::SPtr, SPtrTypeCoder<UadpWriterGroupMessageDataType> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<UadpWriterGroupMessageDataTypeArray> SPtr;
    };

}

#endif
