/// @file system/collections/arraylist.h
#ifndef _aspose_system_collections_arraylist_h_
#define _aspose_system_collections_arraylist_h_

#include "system/object.h"
#include "system/collections/ilist.h"
#include "system/array.h"

#include "system/collections/base_enumerator.h"
#include "system/exceptions.h"
#include "system/cycles_detection.h"

#include <vector>

#include "defines.h"

namespace System { namespace Collections { namespace Generic {

/// Array with dynamic resize.
/// Objects of this class should only be allocated using System::MakeObject() function.
/// Never create instance of this type on stack or using operator new, as it will result in runtime errors and/or assertion faults.
/// Always wrap this class into System::SmartPtr pointer and use this pointer to pass it to functions as argument.
/// @code{.cpp}
/// #include <system/collections/arraylist.h>
/// #include <system/smart_ptr.h>
///
/// using namespace System;
/// using namespace System::Collections::Generic;
///
/// int main()
/// {
///   // Create an empty ArrayList.
///   auto arrayList = MakeObject<ArrayList<int>>();
///
///   // Add some elements.
///   arrayList->Add(10);
///   arrayList->Add(20);
///   arrayList->Add(30);
///
///   // Print the count of items of the ArrayList-class instance.
///   std::cout << arrayList->get_Count() << std::endl;
///
///   // Print the element stored at index 2.
///   std::cout << arrayList->idx_get(2) << std::endl;
///
///   // Clear the ArrayList-class instance.
///   arrayList->Clear();
///
///   // Print ArrayList items count.
///   std::cout << arrayList->get_Count() << std::endl;
///
///   return 0;
/// }
/// /*
/// This code example produces the following output:
/// 3
/// 30
/// 0
/// */
/// @endcode
/// @tparam T Element type.
template<typename T>
class ArrayList : public IList<T>
{
    ASPOSE_COLLECTION_POINTER_MODE_CONTROL(T)

public:
    /// Implemented interface considered basetype.
    typedef IList<T> BaseType;
    /// Pointer to collection; used by copy constructor.
    typedef SharedPtr<ICollection<T>> ICollectionPtr;
    /// Pointer to this type.
    typedef SharedPtr<ArrayList<T>> ThisPtr;
    /// Underlying data type.
    typedef std::vector<T, ASPOSE_COLLECTION_ALLOCATOR_TYPE> storage_type;
    /// Iterator type.
    typedef typename storage_type::iterator iterator;
    /// Const iterator type.
    typedef typename storage_type::const_iterator const_iterator;
    /// Reverse iterator type.
    typedef typename storage_type::reverse_iterator reverse_iterator;
    /// Const reverse iterator type.
    typedef typename storage_type::const_reverse_iterator const_reverse_iterator;

    /// Enumerator to iterate through array in C# style.
    /// Objects of this class should only be allocated using System::MakeObject() function.
    /// Never create instance of this type on stack or using operator new, as it will result in runtime errors and/or assertion faults.
    /// Always wrap this class into System::SmartPtr pointer and use this pointer to pass it to functions as argument.
    class Enumerator : public SimpleEnumerator<storage_type>
    {
    public:
        /// Creates enumerator.
        /// @param data ArrayList to iterate through.
        Enumerator(const ThisPtr& data) : SimpleEnumerator<storage_type>(data, data->m_data) { }
        /// RTTI functions substitutions.
        RTTI_INFO_TEMPLATE_CLASS(ArrayList<T>::Enumerator, System::BaseTypesInfo<System::Object>);
    };

    /// Constructs empty array.
    ArrayList() : ASPOSE_COLLECTION_INIT_ALLOCATOR() {}

    /// Copy constructor.
    /// @param source Collection to copy data from.
    ArrayList(ICollectionPtr source) : ASPOSE_COLLECTION_INIT_ALLOCATOR()
    {
        m_data.reserve(source->get_Count());
        SharedPtr<System::Collections::Generic::IEnumerator<T> > enumearator = source->GetEnumerator();
        while (enumearator->MoveNext())
            m_data.push_back(enumearator->Current());
    }

    /// Creates ArrayList of pre-defined capacity and zero size.
    /// @param capacity Container capacity.
    ArrayList(int capacity) : ASPOSE_COLLECTION_INIT_ALLOCATOR()
    {
        m_data.reserve(capacity);
    }

    /// Gets iterator to the first element of collection.
    /// @return An iterator pointing to the first element in the array list.
    iterator begin() noexcept { return m_data.begin(); }
    /// Gets iterator for a non-existent element behind the end of the collection.
    /// @return An iterator pointing to the theoretical element placed after the end element in the array list.
    iterator end() noexcept { return m_data.end(); }

    /// Gets iterator to the first element of the const-qualified collection.
    /// @return An iterator pointing to the first element in the const-qualified instance of the array list.
    const_iterator begin() const noexcept { return m_data.begin(); }
    /// Gets iterator for a non-existent element behind the end of the const-qualified collection.
    /// @return An iterator pointing to the theoretical element placed after the end element in the const-qualified instance of the array list.
    const_iterator end() const noexcept { return m_data.end(); }

