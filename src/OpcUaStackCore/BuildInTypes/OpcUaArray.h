/*
   Copyright 2015-2021 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Author: Kai Huebl (kai@huebl-sgh.de), Aleksey Timin (atimin@gmail.com)
 */

#ifndef __OpcUaStackCore_OpcUaArray_h__
#define __OpcUaStackCore_OpcUaArray_h__

#include <boost/make_shared.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/property_tree/ptree.hpp>
#include <stdint.h>
#include <iostream>
#include <vector>
#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackCore/BuildInTypes/Xmlns.h"
#include "OpcUaStackCore/BuildInTypes/ByteOrder.h"
#include "OpcUaStackCore/BuildInTypes/Json.h"
#include "OpcUaStackCore/BuildInTypes/XmlNumber.h"
#include "OpcUaStackCore/BuildInTypes/JsonNumber.h"
#include "OpcUaStackCore/BuildInTypes/JsonFormatter.h"

namespace OpcUaStackCore
{

	template <typename T>
	class NumberTypeCoder
	{
	  public:
		  typedef enum {
			  LittleEndian,
			  BigEndian,
		  } NumberByteOrder;

		  static bool opcUaBinaryEncode(std::ostream& os, T& value)
		  {
			  return ByteOrder<T>::opcUaBinaryEncodeNumberLE(os, value);
		  }

		  static bool opcUaBinaryDecode(std::istream& is, T& value)
		  {
			  return ByteOrder<T>::opcUaBinaryDecodeNumberLE(is, value);
		  }

		  static bool xmlEncode(
			  boost::property_tree::ptree& pt,
			  T& value,
			  const std::string& element,
			  Xmlns& xmlns
		  )
		  {
			  return XmlNumber::xmlEncode(pt, value, element);
		  }

		  static bool xmlDecode(
			  boost::property_tree::ptree& pt,
			  T& value, const
			  std::string& element,
			  Xmlns& xmlns
		  )
		  {
			  return XmlNumber::xmlDecode(pt, value);
		  }

		  static bool jsonEncode(
			  boost::property_tree::ptree& pt,
			  T& value,
			  const std::string& listElement
		  )
		  {
			  return JsonNumber::jsonEncode(pt, value, listElement);
		  }

		  static bool jsonDecode(
			  const boost::property_tree::ptree& pt,
			  T& value,
			  const std::string& listElement
		  )
		  {
			  return JsonNumber::jsonDecode(pt, value);
		  }

		  static T copy(T& sourceValue, T& destValue)
		  {
			  destValue = sourceValue;
			  return sourceValue;
		  }

		  static void out(std::ostream& os, const T& value) 
		  {
			  os << (int64_t)value;
		  }
	};

	template <typename T>
	class ClassTypeCoder
	{
	  public:
		  static bool opcUaBinaryEncode(std::ostream& os, T& value)
		  {
			  return value.opcUaBinaryEncode(os);
		  }

		  static bool opcUaBinaryDecode(std::istream& is, T& value)
		  {
			  return value.opcUaBinaryDecode(is);
		  }

		  static bool xmlEncode(
			  boost::property_tree::ptree& pt,
			  T& value,
			  const std::string& element,
			  Xmlns& xmlns
		  )
		  {
			  return value.xmlEncode(pt, element, xmlns);
		  }

		  static bool xmlDecode(
			  boost::property_tree::ptree& pt, T& value,
			  const std::string& element,
			  Xmlns& xmlns
		  )
		  {
			  return value.xmlDecode(pt, element, xmlns);
		  }

		  static bool jsonEncode(
			  boost::property_tree::ptree& pt,
			  T& value,
			  const std::string& listElement
		  )
		  {
			  return value.jsonEncode(pt, listElement);
		  }

		  static bool jsonDecode(
			  const boost::property_tree::ptree& pt,
			  T& value,
			  const std::string& listElement
		  )
		  {
			  return value.jsonDecode(pt);
		  }

		  static T& copy(T& sourceValue, T& destValue)
		  {
			  sourceValue.copyTo(destValue);
			  return destValue;
		  }

		  static void out(std::ostream& os, const T& value) 
		  {
			  os << value;
		  }
	};

	template <typename T>
	class EnumTypeCoder
	{
	  public:
		  static bool opcUaBinaryEncode(std::ostream& os, T& value)
		  {
			  int32_t v = value;
			  return ByteOrder<int32_t>::opcUaBinaryEncodeNumberLE(os, v);
		  }

