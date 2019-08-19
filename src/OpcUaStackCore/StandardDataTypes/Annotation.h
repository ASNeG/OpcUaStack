/*
    DataTypeClass: Annotation

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_Annotation_h__
#define __OpcUaStackCore_Annotation_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT Annotation
    : public Object
    , public ExtensionObjectBase
    {
      public:
        typedef boost::shared_ptr<Annotation> SPtr;
        typedef std::vector<Annotation::SPtr> Vec;
    
        Annotation(void);
        Annotation(const Annotation& value);
        virtual ~Annotation(void);
        
        OpcUaString& message(void);
        OpcUaString& userName(void);
        OpcUaUtcTime& annotationTime(void);
        
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
        
        void copyTo(Annotation& value);
        bool operator==(const Annotation& value);
        bool operator!=(const Annotation& value);
        Annotation& operator=(const Annotation& value);
    
      private:
        OpcUaString message_;
        OpcUaString userName_;
        OpcUaUtcTime annotationTime_;
    
    };
    
    class DLLEXPORT AnnotationArray
    : public OpcUaArray<Annotation::SPtr, SPtrTypeCoder<Annotation> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<AnnotationArray> SPtr;
    };

}

#endif
