/*
    DataTypeClass: HistoryEventFieldList

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_HistoryEventFieldList_h__
#define __OpcUaStackCore_HistoryEventFieldList_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT HistoryEventFieldList
    : public Object
    , public ExtensionObjectBase
    {
      public:
        typedef boost::shared_ptr<HistoryEventFieldList> SPtr;
        typedef std::vector<HistoryEventFieldList::SPtr> Vec;
    
        HistoryEventFieldList(void);
        HistoryEventFieldList(const HistoryEventFieldList& value);
        virtual ~HistoryEventFieldList(void);
        
        OpcUaVariantArray& eventFields(void);
        
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
        
        void copyTo(HistoryEventFieldList& value);
        bool operator==(const HistoryEventFieldList& value);
        bool operator!=(const HistoryEventFieldList& value);
        HistoryEventFieldList& operator=(const HistoryEventFieldList& value);
    
      private:
        OpcUaVariantArray eventFields_;
    
    };
    
    class DLLEXPORT HistoryEventFieldListArray
    : public OpcUaArray<HistoryEventFieldList::SPtr, SPtrTypeCoder<HistoryEventFieldList> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<HistoryEventFieldListArray> SPtr;
    };

}

#endif
