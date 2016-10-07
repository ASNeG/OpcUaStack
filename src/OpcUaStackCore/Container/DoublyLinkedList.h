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

#ifndef __OpcUaStackCore_DoublyLinkedList_h__
#define __OpcUaStackCore_DoublyLinkedList_h__

#include "OpcUaStackCore/Base/os.h"

namespace OpcUaStackCore
{
	class DLLEXPORT DoublyLinkedList
	{
	  public:
		DoublyLinkedList(void);
		virtual ~DoublyLinkedList(void);

		void insert(DoublyLinkedList& newEntry);
		void insert(DoublyLinkedList* newEntry);
		void pushAfter(DoublyLinkedList& newEntry);
		void pushAfter(DoublyLinkedList* newEntry);
		void pushBefore(DoublyLinkedList& newEntry);
		void pushBefore(DoublyLinkedList* newEntry);
		void remove(void);
		void erase(void);
		void next(DoublyLinkedList* entry);
		DoublyLinkedList* next(void);
		void last(DoublyLinkedList* entry);
		DoublyLinkedList* last(void);
		bool empty(void);

	  private:
		DoublyLinkedList* next_;
		DoublyLinkedList* last_;
	};

}

#endif
