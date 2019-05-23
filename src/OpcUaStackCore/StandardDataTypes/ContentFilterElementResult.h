/*
    DataTypeClass: ContentFilterElementResult

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_ContentFilterElementResult_h__
#define __OpcUaStackCore_ContentFilterElementResult_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/Base/JsonFormatter.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT ContentFilterElementResult
    : public Object
    , public ExtensionObjectBase
    {
      public:
        typedef boost::shared_ptr<ContentFilterElementResult> SPtr;
        typedef std::vector<ContentFilterElementResult::SPtr> Vec;
    
        ContentFilterElementResult(void);
        ContentFilterElementResult(const ContentFilterElementResult& value);
        virtual ~ContentFilterElementResult(void);
        
        OpcUaStatus& statusCode(void);
        OpcUaStatusArray& operandStatusCodes(void);
        OpcUaDiagnosticInfoArray& operandDiagnosticInfos(void);
        
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
        
        void copyTo(ContentFilterElementResult& value);
        bool operator==(const ContentFilterElementResult& value);
        bool operator!=(const ContentFilterElementResult& value);
        ContentFilterElementResult& operator=(const ContentFilterElementResult& value);
    
      private:
        OpcUaStatus statusCode_;
        OpcUaStatusArray operandStatusCodes_;
        OpcUaDiagnosticInfoArray operandDiagnosticInfos_;
    
    };
    
    class DLLEXPORT ContentFilterElementResultArray
    : public OpcUaArray<ContentFilterElementResult::SPtr, SPtrTypeCoder<ContentFilterElementResult> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<ContentFilterElementResultArray> SPtr;
    };

}

#endif
