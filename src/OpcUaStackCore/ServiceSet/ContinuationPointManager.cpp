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

    void ContinuationPointManager::addContinuationPoint(ContinuationPoint::SPtr continuationPoint)
    {
        boost::mutex::scoped_lock getlock(lmutex_);
        continuationPointMap_.emplace(std::make_pair(continuationPoint->name_, continuationPoint));
    }

    ReferenceDescriptionArray::SPtr
    ContinuationPointManager::find(const OpcUaByteString continuationPoint)
    {

        boost::mutex::scoped_lock getlock(lmutex_);

        ContinuationPoint::Map::iterator it;
        it = continuationPointMap_.find(continuationPoint);

        if (it != continuationPointMap_.end()) return it->second->referenceDescriptionArray_;

		ReferenceDescriptionArray::SPtr referenceDescriptionArray;
		return referenceDescriptionArray;
    }

    void ContinuationPointManager::checkforExpiredContinuationPoints()
    {

        boost::mutex::scoped_lock getlock(lmutex_);

        OpcUaDateTime currentTime(boost::posix_time::second_clock::local_time());
        for (auto it = continuationPointMap_.begin(); it != continuationPointMap_.end(); ++it) {
             if (currentTime.rawDateTime() > it->second->expireTime_.rawDateTime()) {
                 continuationPointMap_.erase(it);
             }
        }

        ioThread_->slotTimer()->start(slotTimerElement_);
    }
    
    void ContinuationPointManager::clearAllContinuationPoints()
    {
        
        boost::mutex::scoped_lock getlock(lmutex_);
        continuationPointMap_.clear();
    }


    void ContinuationPointManager::deleteContinuationPoint(const OpcUaByteString& continuationPoint)
    {
        
        boost::mutex::scoped_lock getlock(lmutex_);

        ContinuationPoint::Map::iterator it;
        it = continuationPointMap_.find(continuationPoint);

        if (it != continuationPointMap_.end())
            continuationPointMap_.erase(it);
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
        ioThread_->slotTimer()->start(slotTimerElement_);
        
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

    ContinuationPoint::ContinuationPoint():name_{"continuationPoint_"}
    {
        
        static uint32_t unique_id = 0;
        // creation of unique id for continuation point
        name_.fromString(name_.toString() + std::to_string(unique_id));
        unique_id++;
    }
    ContinuationPoint::~ContinuationPoint(){}

}