		  static bool opcUaBinaryDecode(std::istream& is, T& value)
		  {
			  bool rc = true;

			  int32_t v = 0;
			  rc &= ByteOrder<int32_t>::opcUaBinaryDecodeNumberLE(is, v);
			  if (rc) value = (T)v;

			  return rc;
		  }

		  static bool xmlEncode(
			  boost::property_tree::ptree& pt,
			  T& value,
			  const std::string& element,
			  Xmlns& xmlns
		  )
		  {
			  // FIXME: todo
			  return true;
		  }

		  static bool xmlDecode(
			  boost::property_tree::ptree& pt,
			  T& value,
			  const std::string& element,
			  Xmlns& xmlns
		  )
		  {
			  // FIXME: todo
			  return true;
		  }

		  static bool jsonEncode(
			  boost::property_tree::ptree& pt,
			  T& value,
			  const std::string& listElement
		  )
		  {
			  return JsonNumber::jsonEncode(pt, value, listElement);
		  }

		  static bool jsonDecode(
			  const boost::property_tree::ptree& pt,
			  T& value,
			  const std::string& listElement
		  )
		  {
			  uint32_t val;
			  if (!JsonNumber::jsonDecode(pt, val)) {
				  return false;
			  }
			  value = (T)val;
			  return true;
		  }

		  static T copy(T& sourceValue, T& destValue)
		  {
			  destValue = sourceValue;
			  return sourceValue;
		  }

		  static void out(std::ostream& os, const T& value) 
		  {
			  os << value;
		  }
	};

	template <typename T>
	class SPtrTypeCoder
	{
	  public:
		  static bool opcUaBinaryEncode(std::ostream& os, boost::shared_ptr<T>& value)
		  {
			  return value->opcUaBinaryEncode(os);
		  }

		  static bool opcUaBinaryDecode(std::istream& is, boost::shared_ptr<T>& value)
		  {
			  value = boost::make_shared<T>();
			  return value->opcUaBinaryDecode(is);
		  }

		  static bool xmlEncode(
			  boost::property_tree::ptree& pt,
			  boost::shared_ptr<T>& value,
			  const std::string& element,
			  Xmlns& xmlns
		  )
		  {
			  return value->xmlEncode(pt, xmlns);
		  }

		  static bool xmlDecode(
			  boost::property_tree::ptree& pt,
			  boost::shared_ptr<T>& value,
			  const std::string& element,
			  Xmlns& xmlns
		  )
		  {
			  value = boost::make_shared<T>();
			  return value->xmlDecode(pt, xmlns);
		  }

		  static bool jsonEncode(
			  boost::property_tree::ptree& pt,
			  boost::shared_ptr<T>& value,
			  const std::string& listElement
		  )
		  {
			  return value->jsonEncode(pt, listElement);
		  }

		  static bool jsonDecode(
			  const boost::property_tree::ptree& pt,
			  boost::shared_ptr<T>& value,
			  const std::string& listElement
		  )
		  {
			  value = boost::make_shared<T>();
			  return value->jsonDecode(pt);
		  }

		  static boost::shared_ptr<T> copy( boost::shared_ptr<T>& sourceValue, boost::shared_ptr<T>& destValue)
		  {
			  destValue = boost::make_shared<T>();
			  sourceValue->copyTo(*destValue);
			  return destValue;
		  }

