/// @file xml/schema/xml_schema_simple_content.h

#pragma once

#include <xml/schema/xml_schema_content_model.h>
#include <system/shared_ptr.h>


/// @cond
namespace System
{
namespace Xml
{
namespace Schema
{
class XmlSchemaContent;
} // namespace Schema
} // namespace Xml
} // namespace System
/// @endcond

namespace System {

namespace Xml {

namespace Schema {

/// Represents the @c simpleContent element from XML Schema as specified by the World Wide Web Consortium (W3C).
/// This class is for simple and complex types with simple content model.
/// @attention Objects of this class should only be allocated using System::MakeObject() function.
/// Never create instances of this type on stack or using operator new, as it will result in runtime errors and/or assertion faults.
/// Always wrap this class into System::SmartPtr pointer and use this pointer to pass it to functions as argument.
class ASPOSECPP_SHARED_CLASS XmlSchemaSimpleContent : public XmlSchemaContentModel
{
    typedef XmlSchemaSimpleContent ThisType;
    typedef XmlSchemaContentModel BaseType;

    typedef ::System::BaseTypesInfo<BaseType> ThisTypeBaseTypesInfo;
    ASPOSECPP_SHARED_RTTI_INFO_DECL();

public:

    /// An alias for shared pointer to an instance of this class.
    using Ptr = SharedPtr<XmlSchemaSimpleContent>;

public:

    /// Returns one of the XmlSchemaSimpleContentRestriction or XmlSchemaSimpleContentExtension.
    /// @returns The content contained within the XmlSchemaSimpleContentRestriction or XmlSchemaSimpleContentExtension class.
    ASPOSECPP_SHARED_API SharedPtr<XmlSchemaContent> get_Content() override;
    /// Returns one of the XmlSchemaSimpleContentRestriction or XmlSchemaSimpleContentExtension.
    /// @param value The value to set.
    ASPOSECPP_SHARED_API void set_Content(SharedPtr<XmlSchemaContent> value) override;

protected:

    /// @cond
    #ifdef ASPOSE_GET_SHARED_MEMBERS
    ASPOSECPP_SHARED_API System::Object::shared_members_type GetSharedMembers() const override;
    #endif
    /// @endcond

private:

    SharedPtr<XmlSchemaContent> _content;

    ThisType* CppMemberwiseClone() const override { return new ThisType(*this); } 

};

} // namespace Schema
} // namespace Xml
} // namespace System


