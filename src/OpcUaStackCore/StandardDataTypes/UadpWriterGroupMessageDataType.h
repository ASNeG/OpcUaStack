/*
    DataTypeClass: UadpWriterGroupMessageDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

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
