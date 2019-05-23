/*
    DataTypeClass: ReadProcessedDetails

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_ReadProcessedDetails_h__
#define __OpcUaStackCore_ReadProcessedDetails_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/Base/JsonFormatter.h"
#include "OpcUaStackCore/StandardDataTypes/HistoryReadDetails.h"
#include "OpcUaStackCore/StandardDataTypes/AggregateConfiguration.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT ReadProcessedDetails
    : public HistoryReadDetails
    {
      public:
        typedef boost::shared_ptr<ReadProcessedDetails> SPtr;
        typedef std::vector<ReadProcessedDetails::SPtr> Vec;
    
        ReadProcessedDetails(void);
        ReadProcessedDetails(const ReadProcessedDetails& value);
        virtual ~ReadProcessedDetails(void);
        
        OpcUaUtcTime& startTime(void);
        OpcUaUtcTime& endTime(void);
        OpcUaDuration& processingInterval(void);
        OpcUaNodeIdArray& aggregateType(void);
        AggregateConfiguration& aggregateConfiguration(void);
        
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
        
        void copyTo(ReadProcessedDetails& value);
        bool operator==(const ReadProcessedDetails& value);
        bool operator!=(const ReadProcessedDetails& value);
        ReadProcessedDetails& operator=(const ReadProcessedDetails& value);
    
      private:
        OpcUaUtcTime startTime_;
        OpcUaUtcTime endTime_;
        OpcUaDuration processingInterval_;
        OpcUaNodeIdArray aggregateType_;
        AggregateConfiguration aggregateConfiguration_;
    
    };
    
    class DLLEXPORT ReadProcessedDetailsArray
    : public OpcUaArray<ReadProcessedDetails::SPtr, SPtrTypeCoder<ReadProcessedDetails> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<ReadProcessedDetailsArray> SPtr;
    };

}

#endif
