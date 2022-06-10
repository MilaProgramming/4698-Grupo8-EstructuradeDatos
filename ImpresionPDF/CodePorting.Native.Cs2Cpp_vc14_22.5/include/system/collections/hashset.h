/// @file system/collections/hashset.h
#ifndef _aspose_system_collections_hashset_h_
#define _aspose_system_collections_hashset_h_

#include "system/object.h"
#include "system/array.h"
#include "system/collections/iset.h"
#include "system/collections/base_enumerator.h"
#include "system/cycles_detection.h"
#include "system/collections/iequality_comparer.h"

#include <unordered_set>

namespace System {
namespace Collections {
namespace Generic {

/// Forward declaration of HashSet class.
template<typename T> class HashSet;

/// Pointer to keep HashSet references.
/// This type is a pointer to manage other object's deletion.
/// It should be allocated on stack and passed to functions either by value or by const reference.
/// @param T Hashed type.
template<typename T>
class ASPOSECPP_SHARED_CLASS HashSetPtr : public SharedPtr<HashSet<T> >
{
public:
    /// Null pointer constructor.
    HashSetPtr() {}
    /// Copy constructor.
    /// @param obj Pointer to copy.
    HashSetPtr(const SharedPtr<HashSet<T> >& obj) : SharedPtr<HashSet<T> >(obj) { }
};

/// Set implementation based on hashing.
/// Objects of this class should only be allocated using System::MakeObject() function.
/// Never create instance of this type on stack or using operator new, as it will result in runtime errors and/or assertion faults.
/// Always wrap this class into System::SmartPtr pointer and use this pointer to pass it to functions as argument.
/// @param T Element type.
/// @code
/// #include "system/array.h"
/// #include "system/collections/hashset.h"
/// #include "system/smart_ptr.h"
///
/// void PrintValues(const System::SharedPtr<const System::Collections::Generic::IEnumerable<int>> & collection)
/// {
///   for (auto item: collection)
///   {
///     std::cout << item << ' ';
///   }
///   std::cout << std::endl;
/// }
///
/// int main()
/// {
///   // Create and fill instances of the HashSet<int> type.
///   auto set1 = System::MakeObject<System::Collections::Generic::HashSet<int>>();
///   auto set2 = System::MakeObject<System::Collections::Generic::HashSet<int>>();
///
///   for (auto i = 0; i < 10; i++)
///   {
///     set1->Add(i);
///     set2->Add(i * 3);
///   }
///
///   // Print items of the sets.
///   PrintValues(set1);
///   PrintValues(set2);
///
///   // Copy values of the sets to the array and print values.
///   auto arr = System::MakeArray<int>(set1->get_Count() + set2->get_Count());
///   set1->CopyTo(arr, 0);
///   set2->CopyTo(arr, set1->get_Count());
///   PrintValues(arr);
///
///   return 0;
/// }
/// /*
/// This code example produces the following output:
/// 8 0 1 2 3 4 5 6 7 9
/// 24 0 3 6 9 12 15 18 21 27
/// 8 0 1 2 3 4 5 6 7 9 24 0 3 6 9 12 15 18 21 27
/// */
/// @endcode
template<typename T>
class ASPOSECPP_SHARED_CLASS HashSet
    : virtual public System::Object
    , public ICollection<T>
{
    ASPOSE_COLLECTION_POINTER_MODE_CONTROL(T)

public:
    /// Self type.
    using ThisType = System::Collections::Generic::HashSet<T>;
    /// Pointer type.
    using ThisPtr = SharedPtr<ThisType>;
    /// Underlying data type.
    using set_t = std::unordered_set<T, EqualityComparerHashAdapter<T>, EqualityComparerAdapter<T>, ASPOSE_COLLECTION_ALLOCATOR_TYPE>;
    /// Iterator type.
    using iterator = typename set_t::iterator;
    /// Const iterator type.
    using const_iterator = typename set_t::const_iterator;

private:
    /// RTTI information.
    RTTI_INFO_TEMPLATE_CLASS(ThisType, System::BaseTypesInfo<System::Object>);

protected:
    /// Internal data structure.
    set_t m_data;

public:
    /// Value type.
    using ValueType = T;
    /// Implemented interface.
    using BaseType = ICollection<T>;
    /// Enumerable interface pointer.
    using IEnumerablePtr = SharedPtr<IEnumerable<T>>;
    /// Enumerator pointer.
    using IEnumeratorPtr = SharedPtr<IEnumerator<T>>;

    /// Enumerator class.
    /// Objects of this class should only be allocated using System::MakeObject() function.
    /// Never create instance of this type on stack or using operator new, as it will result in runtime errors and/or assertion faults.
    /// Always wrap this class into System::SmartPtr pointer and use this pointer to pass it to functions as argument.
    class Enumerator : public SimpleEnumerator<set_t>
    {
    public:
        /// Creates enumerator iterating through @p set object.
        /// @param set Set to iterate through.
        Enumerator(const ThisPtr& set) : SimpleEnumerator<set_t>(set, set->m_data) { }
        /// RTTI information.
        RTTI_INFO_TEMPLATE_CLASS(HashSet<T>::Enumerator, System::BaseTypesInfo<System::Object>);
    };

    /// Creates empty set.
    HashSet() : ASPOSE_COLLECTION_INIT_ALLOCATOR() {}

    /// Creates empty set that uses the specified equality comparer
    /// @param comparer Comparer object to associate with hashset.
    HashSet(const SharedPtr<IEqualityComparer<T>>& comparer)
        : m_data(8, EqualityComparerHashAdapter<T>(comparer), EqualityComparerAdapter<T>(comparer), ASPOSE_COLLECTION_ALLOCATOR)
    {}

    /// Creates hashset based on enumerable values
    HashSet(const SharedPtr<IEnumerable<T>>& items) : ASPOSE_COLLECTION_INIT_ALLOCATOR()
    {
        auto e = items->GetEnumerator();
        while (e->MoveNext())
            m_data.insert(e->get_Current());
    }

    /// Gets iterator to the first element of the const-qualified collection.
    /// @return An iterator pointing to the first element in the const-qualified instance of the hash set.
    const_iterator begin() const noexcept { return m_data.begin(); }
    /// Gets iterator for a non-existent element behind the end of the const-qualified collection.
    /// @return An iterator pointing to the theoretical element placed after the end element in the const-qualified instance of the hash set.
    const_iterator end() const noexcept { return m_data.end(); }

    /// Gets iterator to the first const-qualified element of collection.
    /// @return An iterator pointing to the first const-qualified element in the hash set.
    const_iterator cbegin() const noexcept { return m_data.cbegin(); }
    /// Gets iterator for a non-existent const-qualified element behind the end of the collection.
    /// @return An iterator pointing to the theoretical const-qualified element placed after the end element in the hash set.
    const_iterator cend() const noexcept { return m_data.cend(); }

    /// Creates enumerator.
    /// @return Newly created enumerator.
    IEnumeratorPtr GetEnumerator() override
    {
        return MakeObject<Enumerator>(MakeSharedPtr(this));
    }

    /// Gets number of elements in set.
    /// @return Actual number of elements.
    int get_Count() const override { return ASPOSECPP_CHECKED_CAST(int, m_data.size()); }

    /// Adds element into set.
    /// @param item Element to add.
    void Add(const T& item) override
    {
        TryAdd(item);
    }
    /// Adds element into set.
    /// @param item Item to add.
    /// @return True if element was added, false if already exists.
    bool TryAdd(const T& item)
    {
        if (m_data.find(item) != m_data.end())
            return false;

        m_data.insert(item);
        return true;
    }
    /// Removes element from set.
    /// @param item Element to remove.
    /// @return True if element was found and deleted, false otherwise.
    bool Remove(const T& item) override
    {
        auto it = m_data.find(item);
        if (it == m_data.end())
            return false;

        m_data.erase(it);
        return true;
    }
    /// Deletes all elements in set.
    void Clear() override
    {
        m_data.clear();
    }
    /// Checks if element is present in set.
    /// @param item Item to look for.
    /// @return True if item is present in set, false otherwise.
    bool Contains(const T& item) const override
    {
        return m_data.find(item) != m_data.end();
    }

    /// Underlying data structure accessor.
    /// @return Reference to underlying data structure.
    set_t& data() { return m_data; }
    /// Underlying data structure accessor.
    /// @return Const reference to underlying data structure.
    const set_t& data() const { return m_data; }
    /// C++ specific
    /// @param list Range to insert into container.
    void _add_range(std::initializer_list<T> list)
    {
        std::for_each(list.begin(), list.end(), [this](const T &v) { m_data.insert(v); });
    }

    /// Keeping get_Count() from hiding.
    using BaseType::get_Count;
        
    /// Copies hash contents into existing array elements.
    /// @param arr Destination array.
    /// @param index Destination array beginning index.
    void CopyTo(ArrayPtr<T> arr, int index) override
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

    /// @copydoc System::Collections::Generic::IEnumerable<T>::virtualizeBeginIterator
    System::Details::VirtualizedIteratorBase<T>* virtualizeBeginIterator() override
    {
        return new System::Details::NativeIteratorWrapper<T, iterator>(m_data.begin(), m_data.end());
    }
    /// @copydoc System::Collections::Generic::IEnumerable<T>::virtualizeEndIterator
    System::Details::VirtualizedIteratorBase<T>* virtualizeEndIterator() override
    {
        return new System::Details::NativeIteratorWrapper<T, iterator>(m_data.end(), m_data.end());
    }
    /// @copydoc System::Collections::Generic::IEnumerable<T>::virtualizeBeginConstIterator
    System::Details::VirtualizedIteratorBase<T>* virtualizeBeginConstIterator() const override
    {
        return new System::Details::NativeConstIteratorWrapper<T, const_iterator>(m_data.begin(), m_data.end());
    }
    /// @copydoc System::Collections::Generic::IEnumerable<T>::virtualizeEndConstIterator
    System::Details::VirtualizedIteratorBase<T>* virtualizeEndConstIterator() const override
    {
        return new System::Details::NativeConstIteratorWrapper<T, const_iterator>(m_data.end(), m_data.end());
    }

#ifdef __DBG_FOR_EACH_MEMBER
public:
    /// Makes container and elements accept visitor.
    /// @param visitor Visitor to accept.
    void DBG_for_each_member(DBG::for_each_member_visitor &visitor) const override
    {
        visitor.add_self(this);
        DBG::for_each_of_Object(this, m_data, visitor);
    }
    /// Returns class name.
    /// @return String literal pointer.
    const char* DBG_class_name() const override { return "HashSet<T>"; }
#endif

protected:
    /// Destructor.
    ~HashSet() override {}
#ifdef ASPOSE_GET_SHARED_MEMBERS
    /// Implements loop reference detection mechanism for container.
    DEFINE_GET_SHARED_MEMBERS(m_data);
#endif
};

} // namespace Generic
} // namespace Collections
} // namespace System

#endif // _aspose_system_collections_hashset_h_
