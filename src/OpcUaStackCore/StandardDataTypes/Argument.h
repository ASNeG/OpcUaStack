/*
    DataTypeClass: Argument

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_Argument_h__
#define __OpcUaStackCore_Argument_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT Argument
    : public Object
    , public ExtensionObjectBase
    {
      public:
        typedef boost::shared_ptr<Argument> SPtr;
        typedef std::vector<Argument::SPtr> Vec;
    
        Argument(void);
        Argument(const Argument& value);
        virtual ~Argument(void);
        
        OpcUaString& name(void);
        OpcUaNodeId& dataType(void);
        OpcUaInt32& valueRank(void);
        OpcUaUInt32Array& arrayDimensions(void);
        OpcUaLocalizedText& description(void);
        
        //- ExtensionObjectBase -----------------------------------------------
        virtual ExtensionObjectBase::SPtr factory(void) override;
        virtual std::string namespaceName(void) override;
        virtual std::string typeName(void) override;
        virtual OpcUaNodeId typeId(void) override;
        virtual OpcUaNodeId binaryTypeId(void) override;
        virtual OpcUaNodeId xmlTypeId(void) override;
        virtual OpcUaNodeId jsonTypeId(void) override;
        virtual bool opcUaBinaryEncode(std::ostream& os) const override;
        virtual bool opcUaBinaryDecode(std::istream& is) override;
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
        
        void copyTo(Argument& value);
        bool operator==(const Argument& value);
        bool operator!=(const Argument& value);
        Argument& operator=(const Argument& value);
    
      private:
        OpcUaString name_; //!< The name of the argument.
        OpcUaNodeId dataType_; //!< The data type of the argument.
        OpcUaInt32 valueRank_; //!< Whether the argument is an array type and the rank of the array if it is.
        OpcUaUInt32Array arrayDimensions_; //!< The number of dimensions if the argument is an array type and one or more dimensions have a fixed length.
        OpcUaLocalizedText description_; //!< The description for the argument.
    
    };
    
    class DLLEXPORT ArgumentArray
    : public OpcUaArray<Argument::SPtr, SPtrTypeCoder<Argument> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<ArgumentArray> SPtr;
    };

}

#endif