		  static void out(std::ostream& os,  const boost::shared_ptr<T>& value) 
		  {
			  value->out(os);
		  }
	};


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// class OpcUaArray
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	template<typename T, typename CODER = ClassTypeCoder<T> >
	class OpcUaArray 
	: public JsonFormatter
	{
	  public:

		OpcUaArray(size_t maxArrayLen = 1);
		OpcUaArray(const OpcUaArray<T, CODER>& other);
		OpcUaArray(const std::vector<T>& other);
		OpcUaArray(const T& other);
		~OpcUaArray(void); 

		//
		// iterator class
		//
		class iterator;
		iterator begin(void);
		iterator end(void);
		class iterator {
		  public:
			friend class OpcUaArray<T, CODER>;

			iterator(void);
			iterator(int32_t actIndex, OpcUaArray<T, CODER>* arrayRef);
			~iterator(void);

			iterator operator++(int);
			iterator& operator++(void);
			T& operator*(void);
			T* operator->(void);
			bool operator==(const iterator& rhs) const;
			bool operator!=(const iterator& rhs) const;

		  private:
			int32_t actIndex_ = -1;
			OpcUaArray<T, CODER>* arrayRef_ = nullptr;
		};

		void resize(size_t maxArrayLen);
		size_t size(void) const;
		size_t maxSize(void);
		size_t freeSize();
		void clear(void);

		bool set(size_t pos, const T& value);
		bool set(const T& value);
		bool push_back(const T& value);
		bool push_back_vec(const std::vector<T>& valueVec);
		bool get(size_t pos, T& value);
		bool get(T& value);
		bool pop_back(void);

		T& operator [](int idx) {
			return valueArray_[idx];
		}

		T operator [](int idx) const {
			return valueArray_[idx];
		}

		OpcUaArray<T, CODER>& operator=(const OpcUaArray<T, CODER>& other);
		OpcUaArray<T, CODER>& operator=(const std::vector<T>& other);
		OpcUaArray<T, CODER>& operator=(const T& other);
		template<typename V>
			OpcUaArray<T, CODER>& operator=(const std::vector<V>& other);
		template<typename V>
			OpcUaArray<T, CODER>& operator=(const V& other);

		void copyTo(OpcUaArray<T, CODER>& array) const;
		bool operator!=(OpcUaArray<T, CODER>& array);
		bool operator==(OpcUaArray<T, CODER>& array);

		void out(std::ostream& os) const;
		friend std::ostream& operator<<(std::ostream& os, const OpcUaArray<T,CODER>& array) {
			array.out(os);
			return os;
		}

		bool opcUaBinaryEncode(std::ostream& os) const;
		bool opcUaBinaryDecode(std::istream& is);

		bool xmlEncode(
			boost::property_tree::ptree& pt,
			const std::string& element,
			const std::string& listElement,
			Xmlns& xmlns
		) const;
		bool xmlEncode(
			boost::property_tree::ptree& pt,
			const std::string& element,
			Xmlns& xmlns
		) const;
		bool xmlDecode(
			boost::property_tree::ptree& pt,
			const std::string& element,
			const std::string& listElement,
			Xmlns& xmlns
		);
		bool xmlDecode(
			boost::property_tree::ptree& pt,
			const std::string& listElement,
			Xmlns& xmlns
		);


		bool isArray(void) const override;
		bool isNull(void) const override;
		void setNull(void) override;
		size_t arrayLength(void) const override;

	  protected:
		bool jsonEncodeImpl(boost::property_tree::ptree &pt) const override;
		bool jsonDecodeImpl(const boost::property_tree::ptree &pt) override;

	  private:
		void initArray(void);
		void clearArray(void);

		bool isNull_;
		size_t maxArrayLen_;
		size_t actArrayLen_;

		T* valueArray_;
		T value_;
	};

	template<typename T, typename CODER>
	OpcUaArray<T, CODER>::OpcUaArray(size_t maxArrayLen)
	: isNull_(false)
	, maxArrayLen_(maxArrayLen)
	, actArrayLen_(0)
	{
		initArray();
	}

	template<typename T, typename CODER>
	OpcUaArray<T, CODER>::OpcUaArray(const OpcUaArray<T, CODER>& other)
	: isNull_(false)
	, maxArrayLen_(other.size())
	, actArrayLen_(0)
	{
		clearArray();
		initArray();

		const_cast<OpcUaArray<T, CODER>*>(&other)->copyTo(*this);
	}

	template<typename T, typename CODER>
	OpcUaArray<T, CODER>::OpcUaArray(const std::vector<T>& other)
	: isNull_(false)
	, maxArrayLen_(other.size())
	, actArrayLen_(0)
	{
		initArray();
		typename std::vector<T>::const_iterator it;
		for (it = other.begin(); it != other.end(); it++) {
			push_back(*it);
		}
	}

	template<typename T, typename CODER>
		OpcUaArray<T, CODER>::OpcUaArray(const T& other)
	: isNull_(false)
	, maxArrayLen_(1)
	, actArrayLen_(0)
	{
		initArray();
		push_back(other);
	}


	template<typename T, typename CODER>
	OpcUaArray<T, CODER>::~OpcUaArray(void)
	{
		clearArray();
	}

	template<typename T, typename CODER>
	void
	OpcUaArray<T, CODER>::initArray(void)
	{
		if (maxArrayLen_ == 1) {
			valueArray_ = &value_;
		}
		else {
			valueArray_ = new T[maxArrayLen_];
		}
		actArrayLen_ = 0;
	}

