/*
   Copyright 2015-2018 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_ObjectAttributes_h__
#define __OpcUaStackCore_ObjectAttributes_h__

#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/ServiceSet/AttributesDescription.h"


namespace OpcUaStackCore
{

	class DLLEXPORT ObjectAttributes
	: public Object
	, public ExtensionObjectBase
	{
	  public:
		typedef boost::shared_ptr<ObjectAttributes> SPtr;

		ObjectAttributes(void);
		virtual ~ObjectAttributes(void);


		//- ExtensibleParameterBase -------------------------------------------
	    virtual ExtensionObjectBase::SPtr factory(void);
		virtual std::string namespaceName(void) { return ""; }
		virtual std::string typeName(void) { return ""; }
	    virtual OpcUaNodeId binaryTypeId(void) { return OpcUaNodeId(0); }
	    virtual OpcUaNodeId xmlTypeId(void) { return OpcUaNodeId(0); }
	    virtual OpcUaNodeId jsonTypeId(void) { return OpcUaNodeId(0); }
	    virtual void opcUaBinaryEncode(std::ostream& os) const;
	    virtual void opcUaBinaryDecode(std::istream& is);
	    virtual bool encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const { return true; }
	    virtual bool decode(boost::property_tree::ptree& pt, Xmlns& xmlns) { return true; }
	    virtual bool xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns) { return true; }
	    virtual bool xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns) { return true; }
	    virtual bool xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns) { return true; }
	    virtual bool xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns) { return true; }
	    virtual bool jsonEncode(boost::property_tree::ptree& pt, const std::string& element) { return true; }
	    virtual bool jsonEncode(boost::property_tree::ptree& pt) { return true; }
	    virtual bool jsonDecode(boost::property_tree::ptree& pt, const std::string& element) { return true; }
	    virtual bool jsonDecode(boost::property_tree::ptree& pt) { return true; }
	    virtual void copyTo(ExtensionObjectBase& extensionObjectBase) {}
	    virtual bool equal(ExtensionObjectBase& extensionObjectBase) const { return true; }
	    virtual void out(std::ostream& os) {}
		//- ExtensibleParameterBase -------------------------------------------

        OpcUaUInt32 specifiedAttributes(void) const;
        void displayName(const OpcUaLocalizedText::SPtr displayNameSPtr);
        OpcUaLocalizedText::SPtr& displayName(void);
        void description(const OpcUaLocalizedText::SPtr descriptionSPtr);
        OpcUaLocalizedText::SPtr& description(void);
        void eventNotifier(const EventNotifierAttribute eventNotifier);
        OpcUaByte eventNotifier(void);
        void writeMask(const WriteableAttribute writeMask);
        OpcUaUInt32 writeMask(void);
        void userWriteMask(const WriteableAttribute userWriteMask);
        OpcUaUInt32 userWriteMask(void);

		
	  private:
		OpcUaUInt32 specifiedAttributes_;
		OpcUaLocalizedText::SPtr displayName_;
		OpcUaLocalizedText::SPtr description_;
		OpcUaByte eventNotifier_;
		OpcUaUInt32 writeMask_;
		OpcUaUInt32 userWriteMask_;
	};

}

#endif
