/*
    DataTypeClass: PublishedEventsDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_PublishedEventsDataType_h__
#define __OpcUaStackCore_PublishedEventsDataType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/StandardDataTypes/PublishedDataSetSourceDataType.h"
#include "OpcUaStackCore/StandardDataTypes/SimpleAttributeOperand.h"
#include "OpcUaStackCore/StandardDataTypes/ContentFilter.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT PublishedEventsDataType
    : public PublishedDataSetSourceDataType
    {
      public:
        typedef boost::shared_ptr<PublishedEventsDataType> SPtr;
        typedef std::vector<PublishedEventsDataType::SPtr> Vec;
    
        PublishedEventsDataType(void);
        PublishedEventsDataType(const PublishedEventsDataType& value);
        virtual ~PublishedEventsDataType(void);
        
        OpcUaNodeId& eventNotifier(void);
        SimpleAttributeOperandArray& selectedFields(void);
        ContentFilter& filter(void);
        
        //- ExtensionObjectBase -----------------------------------------------
        virtual ExtensionObjectBase::SPtr factory(void) override;
        virtual std::string namespaceName(void) override;
        virtual std::string typeName(void) override;
        virtual OpcUaNodeId typeId(void) override;
        virtual OpcUaNodeId binaryTypeId(void) override;
        virtual OpcUaNodeId xmlTypeId(void) override;
        virtual OpcUaNodeId jsonTypeId(void) override;
        virtual bool opcUaBinaryEncode(std::ostream& os) const override;
        virtual bool opcUaBinaryDecode(std::istream& is) override;
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
        
        void copyTo(PublishedEventsDataType& value);
        bool operator==(const PublishedEventsDataType& value);
        bool operator!=(const PublishedEventsDataType& value);
        PublishedEventsDataType& operator=(const PublishedEventsDataType& value);
    
      private:
        OpcUaNodeId eventNotifier_;
        SimpleAttributeOperandArray selectedFields_;
        ContentFilter filter_;
    
    };
    
    class DLLEXPORT PublishedEventsDataTypeArray
    : public OpcUaArray<PublishedEventsDataType::SPtr, SPtrTypeCoder<PublishedEventsDataType> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<PublishedEventsDataTypeArray> SPtr;
    };

}

#endif
