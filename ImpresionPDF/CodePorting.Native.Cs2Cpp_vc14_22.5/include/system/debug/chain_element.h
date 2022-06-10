/// @file system/debug/chain_element.h
#pragma once

#include <functional>
#include <typeinfo>
#include <memory>
#include <vector>
#include <system/smart_ptr.h>
#include <defines.h>

#if defined(ENABLE_CYCLES_DETECTION_EXT)

/// @cond
namespace System { namespace Details {

struct HeldVariables;
struct SharedMembersType;

}}

namespace System { namespace Debug {

class ChainElement
{
    enum class Mode
    {
        SmartPtr,
        Object,
        ClassCallback,
        DelegateCallback
    };

public:
    using ClassCallback = std::function<void(Details::SharedMembersType&)>;
    using DelegateCallback = std::function<std::shared_ptr<Details::HeldVariables>()>;

    ASPOSECPP_SHARED_API ChainElement(const char* field_name, const SmartPtrInfo& info);

    ASPOSECPP_SHARED_API ChainElement(const char* field_name, const Object* object);

    ASPOSECPP_SHARED_API ChainElement(const char* field_name, const std::type_info& member_info, const void* member_ptr,
                                      ClassCallback callback);

    ASPOSECPP_SHARED_API ChainElement(const char* field_name, const std::type_info& member_info, const void* member_ptr,
                                      DelegateCallback callback);

    std::vector<ChainElement> GetHolders() const;

    bool operator < (const ChainElement& other) const;

    const char* GetObjectName() const;
    const char* GetFieldName() const;

    const SmartPtrInfo& GetInfo() const;

private:
    Mode m_mode;

    const char* m_object_name;
    const char* m_field_name;
    const void* m_ptr;

    SmartPtrInfo m_info;

    ClassCallback m_class_callback;
    DelegateCallback m_delegate_callback;
};

}}
/// @endcond

#endif
