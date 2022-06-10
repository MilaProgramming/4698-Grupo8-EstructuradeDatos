/// @file xml/schema/xml_schema_include.h

#pragma once

#include <xml/schema/xml_schema_external.h>
#include <system/shared_ptr.h>


/// @cond
namespace System
{
namespace Xml
{
namespace Schema
{
class XmlSchemaAnnotation;
} // namespace Schema
} // namespace Xml
} // namespace System
/// @endcond

namespace System {

namespace Xml {

namespace Schema {

/// Represents the @c include element from XML Schema as specified by the World Wide Web Consortium (W3C).
/// This class is used to include declarations and definitions from an external schema.
/// The included declarations and definitions are then available for processing in the containing schema.
/// @attention Objects of this class should only be allocated using System::MakeObject() function.
/// Never create instances of this type on stack or using operator new, as it will result in runtime errors and/or assertion faults.
/// Always wrap this class into System::SmartPtr pointer and use this pointer to pass it to functions as argument.
class ASPOSECPP_SHARED_CLASS XmlSchemaInclude : public XmlSchemaExternal
{
    typedef XmlSchemaInclude ThisType;
    typedef XmlSchemaExternal BaseType;

    typedef ::System::BaseTypesInfo<BaseType> ThisTypeBaseTypesInfo;
    ASPOSECPP_SHARED_RTTI_INFO_DECL();

public:

    /// An alias for shared pointer to an instance of this class.
    using Ptr = SharedPtr<XmlSchemaInclude>;

public:

    /// Returns the @c annotation value.
    /// @returns The annotation.
    ASPOSECPP_SHARED_API SharedPtr<XmlSchemaAnnotation> get_Annotation();
    /// Sets the @c annotation value.
    /// @param value The value to set.
    ASPOSECPP_SHARED_API void set_Annotation(const SharedPtr<XmlSchemaAnnotation>& value);

    /// Initializes a new instance of the XmlSchemaInclude class.
    ASPOSECPP_SHARED_API XmlSchemaInclude();

protected:

    /// @cond
    ASPOSECPP_SHARED_API void AddAnnotation(SharedPtr<XmlSchemaAnnotation> annotation) override;

    #ifdef ASPOSE_GET_SHARED_MEMBERS
    ASPOSECPP_SHARED_API System::Object::shared_members_type GetSharedMembers() const override;
    #endif
    /// @endcond

private:

    SharedPtr<XmlSchemaAnnotation> _annotation;

    ThisType* CppMemberwiseClone() const override { return new ThisType(*this); } 

};

} // namespace Schema
} // namespace Xml
} // namespace System


