/*
    DataTypeClass: ReadRawModifiedDetails

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_ReadRawModifiedDetails_h__
#define __OpcUaStackCore_ReadRawModifiedDetails_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/Base/JsonFormatter.h"
#include "OpcUaStackCore/StandardDataTypes/HistoryReadDetails.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT ReadRawModifiedDetails
    : public HistoryReadDetails
    {
      public:
        typedef boost::shared_ptr<ReadRawModifiedDetails> SPtr;
        typedef std::vector<ReadRawModifiedDetails::SPtr> Vec;
    
        ReadRawModifiedDetails(void);
        ReadRawModifiedDetails(const ReadRawModifiedDetails& value);
        virtual ~ReadRawModifiedDetails(void);
        
        OpcUaBoolean& isReadModified(void);
        OpcUaUtcTime& startTime(void);
        OpcUaUtcTime& endTime(void);
        OpcUaCounter& numValuesPerNode(void);
        OpcUaBoolean& returnBounds(void);
        
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
        
        void copyTo(ReadRawModifiedDetails& value);
        bool operator==(const ReadRawModifiedDetails& value);
        bool operator!=(const ReadRawModifiedDetails& value);
        ReadRawModifiedDetails& operator=(const ReadRawModifiedDetails& value);
    
      private:
        OpcUaBoolean isReadModified_;
        OpcUaUtcTime startTime_;
        OpcUaUtcTime endTime_;
        OpcUaCounter numValuesPerNode_;
        OpcUaBoolean returnBounds_;
    
    };
    
    class DLLEXPORT ReadRawModifiedDetailsArray
    : public OpcUaArray<ReadRawModifiedDetails::SPtr, SPtrTypeCoder<ReadRawModifiedDetails> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<ReadRawModifiedDetailsArray> SPtr;
    };

}

#endif