    /// Gets iterator to the first const-qualified element of collection.
    /// @return An iterator pointing to the first const-qualified element in the array list.
    const_iterator cbegin() const noexcept { return m_data.cbegin(); }
    /// Gets iterator for a non-existent const-qualified element behind the end of the collection.
    /// @return An iterator pointing to the theoretical const-qualified element placed after the end element in the array list.
    const_iterator cend() const noexcept { return m_data.cend(); }
    
    /// Gets a reverse iterator to the last element of collection (first in reverse).
    /// @return A reverse iterator pointing to the last element in the array list (first in reverse).
    reverse_iterator rbegin() noexcept { return m_data.rbegin(); }
    /// Gets a reverse iterator for a non-existent element before the start of the collection.
    /// @return A reverse iterator pointing to the theoretical element preceeding the first element in the array list (last in reverse).
    reverse_iterator rend() noexcept { return m_data.rend(); }

    /// Gets a reverse iterator to the last element of the const-qualified collection (first in reverse).
    /// @return A reverse iterator pointing to the last element in the const-qualified array list (first in reverse).
    const_reverse_iterator rbegin() const noexcept { return m_data.rbegin(); }
    /// Gets a reverse iterator for a non-existent element before the start of the const-qualified collection.
    /// @return A reverse iterator pointing to the theoretical element preceeding the first element in the const-qualified array list (last in reverse).
    const_reverse_iterator rend() const noexcept { return m_data.rend(); }

    /// Gets a reverse iterator to the last const-qualified element of collection (first in reverse).
    /// @return A reverse iterator pointing to the last const-qualified element in the array list (first in reverse).
    const_reverse_iterator crbegin() const noexcept { return m_data.crbegin(); }
    /// Gets a reverse iterator for a non-existent const-qualified element before the start of the collection.
    /// @return A reverse iterator pointing to the theoretical const-qualified element preceeding the first element in the array list (last in reverse). 
    const_reverse_iterator crend() const noexcept { return m_data.crend(); }

    /// Gets container capacity.
    /// @return Actual capacity.
    int get_Capacity() const { return m_data.capacity(); }

    /// Sets container capacity. Has no effect on its size.
    /// @param newCapacity Requested capacity. Must be greater or equal to zero.
    void set_Capacity(int newCapacity)
    {
        if (m_data.capacity() == newCapacity)
            return;

        if (newCapacity < 0)
            throw ArgumentOutOfRangeException(u"newCapacity");

        m_data.reserve(newCapacity);

        if(newCapacity != m_data.capacity()) {
            throw OutOfMemoryException();
        }
    }

    /// Copies elements to the end of container.
    /// @param values Enumerable object to copy elements from.
    void AddRange(const SharedPtr<IEnumerable<T>>& values)
    {
        SharedPtr<IEnumerator<T>> enumearator = values->GetEnumerator();
        while (enumearator->MoveNext())
        {
            m_data.push_back(enumearator->Current());
        }
    }

    /// Gets a slice of container.
    /// @param index Slice beginning position.
    /// @param count Slice size.
    /// @return Created slice.
    SharedPtr<ArrayList<T>> GetRange(int index, int count)
    {
        if (index < 0 || count < 0)
        {
            throw ArgumentOutOfRangeException((index < 0) ? u"index" : u"count");
        }

        if (this->get_Count() - index < count)
        {
            throw ArgumentException(u"index");
        }

        auto result = MakeObject<ArrayList<T>>();
        auto length = index + count;
        for (int i = index; i < length; i++)
        {
            result->Add(idx_get(i));
        }

        return result;
    }

    // IList interface
    /// Linear search for element using operator ==.
    /// @param item Item to look for.
    /// @return Index of element (if found) or -1.
    virtual int IndexOf(const T& item) const override
    {
        typename storage_type::const_iterator it = std::find(m_data.begin(), m_data.end(), item);

        if (m_data.end() == it)
            return -1;

        return static_cast<int>(std::distance(m_data.begin(), it));
    }
    /// Inserts item into container position.
    /// @param index Insertion position, must be in range [0, size].
    /// @param item Element to insert.
    virtual void Insert(int index, const T& item) override
    {
        if (index < 0 || index > (int) m_data.size())
            throw ArgumentOutOfRangeException(u"index");

        m_data.insert(m_data.begin()+index, item);
    }
    /// Removes element at specified position.
    /// @param index Index to delete element from, must be in range [0, size).
    virtual void RemoveAt(int index) override
    {
        if (index < 0 || index >= (int) m_data.size())
            throw ArgumentOutOfRangeException(u"index");

        m_data.erase(m_data.begin() + index);
    }
    /// Element accessor.
    /// @param index Index of element to access in range of [0, size).
    /// @return const reference to selected element.
    typename storage_type::const_reference operator[](int index) const
    {
        if (index < 0 || (size_t)index >= m_data.size())
            throw ArgumentOutOfRangeException(u"index");

        return m_data[index];
    }
    /// Element accessor.
    /// @param index Index of element to access in range of [0, size).
    /// @return Reference to selected element.
    typename storage_type::reference operator[](int index)
    {
        if (index < 0 || (size_t)index >= m_data.size())
            throw ArgumentOutOfRangeException(u"index");

        return m_data[index];
    }
    /// Element getter.
    /// @param index Index of element to access in range of [0, size).
    /// @return Copy of specified element.
    virtual T idx_get(int index) const override
    {
        if (index < 0 || (size_t)index >= m_data.size())
            throw ArgumentOutOfRangeException(u"index");

        return m_data[static_cast<typename storage_type::size_type>(index)];
    }
    /// Element setter.
    /// @param index Index of element to access in range of [0, size).
    /// @param value Value to set to specified element.
    virtual void idx_set(int index, T value) override
    {
        if (index < 0 || (size_t)index >= m_data.size())
            throw ArgumentOutOfRangeException(u"index");

        m_data[static_cast<typename storage_type::size_type>(index)] = value;
    }

