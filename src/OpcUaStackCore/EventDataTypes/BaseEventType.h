/*
   Copyright 2017 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_BaseEventType_h__
#define __OpcUaStackCore_BaseEventType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"

namespace OpcUaStackCore
{

	class DLLEXPORT BaseEventType
	: public Object
	, public ExtensionObjectBase
	{
	  public:
		typedef boost::shared_ptr<BaseEventType> SPtr;

		BaseEventType(void);
		virtual ~BaseEventType(void);

		//- ExtensionObjectBase -----------------------------------------------
		virtual ExtensionObjectBase::SPtr factory(void);
		virtual OpcUaNodeId binaryTypeId(void);
		virtual OpcUaNodeId xmlTypeId(void);
		virtual void opcUaBinaryEncode(std::ostream& os) const;
		virtual void opcUaBinaryDecode(std::istream& is);
		virtual bool encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const;
		virtual bool decode(boost::property_tree::ptree& pt, Xmlns& xmlns);
		virtual void copyTo(ExtensionObjectBase& extensionObjectBase);
		virtual bool equal(ExtensionObjectBase& extensionObjectBase) const;
		virtual void out(std::ostream& os);
		//- ExtensionObjectBase -----------------------------------------------

		void copyTo(BaseEventType& baseEventType);
		bool operator==(const BaseEventType& baseEventType) const;

	  private:
		OpcUaByteString::SPtr eventId_;

#if 0
		   	    <Variable Name="EventId" 	 Type="ByteString" 		 ModellingRule="M"></Variable>
			    <Variable Name="EventType" 	 Type="NodeId" 			 ModellingRule="M"></Variable>
			    <Variable Name="SourceNode"  Type="NodeId"	 		 ModellingRule="M"></Variable>
			    <Variable Name="SourceName"  Type="String" 			 ModellingRule="M"</Variable>
			    <Variable Name="Time" 		 Type="Time" 			 ModellingRule="M"></Variable>
			    <Variable Name="ReceiveTime" Type="Time" 			 ModellingRule="M"></Variable>
			    <Variable Name="LocalTime" 	 Type="TimeZoneDataType" ModellingRule="O"></Variable>
			    <Variable Name="Message" 	 Type="LocalizedText" 	 ModellingRule="M"></Variable>
			    <Variable Name="Severity" 	 Type="UInt16" 			 ModellingRule="M"></Variable>
#endif
	};

}

#endif
