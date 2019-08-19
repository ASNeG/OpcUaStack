/*
    DataTypeClass: UpdateEventDetails

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_UpdateEventDetails_h__
#define __OpcUaStackCore_UpdateEventDetails_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
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
