/*
   Copyright 2018-2019 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de)
 */

#ifndef __OpcUaStackCore_OpcUaStatus_h__
#define __OpcUaStackCore_OpcUaStatus_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/BuildInTypes/OpcUaExtensionObjectBase.h"
#include "OpcUaStackCore/BuildInTypes/XmlNumber.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaStatusCode.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT OpcUaStatus
    : public Object
    , public ExtensionObjectBase
    {
      public:
        typedef boost::shared_ptr<OpcUaStatus> SPtr;

        OpcUaStatus(void);
        OpcUaStatus(OpcUaStatusCode enumeration);
        OpcUaStatus(OpcUaStatus& value);
        virtual ~OpcUaStatus(void);
        
        int32_t& value(void);
        void enumeration(OpcUaStatusCode enumeration);
        OpcUaStatusCode enumeration(void);
        OpcUaStatusCode str2Enum(const std::string& enumerationString);
        std::string enum2Str(OpcUaStatusCode enumeration) const;
        std::string enum2Str(void) const;
        std::string toString(void) const;
        bool exist(const std::string& enumerationString);
        bool exist(OpcUaStatusCode enumeration);
        
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
        
        void copyTo(OpcUaStatus& value);
        bool operator==(const OpcUaStatus& value) const;
        bool operator!=(const OpcUaStatus& value) const;
        OpcUaStatus& operator=(const OpcUaStatus& value);
        OpcUaStatus& operator=(const OpcUaStatusCode& value);
		friend std::ostream& operator<<(std::ostream& os, const OpcUaStatus& value) {
			const_cast<OpcUaStatus*>(&value)->out(os);
			return os;
		}
    
      protected:
        bool jsonEncodeImpl(boost::property_tree::ptree& pt) const override;
        bool jsonDecodeImpl(const boost::property_tree::ptree& pt) override;

      private:
        int32_t value_;
    
    };
    
    class DLLEXPORT OpcUaStatusArray
    : public OpcUaArray<OpcUaStatus::SPtr, SPtrTypeCoder<OpcUaStatus> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<OpcUaStatusArray> SPtr;
    };

}

#endif
