/*
    DataTypeClass: Argument

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_Argument_h__
#define __OpcUaStackCore_Argument_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/JsonNumber.h"

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
