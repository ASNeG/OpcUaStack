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
#include "OpcUaStackCore/Base/ObjectPool.h"
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
