/*
    DataTypeClass: RelativePathElement

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_RelativePathElement_h__
#define __OpcUaStackCore_RelativePathElement_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT RelativePathElement
    : public Object
    , public ExtensionObjectBase
    {
      public:
        typedef boost::shared_ptr<RelativePathElement> SPtr;
        typedef std::vector<RelativePathElement::SPtr> Vec;
    
        RelativePathElement(void);
        RelativePathElement(const RelativePathElement& value);
        virtual ~RelativePathElement(void);
        
        OpcUaNodeId& referenceTypeId(void);
        OpcUaBoolean& isInverse(void);
        OpcUaBoolean& includeSubtypes(void);
        OpcUaQualifiedName& targetName(void);
        
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
        
        void copyTo(RelativePathElement& value);
        bool operator==(const RelativePathElement& value);
        bool operator!=(const RelativePathElement& value);
        RelativePathElement& operator=(const RelativePathElement& value);
    
      private:
        OpcUaNodeId referenceTypeId_; //!< The type of reference to follow.
        OpcUaBoolean isInverse_; //!< If TRUE the reverse reference is followed.
        OpcUaBoolean includeSubtypes_; //!< If TRUE then subtypes of the reference type are followed.
        OpcUaQualifiedName targetName_; //!< The browse name of the target.
    
    };
    
    class DLLEXPORT RelativePathElementArray
    : public OpcUaArray<RelativePathElement::SPtr, SPtrTypeCoder<RelativePathElement> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<RelativePathElementArray> SPtr;
    };

}

#endif
