/*
   Copyright 2016 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackCore/Container/DoublyLinkedList.h"

namespace OpcUaStackCore
{

	DoublyLinkedList::DoublyLinkedList(void)
	: last_(this)
	, next_(this)
	{
	}

	DoublyLinkedList::~DoublyLinkedList(void)
	{
		remove();
	}

	void
	DoublyLinkedList::insert(DoublyLinkedList& entry)
	{
		insert(&entry);
	}

	void
	DoublyLinkedList::insert(DoublyLinkedList* entry)
	{
		entry->next(next());
		entry->last(this);
        next()->last(entry);
		next(entry);
	}

	void
	DoublyLinkedList::pushAfter(DoublyLinkedList& entry)
	{
		insert(entry);
	}

	void
	DoublyLinkedList::pushAfter(DoublyLinkedList* entry)
	{
		insert(entry);
	}

	void
	DoublyLinkedList::pushBefore(DoublyLinkedList& entry)
	{
		last()->insert(entry);
	}

	void
	DoublyLinkedList::pushBefore(DoublyLinkedList* entry)
	{
		last()->insert(entry);
	}

	void
	DoublyLinkedList::remove(void)
	{
#if 0
		if (last_ != next_) {
			next()->last(last_);
			last()->next(next_);
			next_ = this;
			last_ = this;
		}
#endif

		if (last_ == next_&& last_ == this) return;

		next()->last(last_);
		last()->next(next_);
		next_ = this;
		last_ = this;
	}

	void
	DoublyLinkedList::erase(void)
	{
		remove();
		delete this;
	}

	void
	DoublyLinkedList::next(DoublyLinkedList* entry)
	{
		next_ = entry;
	}

	DoublyLinkedList*
	DoublyLinkedList::next(void)
	{
		return next_;
	}

	void
	DoublyLinkedList::last(DoublyLinkedList* entry)
	{
		last_ = entry;
	}

	DoublyLinkedList*
	DoublyLinkedList::last(void)
	{
		return last_;
	}

	bool
	DoublyLinkedList::empty(void)
	{
		return next_ == last_;
	}

}

