/*
    DataTypeClass: ViewAttributes

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_ViewAttributes_h__
#define __OpcUaStackCore_ViewAttributes_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/JsonFormatter.h"
#include "OpcUaStackCore/StandardDataTypes/NodeAttributes.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT ViewAttributes
    : public NodeAttributes
    {
      public:
        typedef boost::shared_ptr<ViewAttributes> SPtr;
        typedef std::vector<ViewAttributes::SPtr> Vec;
    
        ViewAttributes(void);
        ViewAttributes(const ViewAttributes& value);
        virtual ~ViewAttributes(void);
        
        OpcUaBoolean& containsNoLoops(void);
        OpcUaByte& eventNotifier(void);
        
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
        
        void copyTo(ViewAttributes& value);
        bool operator==(const ViewAttributes& value);
        bool operator!=(const ViewAttributes& value);
        ViewAttributes& operator=(const ViewAttributes& value);
    
      private:
        OpcUaBoolean containsNoLoops_; //!< If TRUE the view contains a tree of non-looping hierarchical references.
        OpcUaByte eventNotifier_; //!< A mask indicating whether events are produced by the view.
    
    };
    
    class DLLEXPORT ViewAttributesArray
    : public OpcUaArray<ViewAttributes::SPtr, SPtrTypeCoder<ViewAttributes> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<ViewAttributesArray> SPtr;
    };

}

#endif
