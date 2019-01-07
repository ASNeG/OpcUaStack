/*
    DataTypeClass: HistoryUpdateDetails

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_HistoryUpdateDetails_h__
#define __OpcUaStackCore_HistoryUpdateDetails_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/JsonNumber.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT HistoryUpdateDetails
    : public Object
    , public ExtensionObjectBase
    {
      public:
        typedef boost::shared_ptr<HistoryUpdateDetails> SPtr;
        typedef std::vector<HistoryUpdateDetails::SPtr> Vec;
    
        HistoryUpdateDetails(void);
        HistoryUpdateDetails(const HistoryUpdateDetails& value);
        virtual ~HistoryUpdateDetails(void);
        
        OpcUaNodeId& nodeId(void);
        
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
        
        void copyTo(HistoryUpdateDetails& value);
        bool operator==(const HistoryUpdateDetails& value);
        bool operator!=(const HistoryUpdateDetails& value);
        HistoryUpdateDetails& operator=(const HistoryUpdateDetails& value);
    
      private:
        OpcUaNodeId nodeId_;
    
    };
    
    class HistoryUpdateDetailsArray
    : public OpcUaArray<HistoryUpdateDetails::SPtr, SPtrTypeCoder<HistoryUpdateDetails> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<HistoryUpdateDetailsArray> SPtr;
    };

}

#endif
