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

#ifndef __OpcUaStackCore_ModificationInfo_h__
#define __OpcUaStackCore_ModificationInfo_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaArray.h"

namespace OpcUaStackCore
{

	typedef enum
	{
		HistoryUpdateMode_Insert = 1,
		HistoryUpdateMode_Replace = 2,
		HistoryUpdateMode_Update = 3,
		HistoryUpdateMode_Delete = 4
	} HistoryUpdateMode;

	class DLLEXPORT ModificationInfo
	: public  Object
	{
	  public:
		typedef boost::shared_ptr<ModificationInfo> SPtr;

		ModificationInfo(void);
		virtual ~ModificationInfo(void);

		void username(const OpcUaString& username);
		void username(const std::string& username);
		OpcUaString& username(void);
		void modificationTime(const UtcTime& modificationTime);
		void modificationTime(const boost::posix_time::ptime& modificationTime);
		UtcTime& modificationTime(void);
		void updateType(const HistoryUpdateMode updateType);
		HistoryUpdateMode updateType(void);

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		OpcUaString username_;
		UtcTime modificationTime_;
		HistoryUpdateMode updateType_;
	};

	class ModificationInfoArray
	: public OpcUaArray<ModificationInfo::SPtr, SPtrTypeCoder<ModificationInfo> >
	, public Object
	{
	  public:
		typedef boost::shared_ptr<ModificationInfoArray> SPtr;
	};

}

#endif
