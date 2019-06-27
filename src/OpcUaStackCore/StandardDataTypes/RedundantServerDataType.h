/*
   Copyright 2015-2017 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Samuel Huebl (samuel.huebl@asneg.de)
 */

#ifndef __OpcUaStackCore_RedundantServerDataType_h__
#define __OpcUaStackCore_RedundantServerDataType_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/Xmlns.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"

namespace OpcUaStackCore
{

	class DLLEXPORT RedundantServerDataType
	: public Object
	, public ExtensionObjectBase
	{
	  public:
		typedef boost::shared_ptr<RedundantServerDataType> SPtr;

		RedundantServerDataType(void);
		virtual ~RedundantServerDataType(void);

		OpcUaString& serverId(void);
		void serverId(OpcUaString serverId);
        OpcUaByte& serviceLevel(void);
        void serviceLevel(OpcUaByte serviceLevel);
		OpcUaInt32& serverState(void);
		void serverState(OpcUaInt32 serverState);
		
		void copyTo(RedundantServerDataType& redundantServerDataType);
		bool operator==(const RedundantServerDataType& redundantServerDataType) const;

		//- ExtensionObjectBase -----------------------------------------------
		ExtensionObjectBase::SPtr factory(void);
		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);
		bool xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns);
		bool xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns);
		bool xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns);
		void copyTo(ExtensionObjectBase& extensionObjectBase);
		bool equal(ExtensionObjectBase& extensionObjectBase) const;
		void out(std::ostream& os);
		//- ExtensionObjectBase -----------------------------------------------

	  private:
        OpcUaString serverId_;
        OpcUaByte serviceLevel_;
		OpcUaInt32 serverState_;
	};

}

#endif
