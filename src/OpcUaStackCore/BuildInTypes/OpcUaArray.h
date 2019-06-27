/*
   Copyright 2015-2018 Kai Huebl (kai@huebl-sgh.de)

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


#include <boost/shared_ptr.hpp>
#include <boost/property_tree/ptree.hpp>
#include <stdint.h>
#include <iostream>
#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/Xmlns.h"
#include "OpcUaStackCore/BuildInTypes/ByteOrder.h"
#include "OpcUaStackCore/BuildInTypes/Json.h"
#include "OpcUaStackCore/BuildInTypes/XmlNumber.h"

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

		  static void opcUaBinaryEncode(std::ostream& os, T& value)
		  {
			  ByteOrder<T>::opcUaBinaryEncodeNumberLE(os, value);
		  }

		  static void opcUaBinaryDecode(std::istream& is, T& value)
		  {
			  ByteOrder<T>::opcUaBinaryDecodeNumberLE(is, value);
		  }

		  static bool encode(boost::property_tree::ptree& pt, T& value)
		  {
			  return Json::encode(pt, value);
		  }

		  static bool decode(boost::property_tree::ptree& pt, T& value)
		  {
			  return Json::decode(pt, value);
		  }

		  static bool xmlEncode(boost::property_tree::ptree& pt, T& value, const std::string& element)
		  {
			  return XmlNumber::xmlEncode(pt, value, element);
		  }

		  static bool xmlDecode(boost::property_tree::ptree& pt, T& value, const std::string& element)
		  {
			  return XmlNumber::xmlDecode(pt, value);
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
		  static void opcUaBinaryEncode(std::ostream& os, T& value) 
		  {
			  value.opcUaBinaryEncode(os);
		  }

		  static void opcUaBinaryDecode(std::istream& is, T& value)
		  {
			  value.opcUaBinaryDecode(is);
		  }

		  static bool encode(boost::property_tree::ptree& pt, T& value)
		  {
			  return value.encode(pt);
		  }

		  static bool decode(boost::property_tree::ptree& pt, T& value)
		  {
			  return value.decode(pt);
		  }

		  static bool xmlEncode(boost::property_tree::ptree& pt, T& value, const std::string& element)
		  {
			  return value.xmlEncode(pt, element);
		  }

		  static bool xmlDecode(boost::property_tree::ptree& pt, T& value, const std::string& element)
		  {
			  return value.xmlDecode(pt, element);
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
		  static void opcUaBinaryEncode(std::ostream& os, T& value) 
		  {
			  int32_t v = value;
			  ByteOrder<int32_t>::opcUaBinaryEncodeNumberLE(os, v);
		  }

		  static void opcUaBinaryDecode(std::istream& is, T& value)
		  {
			  int32_t v = 0;
			  ByteOrder<int32_t>::opcUaBinaryDecodeNumberLE(is, v);
			  value = (T)v;
		  }

		  static bool encode(boost::property_tree::ptree& pt, T& value)
		  {
			  int32_t v = value;
			  pt.put_value(value);
			  return true;
		  }

		  static bool decode(boost::property_tree::ptree& pt, T& value)
		  {
			  int32_t v = 0;
			  try { v = pt.get_value<int32_t>(); } catch(...) { return false; }
			  value = (T)v;
			  return true;
		  }

		  static bool xmlEncode(boost::property_tree::ptree& pt, T& value, const std::string& element)
		  {
			  // FIXME: todo
			  return true;
		  }

		  static bool xmlDecode(boost::property_tree::ptree& pt, T& value, const std::string& element)
		  {
			  // FIXME: todo
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
		  static void opcUaBinaryEncode(std::ostream& os, boost::shared_ptr<T>& value) 
		  {
			  value->opcUaBinaryEncode(os);
		  }

		  static void opcUaBinaryDecode(std::istream& is, boost::shared_ptr<T>& value)
		  {
			  value = constructSPtr<T>();
			  value->opcUaBinaryDecode(is);
		  }

		  static bool encode(boost::property_tree::ptree& pt, boost::shared_ptr<T>& value)
		  {
			  return value->encode(pt);
		  }

		  static bool decode(boost::property_tree::ptree& pt, boost::shared_ptr<T>& value)
		  {
			  value = constructSPtr<T>();
			  return value->decode(pt);
		  }
		  static bool xmlEncode(boost::property_tree::ptree& pt, boost::shared_ptr<T>& value, const std::string& element)
		  {
			  return value->xmlEncode(pt);
		  }

		  static bool xmlDecode(boost::property_tree::ptree& pt, boost::shared_ptr<T>& value, const std::string& element)
		  {
			  value = constructSPtr<T>();
			  return value->xmlDecode(pt);
		  }

		  static boost::shared_ptr<T> copy( boost::shared_ptr<T>& sourceValue, boost::shared_ptr<T>& destValue)
		  {
			  destValue = constructSPtr<T>();
			  sourceValue->copyTo(*destValue);
			  return destValue;
		  }

		  static void out(std::ostream& os,  const boost::shared_ptr<T>& value) 
		  {
			  os << *value;
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
	{
	  public:
		OpcUaArray(size_t maxArrayLen = 1);
		OpcUaArray(const OpcUaArray<T, CODER>& other);
		OpcUaArray(const std::vector<T>& other);
		OpcUaArray(const T& other);
		~OpcUaArray(void); 

		void resize(size_t maxArrayLen);
		size_t size(void) const;
		size_t maxSize(void);
		size_t freeSize();
		void clear(void);
		bool isNull(void);
		void setNull(void);

		bool set(size_t pos, const T& value);
		bool set(const T& value);
		bool push_back(const T& value);
		bool get(size_t pos, T& value);
		bool get(T& value);

		OpcUaArray<T, CODER>& operator=(const OpcUaArray<T, CODER>& other);
		OpcUaArray<T, CODER>& operator=(const std::vector<T>& other);
		OpcUaArray<T, CODER>& operator=(const T& other);
		template<typename V>
		    OpcUaArray<T, CODER>& operator=(const std::vector<V>& other);
		template<typename V>
		    OpcUaArray<T, CODER>& operator=(const V& other);

		void copyTo(OpcUaArray<T, CODER>& array);
		bool operator!=(OpcUaArray<T, CODER>& array);
		bool operator==(OpcUaArray<T, CODER>& array);

		void out(std::ostream& os) const;
		friend std::ostream& operator<<(std::ostream& os, const OpcUaArray<T,CODER>& array) {
			array.out(os);
			return os;
		}

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

		bool encode(boost::property_tree::ptree& pt) const;
		bool decode(boost::property_tree::ptree& pt);

		bool xmlEncode(boost::property_tree::ptree& pt, const std::string& element, const std::string& extElement) const;
		bool xmlEncode(boost::property_tree::ptree& pt, const std::string& element) const;
		bool xmlDecode(boost::property_tree::ptree& pt, const std::string& element);

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
		initArray();
		for (size_t idx = 0; idx < other.size(); idx++) {
			T value;
			get(0, value);
			push_back(value);
		}
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
	OpcUaArray<T, CODER>::isNull(void)
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
			push_back(constructSPtr<T>(other));
		}
		return *this;
	}

	template<typename T, typename CODER>
	template<typename V>
	OpcUaArray<T, CODER>&
	OpcUaArray<T, CODER>::operator=(const V& other)
	{
		resize(1);
		set(0, constructSPtr<T>(other));
		return *this;
	}

	template<typename T, typename CODER>
	void 
	OpcUaArray<T, CODER>::copyTo(OpcUaArray<T, CODER>& array)
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
			CODER::out(os, valueArray_[idx]);
			first = false;
		}
		os << "]";
	}

	template<typename T, typename CODER>
	void 
	OpcUaArray<T, CODER>::opcUaBinaryEncode(std::ostream& os) const
	{
		ByteOrder<uint32_t>::opcUaBinaryEncodeNumberLE(os, static_cast<uint32_t>(actArrayLen_));
		for (size_t idx=0; idx<actArrayLen_; idx++) {
			CODER::opcUaBinaryEncode(os, valueArray_[idx]);
		}
	}
	
	template<typename T, typename CODER>
	void 
	OpcUaArray<T, CODER>::opcUaBinaryDecode(std::istream& is)
	{
		int32_t arrayLength = 0;
		ByteOrder<int32_t>::opcUaBinaryDecodeNumberLE(is, arrayLength);
		if (arrayLength <= 0) {
			return;
		}

		resize(arrayLength);
		for (int32_t idx=0; idx<arrayLength; idx++) {
			T value;
			CODER::opcUaBinaryDecode(is, value);
			push_back(value);
		}
	}

	template<typename T, typename CODER>
	bool
	OpcUaArray<T, CODER>::encode(boost::property_tree::ptree& pt) const
	{
		for (uint32_t idx=0; idx<actArrayLen_; idx++) {
			boost::property_tree::ptree arrayElement;
			if (!CODER::encode(arrayElement, valueArray_[idx])) return false;
			pt.push_back(std::make_pair("", arrayElement));
		}
		return true;
	}

	template<typename T, typename CODER>
	bool
	OpcUaArray<T, CODER>::decode(boost::property_tree::ptree& pt)
	{
		size_t arrayLength = 0;
		arrayLength = pt.size();

		resize(arrayLength);
		boost::property_tree::ptree::iterator it;
		for (it = pt.begin(); it != pt.end(); it++) {
			boost::property_tree::ptree arrayElement = it->second;

			T value;
			if (!CODER::decode(arrayElement, value)) return false;
			push_back(value);
		}
		return true;
	}

	template<typename T, typename CODER>
	bool
	OpcUaArray<T, CODER>::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, const std::string& listElement) const
	{
		if (isNull_) {
			return true;
		}

		boost::property_tree::ptree tmpTree;
		if (!xmlEncode(tmpTree, listElement)) {
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
	OpcUaArray<T, CODER>::xmlEncode(boost::property_tree::ptree& pt, const std::string& element) const
	{
		if (isNull_) {
			return true;
		}

		for (uint32_t idx=0; idx<actArrayLen_; idx++) {
			if (!CODER::xmlEncode(pt, valueArray_[idx], element)) {
				Log(Error, "OpcUaArray xml encoder error")
					.parameter("ListElement", element);
				return false;
			}
		}
		return true;
	}

	template<typename T, typename CODER>
	bool
	OpcUaArray<T, CODER>::xmlDecode(boost::property_tree::ptree& pt, const std::string& element)
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
			if (!CODER::xmlDecode(arrayElement, value, element)) {
				Log(Error, "OpcUaArray xml decoder error")
					.parameter("ListElement", element);
				return false;
			}
			push_back(value);
		}
		return true;
	}

}

#endif