	template<typename T, typename CODER>
	void
	OpcUaArray<T, CODER>::clearArray(void)
	{
		if (maxArrayLen_ != 1) {
			delete [] valueArray_;
		}
		valueArray_ = NULL;

		actArrayLen_ = 0;
		maxArrayLen_ = 1;
	}

	template<typename T, typename CODER>
	void
	OpcUaArray<T, CODER>::resize(size_t maxArrayLen)
	{
		isNull_ = false;
		clearArray();
		maxArrayLen_ = maxArrayLen;
		initArray();
	}

	template<typename T, typename CODER>
	size_t
	OpcUaArray<T, CODER>::size(void) const
	{
		return actArrayLen_;
	}

	template<typename T, typename CODER>
	size_t
	OpcUaArray<T, CODER>::maxSize(void)
	{
		return maxArrayLen_;
	}

	template<typename T, typename CODER>
	size_t
	OpcUaArray<T, CODER>::freeSize(void)
	{
		return maxArrayLen_ - actArrayLen_;
	}

	template<typename T, typename CODER>
	void
	OpcUaArray<T, CODER>::clear(void)
	{
		clearArray();
		initArray();
	}

	template<typename T, typename CODER>
	bool
	OpcUaArray<T, CODER>::isNull(void) const
	{
		return isNull_;
	}

	template<typename T, typename CODER>
	void
	OpcUaArray<T, CODER>::setNull(void)
	{
		clearArray();
		initArray();
		isNull_ = true;
	}

	template<typename T, typename CODER>
	size_t
	OpcUaArray<T, CODER>::arrayLength(void) const
	{
		return actArrayLen_;
	}

	template<typename T, typename CODER>
	bool
	OpcUaArray<T, CODER>::set(size_t pos, const T& value)
	{
		if (pos >= maxArrayLen_) {
			return false;
		}
		valueArray_[pos] = value;

		if (pos+1 > actArrayLen_) {
			actArrayLen_ = pos + 1;
		}
		return true;
	}

	template<typename T, typename CODER>
	bool
	OpcUaArray<T, CODER>::set(const T& value)
	{
		return set(0, value);
	}

	template<typename T, typename CODER>
	bool
	OpcUaArray<T, CODER>::push_back(const T& value)
	{
		return set(actArrayLen_, value);
	}

	template<typename T, typename CODER>
	bool
	OpcUaArray<T, CODER>::push_back_vec(const std::vector<T>& valueVec)
	{
		for (uint32_t idx = 0; idx<valueVec.size(); idx++) {
			if (!push_back(valueVec[idx])) {
				return false;
			}
		}
		return true;
	}

	template<typename T, typename CODER>
	bool 
	OpcUaArray<T, CODER>::get(size_t pos, T& value)
	{
		if (pos >= actArrayLen_) {
			return false;
		}

		value = valueArray_[pos];
		return true;
	}

	template<typename T, typename CODER>
	bool 
	OpcUaArray<T, CODER>::get(T& value)
	{
		return get(0, value);
	}

	template<typename T, typename CODER>
	bool
	OpcUaArray<T, CODER>::pop_back(void)
	{
		if (actArrayLen_ <= 0) return false;
		actArrayLen_--;
		return true;
	}

	template<typename T, typename CODER>
	OpcUaArray<T, CODER>&
	OpcUaArray<T, CODER>::operator=(const OpcUaArray<T, CODER>& other)
	{
		const_cast<OpcUaArray<T, CODER>*>(&other)->copyTo(*this);
		return *this;
	}

	template<typename T, typename CODER>
	OpcUaArray<T, CODER>&
	OpcUaArray<T, CODER>::operator=(const std::vector<T>& other)
	{
		typename std::vector<T>::const_iterator it;
		resize(other.size());
		for (it = other.begin(); it != other.end(); it++) {
			push_back(*it);
		}
		return *this;
	}

	template<typename T, typename CODER>
	OpcUaArray<T, CODER>&
	OpcUaArray<T, CODER>::operator=(const T& other)
	{
		resize(1);
		set(0, other);
		return *this;
	}

	template<typename T, typename CODER>
	template<typename V>
	OpcUaArray<T, CODER>&
	OpcUaArray<T, CODER>::operator=(const std::vector<V>& other)
	{
		typename std::vector<T>::iterator it;
		resize(other.size());
		for (it = other.begin(); it != other.end(); it++) {
			push_back(boost::make_shared<T>(other));
		}
		return *this;
	}

	template<typename T, typename CODER>
	template<typename V>
	OpcUaArray<T, CODER>&
	OpcUaArray<T, CODER>::operator=(const V& other)
	{
		resize(1);
		set(0, boost::make_shared<T>(other));
		return *this;
	}

