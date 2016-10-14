/*
   Copyright 2016 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_Argument_h__
#define __OpcUaStackCore_Argument_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"

namespace OpcUaStackCore
{

	class DLLEXPORT Argument
	: public Object
	, public ExtensionObjectBase
	{
	  public:
		typedef boost::shared_ptr<Argument> SPtr;

		Argument(void);
		virtual ~Argument(void);

		OpcUaString& name(void);
		OpcUaNodeId& dataType(void);
		OpcUaInt32& valueRank(void);
		OpcUaUInt32Array::SPtr& arrayDimensions(void);
		OpcUaLocalizedText& description(void);

		void copyTo(Argument& argument);
		bool operator==(const Argument& argument) const;

		//- ExtensionObjectBase -----------------------------------------------
		ExtensionObjectBase::BSPtr factory(void);
		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);
		bool encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const;
		bool decode(boost::property_tree::ptree& pt, Xmlns& xmlns);
		void copyTo(ExtensionObjectBase& extensionObjectBase);
		bool equal(ExtensionObjectBase& extensionObjectBase) const;
		void out(std::ostream& os);
		//- ExtensionObjectBase -----------------------------------------------

	  private:
		OpcUaString name_;
		OpcUaNodeId dataType_;
		OpcUaInt32 valueRank_;
		OpcUaUInt32Array::SPtr arrayDimensions_;
		OpcUaLocalizedText description_;
	};

}

#endif
