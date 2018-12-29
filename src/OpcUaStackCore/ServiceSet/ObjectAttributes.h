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

   Autor: Kai Huebl (kai@huebl-sgh.de)
 */

#ifndef __OpcUaStackCore_ObjectAttributes_h__
#define __OpcUaStackCore_ObjectAttributes_h__

#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/ServiceSet/ExtensibleParameter.h"
#include "OpcUaStackCore/ServiceSet/AttributesDescription.h"


namespace OpcUaStackCore
{

	class DLLEXPORT ObjectAttributes
	: public  Object
	, public ExtensibleParameterBase
	{
	  public:
		typedef boost::shared_ptr<ObjectAttributes> SPtr;

		ObjectAttributes(void);
		virtual ~ObjectAttributes(void);


		//- ExtensibleParameterBase -------------------------------------------
		virtual ExtensibleParameterBase::SPtr factory(void);
		virtual void opcUaBinaryEncode(std::ostream& os) const;
		virtual void opcUaBinaryDecode(std::istream& is);
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