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

#ifndef __OpcUaStackCore_ForwardInfoSync_h__
#define __OpcUaStackCore_ForwardInfoSync_h__

#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/Callback.h"
#include "OpcUaStackCore/Base/os.h"

namespace OpcUaStackCore
{

	class DLLEXPORT ForwardInfoSync
	: public  ObjectPool<ForwardInfoSync>
	{
	  public:
		typedef boost::shared_ptr<ForwardInfoSync> SPtr;

		ForwardInfoSync(void);
		virtual ~ForwardInfoSync(void);

		void setReadCallback(Callback& readCallback);
		void unsetReadCallback(void);
		bool isReadCallback(void);
		Callback& readCallback(void);

		void setWriteCallback(Callback& writeCallback);
		void unsetWriteCallback(void);
		bool isWriteCallback(void);
		Callback& writeCallback(void);

	  private:

		bool readCallbackFlag_;
		bool writeCallbackFlag_;

		Callback readCallback_;
		Callback writeCallback_;

	};

}

#endif
