/// @file xml/schema/xml_schema_sequence.h

#pragma once

#include <xml/schema/xml_schema_group_base.h>
#include <system/shared_ptr.h>


/// @cond
namespace System
{
namespace Xml
{
namespace Schema
{
class XmlSchemaObjectCollection;
} // namespace Schema
} // namespace Xml
} // namespace System
/// @endcond

namespace System {

namespace Xml {

namespace Schema {

/// Represents the @c sequence element (compositor) from the XML Schema as specified by the World Wide Web Consortium (W3C).
/// The @c sequence requires the elements in the group to appear in the specified sequence within the containing element.
/// @attention Objects of this class should only be allocated using System::MakeObject() function.
/// Never create instances of this type on stack or using operator new, as it will result in runtime errors and/or assertion faults.
/// Always wrap this class into System::SmartPtr pointer and use this pointer to pass it to functions as argument.
class ASPOSECPP_SHARED_CLASS XmlSchemaSequence : public XmlSchemaGroupBase
{
    typedef XmlSchemaSequence ThisType;
    typedef XmlSchemaGroupBase BaseType;

    typedef ::System::BaseTypesInfo<BaseType> ThisTypeBaseTypesInfo;
    ASPOSECPP_SHARED_RTTI_INFO_DECL();

public:

    /// An alias for shared pointer to an instance of this class.
    using Ptr = SharedPtr<XmlSchemaSequence>;

public:

    /// The elements contained within the compositor.
    /// Collection of XmlSchemaElement, XmlSchemaGroupRef, XmlSchemaChoice, XmlSchemaSequence, or XmlSchemaAny.
    /// @returns The elements contained within the compositor.
    ASPOSECPP_SHARED_API SharedPtr<XmlSchemaObjectCollection> get_Items() override;

    /// Initializes a new instance of the XmlSchemaSequence class.
    ASPOSECPP_SHARED_API XmlSchemaSequence();

protected:

    /// @cond
    ASPOSECPP_SHARED_API bool get_IsEmpty() override;

    ASPOSECPP_SHARED_API void SetItems(SharedPtr<XmlSchemaObjectCollection> newItems) override;

    #ifdef ASPOSE_GET_SHARED_MEMBERS
    ASPOSECPP_SHARED_API System::Object::shared_members_type GetSharedMembers() const override;
    #endif
    /// @endcond

private:

    SharedPtr<XmlSchemaObjectCollection> _items;

    ThisType* CppMemberwiseClone() const override { return new ThisType(*this); } 

};

} // namespace Schema
} // namespace Xml
} // namespace System