	template<typename T, typename CODER>
	void 
	OpcUaArray<T, CODER>::copyTo(OpcUaArray<T, CODER>& array) const
	{
		if (isNull_) {
			array.setNull();
			return;
		}
		if (actArrayLen_ == 0) return;
		array.resize(actArrayLen_);
		for (size_t idx=0; idx<actArrayLen_; idx++) {
			T destValue;
			CODER::copy(valueArray_[idx], destValue);
			array.set(idx, destValue);
		}
	}

	template<typename T, typename CODER>
	bool 
	OpcUaArray<T, CODER>::operator!=(OpcUaArray<T, CODER>& array)
	{
		return !operator==(array);
	}

	template<typename T, typename CODER>
	bool 
	OpcUaArray<T, CODER>::operator==(OpcUaArray<T, CODER>& array)
	{
		if (size() != array.size()) return false;
		if (isNull() != array.isNull()) return false;
		for (uint32_t pos = 0; pos < size();  pos++) {
			T value1, value2;
			get(pos, value1);
			array.get(pos, value2);
			if (value1 != value2) return false;
		}
		return true;
	}

	template<typename T, typename CODER>
	void 
	OpcUaArray<T, CODER>::out(std::ostream& os) const
	{
		bool first = true;

		os << "[";
		for (size_t idx=0; idx<actArrayLen_; idx++) {
			if (!first) os << ",";
			os << "{";
			CODER::out(os, valueArray_[idx]);
			os << "}";
			first = false;
		}
		os << "]";
	}

	template<typename T, typename CODER>
	bool
	OpcUaArray<T, CODER>::opcUaBinaryEncode(std::ostream& os) const
	{
		bool rc = true;

		rc &= ByteOrder<uint32_t>::opcUaBinaryEncodeNumberLE(os, static_cast<uint32_t>(actArrayLen_));
		for (size_t idx=0; idx<actArrayLen_; idx++) {
			rc &= CODER::opcUaBinaryEncode(os, valueArray_[idx]);
		}

		return rc;
	}
	
	template<typename T, typename CODER>
	bool
	OpcUaArray<T, CODER>::opcUaBinaryDecode(std::istream& is)
	{
		bool rc = true;

		int32_t arrayLength = 0;
		rc &= ByteOrder<int32_t>::opcUaBinaryDecodeNumberLE(is, arrayLength);
		if (arrayLength <= 0) {
			return rc;
		}

		resize(arrayLength);
		for (int32_t idx=0; idx<arrayLength; idx++) {
			T value;
			rc &= CODER::opcUaBinaryDecode(is, value);
			push_back(value);
		}

		return rc;
	}

	template<typename T, typename CODER>
	bool
	OpcUaArray<T, CODER>::xmlEncode(
		boost::property_tree::ptree& pt,
		const std::string& element,
		const std::string& listElement,
		Xmlns& xmlns
	) const
	{
		if (isNull_) {
			return true;
		}

		boost::property_tree::ptree tmpTree;
		if (!xmlEncode(tmpTree, listElement, xmlns)) {
			Log(Error, "OpcUaArray xml encoder error")
				.parameter("Element", element)
				.parameter("ListElement", listElement);
			return false;
		}

		pt.add_child(element, tmpTree);
		return true;
	}

	template<typename T, typename CODER>
	bool
	OpcUaArray<T, CODER>::xmlEncode(
		boost::property_tree::ptree& pt,
		const std::string& listElement,
		Xmlns& xmlns
	) const
	{
		if (isNull_) {
			return true;
		}

		for (uint32_t idx=0; idx<actArrayLen_; idx++) {
			if (!CODER::xmlEncode(pt, valueArray_[idx], listElement, xmlns)) {
				Log(Error, "OpcUaArray xml encoder error")
					.parameter("ListElement", listElement);
				return false;
			}
		}
		return true;
	}

	template<typename T, typename CODER>
	bool
	OpcUaArray<T, CODER>::xmlDecode(
		boost::property_tree::ptree& pt,
		const std::string& element,
		const std::string& listElement,
		Xmlns& xmlns
	)
	{
		boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
		if (!tree) return false;
		return xmlDecode(*tree, listElement, xmlns);
	}

