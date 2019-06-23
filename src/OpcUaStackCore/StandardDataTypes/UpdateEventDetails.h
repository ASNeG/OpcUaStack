/*
    DataTypeClass: UpdateEventDetails

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_UpdateEventDetails_h__
#define __OpcUaStackCore_UpdateEventDetails_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/StandardDataTypes/HistoryUpdateDetails.h"
#include "OpcUaStackCore/StandardDataTypes/PerformUpdateType.h"
#include "OpcUaStackCore/StandardDataTypes/EventFilter.h"
#include "OpcUaStackCore/StandardDataTypes/HistoryEventFieldList.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT UpdateEventDetails
    : public HistoryUpdateDetails
    {
      public:
        typedef boost::shared_ptr<UpdateEventDetails> SPtr;
        typedef std::vector<UpdateEventDetails::SPtr> Vec;
    
        UpdateEventDetails(void);
        UpdateEventDetails(const UpdateEventDetails& value);
        virtual ~UpdateEventDetails(void);
        
        PerformUpdateType& performInsertReplace(void);
        EventFilter& filter(void);
        HistoryEventFieldListArray& eventData(void);
        
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
        
        void copyTo(UpdateEventDetails& value);
        bool operator==(const UpdateEventDetails& value);
        bool operator!=(const UpdateEventDetails& value);
        UpdateEventDetails& operator=(const UpdateEventDetails& value);
    
      private:
        PerformUpdateType performInsertReplace_;
        EventFilter filter_;
        HistoryEventFieldListArray eventData_;
    
    };
    
    class DLLEXPORT UpdateEventDetailsArray
    : public OpcUaArray<UpdateEventDetails::SPtr, SPtrTypeCoder<UpdateEventDetails> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<UpdateEventDetailsArray> SPtr;
    };

}

#endif
