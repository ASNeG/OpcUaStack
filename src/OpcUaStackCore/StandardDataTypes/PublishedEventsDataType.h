/*
    DataTypeClass: PublishedEventsDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_PublishedEventsDataType_h__
#define __OpcUaStackCore_PublishedEventsDataType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/JsonFormatter.h"
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
        virtual bool jsonEncode(boost::property_tree::ptree& pt, const std::string& element);
        virtual bool jsonEncode(boost::property_tree::ptree& pt);
        virtual bool jsonDecode(boost::property_tree::ptree& pt, const std::string& element);
        virtual bool jsonDecode(boost::property_tree::ptree& pt);
        virtual void copyTo(ExtensionObjectBase& extensionObjectBase);
        virtual bool equal(ExtensionObjectBase& extensionObjectBase) const;
        virtual void out(std::ostream& os);
        //- ExtensionObjectBase -----------------------------------------------
        
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