    // ICollection interface
    /// Gets current container size.
    /// @return Actual container size.
    virtual int  get_Count() const override { return static_cast<int>(m_data.size()); }
    /// Puts element to the end of container.
    /// @param item Element to push.
    virtual void Add(const T& item) override
    {
        m_data.push_back(item);
    }
    /// Deletes all elements from container, sets its size to zero.
    virtual void Clear() override
    {
        m_data.clear();
    }
    /// Checks if container contains specified element, uses operator == for elements comparison.
    /// @param item Item to look for.
    /// @return true if element is present, false otherwise.
    virtual bool Contains(const T& item) const override
    {
        return m_data.end() != std::find(m_data.begin(), m_data.end(), item);
    }
    /// Removes first instance of passed element found in container.
    /// @param item Element to remove.
    /// @return true if element was found and removed, false otherwise.
    virtual bool Remove(const T& item) override
    {
        typename storage_type::iterator it = std::find(m_data.begin(), m_data.end(), item);

        if(m_data.end() != it)
        {
            m_data.erase(it);
            return true;
        }

        return false;
    }
    /// Copies container contents to existing array positions.
    /// @param arr Pointer to destination array.
    /// @param index Destination array position.
    virtual void CopyTo(System::ArrayPtr<T> arr, int index) override
    {
        if (!arr)
            throw ArgumentNullException();

        if (index < 0)
            throw ArgumentOutOfRangeException();

        if (index + get_Count() > arr->get_Length())
            throw ArgumentException();

        SharedPtr<IEnumerator<T>> e = this->GetEnumerator();
        while (e->MoveNext())
            (*arr)[index++] = e->get_Current();
    }

    // IEnumerable interface
    /// Gets enumerator to iterate through container.
    /// @return Enumerator associated with current container.
    virtual SharedPtr<IEnumerator<T> > GetEnumerator() override
    {
        return MakeObject<Enumerator>(MakeSharedPtr(this));
    }

    /// @copydoc System::Collections::Generic::IEnumerable<T>::virtualizeBeginIterator
    System::Details::VirtualizedIteratorBase<T>* virtualizeBeginIterator() override
    {
        return new System::Details::NativeIteratorWrapper<T, iterator>(begin(), end());
    }
    /// @copydoc System::Collections::Generic::IEnumerable<T>::virtualizeEndIterator
    System::Details::VirtualizedIteratorBase<T>* virtualizeEndIterator() override
    {
        return new System::Details::NativeIteratorWrapper<T, iterator>(end(), end());
    }
    /// @copydoc System::Collections::Generic::IEnumerable<T>::virtualizeBeginConstIterator
    System::Details::VirtualizedIteratorBase<T>* virtualizeBeginConstIterator() const override
    {
        return new System::Details::NativeConstIteratorWrapper<T, const_iterator>(begin(), end());
    }
    /// @copydoc System::Collections::Generic::IEnumerable<T>::virtualizeEndConstIterator
    System::Details::VirtualizedIteratorBase<T>* virtualizeEndConstIterator() const override
    {
        return new System::Details::NativeConstIteratorWrapper<T, const_iterator>(end(), end());
    }

protected:
    /// Destructor.
    ~ArrayList() override {}

#ifdef ASPOSE_GET_SHARED_MEMBERS
    /// Provides GetSharedMember() function for container.
    DEFINE_GET_SHARED_MEMBERS(m_data);
#endif

private:
    /// Container elements.
    storage_type m_data;

#ifdef __DBG_FOR_EACH_MEMBER
public:
    /// Provides debug iteration throuhg container.
    /// @param visitor Visitor to apply to each element.
    void DBG_for_each_member(DBG::for_each_member_visitor &visitor) const override
    {
        visitor.add_self(this);
        DBG::for_each_of_Object(this, m_data, visitor);
    }

    /// Provides debug class name.
    /// @return Pointer to string literal specifying class name.
    const char* DBG_class_name() const override { return "ArrayList<T>"; }
#endif
};

}}} // namespace System::Collections::Generic

#endif // _aspose_system_collections_arraylist_h_
