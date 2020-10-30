/*
   Copyright 2020 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackServer_ForwardTransaction_h__
#define __OpcUaStackServer_ForwardTransaction_h__

#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/Object.h"

#include <vector>

namespace OpcUaStackServer
{
	class DLLEXPORT ForwardTransaction
	{
	  public:
		using SPtr = boost::shared_ptr<ForwardTransaction>;
		using WPtr = boost::weak_ptr<ForwardTransaction>;
		using Vec = std::vector<SPtr>;

		ForwardTransaction(
			void
		);
		~ForwardTransaction(void);

		void forwardJob(const OpcUaStackCore::Object::WPtr& forwardJob);
		OpcUaStackCore::Object::WPtr& forwardJob(void);
		void idx(uint32_t idx);
		uint32_t idx(void);
		void complete(bool complete);
		bool complete(void);

	  private:
		OpcUaStackCore::Object::WPtr forwardJob_;	// reference to the associated job
		uint32_t idx_ = 0;							// index of the entry in the service transaction
		bool complete_ = false;						// transaction completed

	};
}

#endif
