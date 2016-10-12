/*
   Copyright 2015 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_ViewDescription_h__
#define __OpcUaStackCore_ViewDescription_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaArray.h"

namespace OpcUaStackCore
{

	class DLLEXPORT ViewDescription
	: public  Object
	{
	  public:
		typedef boost::shared_ptr<ViewDescription> SPtr;

		ViewDescription(void);
		virtual ~ViewDescription(void);

		void viewId(const OpcUaNodeId::SPtr viewId);
		OpcUaNodeId::SPtr viewId(void);
		void timestamp(const UtcTime& timestamp);
		void timestamp(const boost::posix_time::ptime& timestamp);
		UtcTime& timestamp(void);
		void viewVersion(const OpcUaUInt32& viewVersion);
		OpcUaUInt32 viewVersion(void);

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		OpcUaNodeId::SPtr viewIdSPtr_;
		UtcTime timestamp_;
		OpcUaUInt32 viewVersion_;
	};

	class ViewDescriptionArray
	: public OpcUaArray<ViewDescription::SPtr, SPtrTypeCoder<ViewDescription> >
	, public Object
	{
	  public:
		typedef boost::shared_ptr<ViewDescriptionArray> SPtr;
	};

}

#endif
