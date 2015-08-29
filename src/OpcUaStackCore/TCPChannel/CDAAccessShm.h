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

#ifndef __CDAAccessShm_h__
#define __CDAAccessShm_h__

#include "Common/Base/TaskPool.h"
#include "Application/CDA/CDAInterface.h"

class CDAAccessShm : public CDAInterface
{
  public:
    CDAAccessShm(TaskPool& taskPool);
    ~CDAAccessShm(void);

    void start(CDAInterfaceCallback& cdaInterfaceCallback);
    void stop(void);

   	virtual void readValue(const std::string& name, DataValue::Type dataValueType);
	virtual void writeValue(const std::string& name, DataValue::Type dataValueType, DataValue::SPtr dataValueSPtr);
	virtual void subscribeOn(const std::string& name, DataValue::Type dataValueType);
	virtual void subscribeOff(const std::string& name, DataValue::Type dataValueType);
	virtual void reset(void);

  private:
	CDAInterfaceCallback* cdaInterfaceCallback_;
	TaskPool* taskPool_;
	bool running_;
};

#endif
