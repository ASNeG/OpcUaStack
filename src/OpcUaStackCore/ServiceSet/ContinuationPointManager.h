
/*
  Author: Upendar Reddy Sama (upendarreddysama3@gmail.com)
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
//#include <mutex>

namespace OpcUaStackCore
{

    class DLLEXPORT ContinuationPoint:public OpcUaStackCore::Object
    {
        public:
            using SPtr = boost::shared_ptr<ContinuationPoint>;
            using Map = std::map<OpcUaByteString, ContinuationPoint::SPtr>;

            OpcUaStackCore::OpcUaByteString name;
            uint32_t sessionId;
            ReferenceDescriptionArray::SPtr referenceDescriptionArray;
            OpcUaStackCore::OpcUaDateTime expireTime;
            
            

            ContinuationPoint();
            ~ContinuationPoint();

    };
    class DLLEXPORT ContinuationPointManager:public OpcUaStackCore::Object
    {
        private:
            OpcUaStackCore::IOThread::SPtr ioThread_ = nullptr;
            OpcUaStackCore::SlotTimerElement::SPtr slotTimerElement_ = nullptr;
            OpcUaStackCore::ContinuationPoint::Map continuationPointMap;
            boost::mutex lmutex_;


        public:
            using SPtr = boost::shared_ptr<ContinuationPointManager>;
            


        public:
            ContinuationPointManager(void);
            virtual ~ContinuationPointManager(void);
            void addContinuationPoint(OpcUaStackCore::ContinuationPoint::SPtr continuationPoint_);
            ReferenceDescriptionArray::SPtr find(const OpcUaByteString _continuationPoint);
            void checkforExpiredContinuationPoints();
            void clearAllContinuationPoints();
            void deleteContinuationPoint(const OpcUaByteString& _continuationPoint);
    };

    
}

#endif