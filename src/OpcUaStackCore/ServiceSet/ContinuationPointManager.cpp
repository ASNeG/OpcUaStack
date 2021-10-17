#include "OpcUaStackCore/ServiceSet/ContinuationPointManager.h"

namespace OpcUaStackCore
{

    ContinuationPointManager::ContinuationPointManager(void)
    : ioThread_(), lmutex_(), slotTimerElement_()
    {

	  	slotTimerElement_ = boost::make_shared<SlotTimerElement>();
	  	slotTimerElement_->timeoutCallback(
	  		ioThread_->createStrand(),
	  		[this](void) {
	  		    this->checkforExpiredContinuationPoints();
	  	    }
	  	);
	  	slotTimerElement_->expireTime(boost::posix_time::microsec_clock::local_time(), 60000);
	  	ioThread_->slotTimer()->start(slotTimerElement_);
    }

    ContinuationPointManager::~ContinuationPointManager(void)
    {
    }

    void ContinuationPointManager::addContinuationPoint(ContinuationPoint::SPtr continuationPoint_)
    {
        boost::mutex::scoped_lock getlock(lmutex_);
        continuationPointMap.emplace(std::make_pair(continuationPoint_->name, continuationPoint_));
    }

    ReferenceDescriptionArray::SPtr
    ContinuationPointManager::find(const OpcUaByteString _continuationPoint)
    {

        boost::mutex::scoped_lock getlock(lmutex_);

        ContinuationPoint::Map::iterator it;
        it = continuationPointMap.find(_continuationPoint);

        if (it != continuationPointMap.end()) return it->second->referenceDescriptionArray;

		ReferenceDescriptionArray::SPtr referenceDescriptionArray;
		return referenceDescriptionArray;
    }

    void ContinuationPointManager::checkforExpiredContinuationPoints()
    {

        boost::mutex::scoped_lock getlock(lmutex_);

        for (auto it = continuationPointMap.begin(); it != continuationPointMap.end(); ++it) {
             OpcUaDateTime currentTime(boost::posix_time::second_clock::local_time());
             if (currentTime.rawDateTime() > it->second->expireTime.rawDateTime()) {
                
                 continuationPointMap.erase(it);
             }
        }
    }
    
    void ContinuationPointManager::clearAllContinuationPoints()
    {
        
        boost::mutex::scoped_lock getlock(lmutex_);
        continuationPointMap.clear();
    }


    void ContinuationPointManager::deleteContinuationPoint(const OpcUaByteString& _continuationPoint)
    {
        
        boost::mutex::scoped_lock getlock(lmutex_);

        ContinuationPoint::Map::iterator it;
        it = continuationPointMap.find(_continuationPoint);

        if (it != continuationPointMap.end())
            continuationPointMap.erase(it);
    }

    ContinuationPoint::ContinuationPoint():name{"continuationPoint_"}
    {
        
        static uint32_t unique_id = 0;
        // creation of unique id for continuation point
        name.fromString(name.toString() + std::to_string(unique_id));
        unique_id++;
    }
    ContinuationPoint::~ContinuationPoint(){}

}