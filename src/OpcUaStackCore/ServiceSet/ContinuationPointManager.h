/*
   Copyright 2021 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Upendar Reddy Sama (upendarreddysama3@gmail.com)

 */

#ifndef __OpcUaStackCore__ContinuationPointManager_h__
#define __OpcUaStackCore__ContinuationPointManager_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/BuildInTypes/OpcUaByteString.h"
#include "OpcUaStackCore/ServiceSet/ReferenceDescription.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaDateTime.h"
#include "OpcUaStackCore/Utility/SlotTimer.h"
#include "OpcUaStackCore/Utility/IOThread.h"

#include <boost/thread/mutex.hpp>

#include <map>
#include <list>

namespace OpcUaStackCore
{

    class DLLEXPORT ContinuationPoint : public OpcUaStackCore::Object
    {
    public:
        using SPtr = boost::shared_ptr<ContinuationPoint>;
        using Map = std::map<OpcUaByteString, ContinuationPoint::SPtr>;

        OpcUaStackCore::OpcUaByteString name_;
        uint32_t sessionId_;
        std::list<OpcUaStackCore::ReferenceDescription::SPtr> referenceDescriptionList_;
        
        OpcUaStackCore::OpcUaDateTime expireTime_;
        OpcUaUInt32 requestMaxReferencesPerNode_;

        ContinuationPoint();
        ~ContinuationPoint();
    };

    class DLLEXPORT ContinuationPointManager : public OpcUaStackCore::Object
    {
    private:
        OpcUaStackCore::IOThread::SPtr ioThread_ = nullptr;
        OpcUaStackCore::SlotTimerElement::SPtr slotTimerElement_ = nullptr;
        boost::shared_ptr<boost::asio::io_service::strand> strand_ = nullptr;
        OpcUaStackCore::ContinuationPoint::Map continuationPointMap_;
        boost::mutex lmutex_;

    public:
        using SPtr = boost::shared_ptr<ContinuationPointManager>;

    public:
        ContinuationPointManager(OpcUaStackCore::IOThread::SPtr &ioThread);
        virtual ~ContinuationPointManager(void);
        void addContinuationPoint(OpcUaStackCore::ContinuationPoint::SPtr continuationPoint);
        
        ContinuationPoint::SPtr getContinuationPoint(const OpcUaByteString continuationPointStr);
        OpcUaInt32 getRequestMaxReferencesPerNode(const OpcUaByteString continuationPointStr);
    

        void checkforExpiredContinuationPoints();
        void clearAllContinuationPoints();
        void deleteContinuationPoint(const OpcUaByteString &_continuationPointStr);

        bool startup();
        bool shutdown();
    };

}

#endif
