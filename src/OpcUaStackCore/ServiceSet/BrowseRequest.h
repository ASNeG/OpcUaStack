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

#ifndef __OpcUaStackCore_BrowseRequest_h__
#define __OpcUaStackCore_BrowseRequest_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/SecureChannel/RequestHeader.h"
#include "OpcUaStackCore/ServiceSet/ViewDescription.h"
#include "OpcUaStackCore/ServiceSet/BrowseDescription.h"

namespace OpcUaStackCore
{

	class DLLEXPORT BrowseRequest
	: public  Object
	{
	  public:
		typedef boost::shared_ptr<BrowseRequest> SPtr;

		BrowseRequest(void);
		virtual ~BrowseRequest(void);

		void view(const ViewDescription& view);
		ViewDescription& view(void);
		void requestMaxReferencesPerNode(const OpcUaUInt32& requestMaxReferencesPerNode);
		OpcUaUInt32 requestMaxReferencesPerNode(void);
		void nodesToBrowse(const BrowseDescriptionArray::SPtr nodesToBrowse);
		BrowseDescriptionArray::SPtr nodesToBrowse(void) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		ViewDescription view_;
		OpcUaUInt32 requestMaxReferencesPerNode_;
		BrowseDescriptionArray::SPtr nodesToBrowseArraySPtr_;
	};

}

#endif
