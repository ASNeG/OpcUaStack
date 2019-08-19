/*
    DataTypeClass: ContentFilterElement

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_ContentFilterElement_h__
#define __OpcUaStackCore_ContentFilterElement_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/StandardDataTypes/FilterOperator.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaExtensibleParameter.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT ContentFilterElement
    : public Object
    , public ExtensionObjectBase
    {
      public:
        typedef boost::shared_ptr<ContentFilterElement> SPtr;
        typedef std::vector<ContentFilterElement::SPtr> Vec;
    
        ContentFilterElement(void);
        ContentFilterElement(const ContentFilterElement& value);
        virtual ~ContentFilterElement(void);
        
        FilterOperator& filterOperator(void);
        OpcUaExtensibleParameterArray& filterOperands(void);
        
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
        
        void copyTo(ContentFilterElement& value);
        bool operator==(const ContentFilterElement& value);
        bool operator!=(const ContentFilterElement& value);
        ContentFilterElement& operator=(const ContentFilterElement& value);
    
      private:
        FilterOperator filterOperator_;
        OpcUaExtensibleParameterArray filterOperands_;
    
    };
    
    class DLLEXPORT ContentFilterElementArray
    : public OpcUaArray<ContentFilterElement::SPtr, SPtrTypeCoder<ContentFilterElement> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<ContentFilterElementArray> SPtr;
    };

}

#endif
