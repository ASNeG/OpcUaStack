/*
   Copyright 2015-2019 Kai Huebl (kai@huebl-sgh.de)

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
#ifndef __OpcUaStackClient_ServiceConfigBase_h__
#define __OpcUaStackClient_ServiceConfigBase_h__

#include "OpcUaStackCore/Utility/IOThread.h"

namespace OpcUaStackClient
{

	class DLLEXPORT ServiceConfigBase
	{
	  public:
		typedef boost::shared_ptr<ServiceConfigBase> SPtr;
		 
		ServiceConfigBase(const std::string& ioThreadName);
		virtual ~ServiceConfigBase(void);

	    void ioThreadName(const std::string& ioThreadName);
	    std::string ioThreadName(void);

	   private:
		std::string ioThreadName_;
	};

}

#endif
