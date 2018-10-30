/*
   Copyright 2018 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_OpcUaExtensibleParameter_h__
#define __OpcUaStackCore_OpcUaExtensibleParameter_h__

#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaArray.h"

namespace OpcUaStackCore
{

	class DLLEXPORT OpcUaExtensibleParameter
	: public  Object
	, public ExtensionObjectBase
	{
	  public:
		typedef boost::shared_ptr<OpcUaExtensibleParameter> SPtr;

		OpcUaExtensibleParameter(void);
		~OpcUaExtensibleParameter(void);

		OpcUaNodeId& parameterTypeId(void);
		ExtensionObjectBase::SPtr& eoSPtr(void);

        //- ExtensionObjectBase -----------------------------------------------
        virtual ExtensionObjectBase::SPtr factory(void);
        virtual OpcUaNodeId binaryTypeId(void);
        virtual OpcUaNodeId xmlTypeId(void);
        virtual void opcUaBinaryEncode(std::ostream& os) const;
        virtual void opcUaBinaryDecode(std::istream& is);
        virtual bool encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const;
        virtual bool decode(boost::property_tree::ptree& pt, Xmlns& xmlns);
        virtual bool xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns);
        virtual bool xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns);
        virtual bool xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns);
        virtual bool xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns);
        virtual void copyTo(ExtensionObjectBase& extensionObjectBase);
        virtual bool equal(ExtensionObjectBase& extensionObjectBase) const;
        virtual void out(std::ostream& os);
        //- ExtensionObjectBase -----------------------------------------------

        void copyTo(OpcUaExtensibleParameter& value);
        bool operator==(const OpcUaExtensibleParameter& value) const;
        bool operator!=(const OpcUaExtensibleParameter& value) const;
        OpcUaExtensibleParameter& operator=(const OpcUaExtensibleParameter& value);

	  private:
		OpcUaNodeId parameterTypeId_;
		ExtensionObjectBase::SPtr eoSPtr_;
	};

	class OpcUaExtensibleParameterArray
	: public OpcUaArray<OpcUaExtensibleParameter::SPtr, SPtrTypeCoder<OpcUaExtensibleParameter> >
	, public Object
	{
	  public:
		typedef boost::shared_ptr<OpcUaExtensibleParameterArray> SPtr;
	};

}

#endif