	template<typename T, typename CODER>
	bool
	OpcUaArray<T, CODER>::xmlDecode(
		boost::property_tree::ptree& pt,
		const std::string& listElement,
		Xmlns& xmlns
	)
	{
		size_t arrayLength = 0;
		arrayLength = pt.size();

		if (arrayLength == 0) {
			return true;
		}

		resize(arrayLength);
		boost::property_tree::ptree::iterator it;
		for (it = pt.begin(); it != pt.end(); it++) {
			boost::property_tree::ptree arrayElement = it->second;

			T value;
			if (!CODER::xmlDecode(arrayElement, value, listElement, xmlns)) {
				Log(Error, "OpcUaArray xml decoder error")
					.parameter("ListElement", listElement);
				return false;
			}
			push_back(value);
		}
		return true;
	}

	template<typename T, typename CODER>
	bool
	OpcUaArray<T, CODER>::jsonEncodeImpl(
		boost::property_tree::ptree& pt
	) const
	{
		if (isNull_) {
			return true;
		}

		if (actArrayLen_ == 0) {
			pt.put_value("__EmptyArray__");
			return true;
		}

		for (uint32_t idx=0; idx<actArrayLen_; idx++) {
			if (!CODER::jsonEncode(pt, valueArray_[idx], "")) {
				Log(Error, "OpcUaArray json encoder error");
				return false;
			}
		}
		return true;
	}

	template<typename T, typename CODER>
	bool
	OpcUaArray<T, CODER>::jsonDecodeImpl(
		const boost::property_tree::ptree& pt
	)
	{
		size_t arrayLength = 0;
		arrayLength = pt.size();

		if (arrayLength == 0) {
			return true;
		}

		resize(arrayLength);
		boost::property_tree::ptree::const_iterator it;
		for (it = pt.begin(); it != pt.end(); it++) {
			const boost::property_tree::ptree arrayElement = it->second;

			T value;
			if (!CODER::jsonDecode(arrayElement, value, "")) {
				Log(Error, "OpcUaArray json decoder error");
				return false;
			}
			push_back(value);
		}
		return true;
	}

	template<typename T, typename CODER>
	bool
	OpcUaArray<T, CODER>::isArray(void) const
	{
		return true;
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// implementation iterator functions
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	template<typename T, typename CODER>
	typename OpcUaArray<T, CODER>::iterator
	OpcUaArray<T, CODER>::begin(void)
	{
		return iterator(0, this);
	}

	template<typename T, typename CODER>
	typename OpcUaArray<T, CODER>::iterator
	OpcUaArray<T, CODER>::end(void)
	{
		return iterator(-1, this);
	}

	template<typename T, typename CODER>
	OpcUaArray<T, CODER>::iterator::iterator(int32_t actIndex, OpcUaArray<T, CODER>* arrayRef)
	{
		arrayRef_ = arrayRef;
		if (arrayRef_->actArrayLen_ <= 0 || actIndex >= arrayRef_->actArrayLen_ ) {
			actIndex_ = -1;
		}
		else {
			actIndex_ = actIndex;
		}
	}

	template<typename T, typename CODER>
	OpcUaArray<T, CODER>::iterator::~iterator(void)
	{
		arrayRef_ = nullptr;
		actIndex_ = -1;
	}


	template<typename T, typename CODER>
	typename OpcUaArray<T, CODER>::iterator
	OpcUaArray<T, CODER>::iterator::operator++(int)
	{
		iterator it(actIndex_, arrayRef_);
		++(*this);
		return it;
	}

	template<typename T, typename CODER>
	typename OpcUaArray<T, CODER>::iterator::iterator&
	OpcUaArray<T, CODER>::iterator::operator++(void)
	{
		actIndex_++;
		if (actIndex_ >= arrayRef_->actArrayLen_) {
			actIndex_ = -1;
		}
		return *this;
	}

	template<typename T, typename CODER>
	T&
	OpcUaArray<T, CODER>::iterator::operator*(void)
	{
		return arrayRef_->valueArray_[actIndex_];
	}

	template<typename T, typename CODER>
	T*
	OpcUaArray<T, CODER>::iterator::operator->(void)
	{
		return &arrayRef_->valueArray_[actIndex_];
	}

	template<typename T, typename CODER>
	bool
	OpcUaArray<T, CODER>::iterator::operator==(const iterator& rhs) const
	{
		return actIndex_ == rhs.actIndex_;
	}

	template<typename T, typename CODER>
	bool
	OpcUaArray<T, CODER>::iterator::operator!=(const iterator& rhs) const
	{
		return actIndex_ != rhs.actIndex_;
	}

}

#endif
