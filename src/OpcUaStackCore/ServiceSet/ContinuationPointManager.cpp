#include "OpcUaStackCore/ServiceSet/ContinuationPointManager.h"

namespace OpcUaStackCore
{

    ContinuationPointManager::ContinuationPointManager(OpcUaStackCore::IOThread::SPtr& ioThread)
    : ioThread_(ioThread), lmutex_(), slotTimerElement_()
    {

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

        ioThread_->slotTimer()->start(slotTimerElement_);
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


    bool ContinuationPointManager::startup()
    {
        strand_ = ioThread_->createStrand();

        slotTimerElement_ = boost::make_shared<OpcUaStackCore::SlotTimerElement>();
	  	slotTimerElement_->timeoutCallback(
	  		strand_,
	  		[this](void) {
	  		    this->checkforExpiredContinuationPoints();
	  	    }
	  	);
        slotTimerElement_->expireFromNow(60000);
	  	
	  	
        ioThread_->slotTimer(boost::make_shared<SlotTimer>());

        //OpcUaStackCore::SlotTimer::SPtr tempPtr = ioThread_->slotTimer();
        //if(tempPtr != nullptr) {
        ioThread_->slotTimer()->start(slotTimerElement_);
        //tempPtr->start(slotTimerElement_);
        //}
        
        return true;
    
    }
    bool ContinuationPointManager::shutdown()
    {
        if (!strand_->running_in_this_thread()) {
			// the function was not called by the strand

			std::promise<void> promise;
			std::future<void> future = promise.get_future();

			strand_->dispatch(
				[this, &promise]() {
					shutdown();
				    promise.set_value();
			    }
			);

			future.wait();
			return true;
		}

		// stop pixtend timer loop
		if (slotTimerElement_.get() != nullptr) {
			ioThread_->slotTimer()->stop(slotTimerElement_);
			slotTimerElement_.reset();
		}

		return true;
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