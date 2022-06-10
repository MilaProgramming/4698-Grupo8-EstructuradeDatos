/// @file xml/schema/xml_schema_import.h

#pragma once

#include <xml/schema/xml_schema_external.h>
#include <system/string.h>


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

/// Represents the @c import element from XML Schema as specified by the World Wide Web Consortium (W3C).
/// This class is used to import schema components from other schemas.
/// @attention Objects of this class should only be allocated using System::MakeObject() function.
/// Never create instances of this type on stack or using operator new, as it will result in runtime errors and/or assertion faults.
/// Always wrap this class into System::SmartPtr pointer and use this pointer to pass it to functions as argument.
class ASPOSECPP_SHARED_CLASS XmlSchemaImport : public XmlSchemaExternal
{
    typedef XmlSchemaImport ThisType;
    typedef XmlSchemaExternal BaseType;

    typedef ::System::BaseTypesInfo<BaseType> ThisTypeBaseTypesInfo;
    ASPOSECPP_SHARED_RTTI_INFO_DECL();

public:

    /// An alias for shared pointer to an instance of this class.
    using Ptr = SharedPtr<XmlSchemaImport>;

public:

    /// Returns the target namespace for the imported schema as a Uniform Resource Identifier (URI) reference.
    /// @returns The target namespace for the imported schema as a URI reference. Optional.
    ASPOSECPP_SHARED_API String get_Namespace();
    /// Sets the target namespace for the imported schema as a Uniform Resource Identifier (URI) reference.
    /// @param value The value to set.
    ASPOSECPP_SHARED_API void set_Namespace(const String& value);
    /// Returns the @c annotation value.
    /// @returns The annotation.
    ASPOSECPP_SHARED_API SharedPtr<XmlSchemaAnnotation> get_Annotation();
    /// Sets the @c annotation value.
    /// @param value The value to set.
    ASPOSECPP_SHARED_API void set_Annotation(const SharedPtr<XmlSchemaAnnotation>& value);

    /// Initializes a new instance of the XmlSchemaImport class.
    ASPOSECPP_SHARED_API XmlSchemaImport();

protected:

    /// @cond
    ASPOSECPP_SHARED_API void AddAnnotation(SharedPtr<XmlSchemaAnnotation> annotation) override;

    #ifdef ASPOSE_GET_SHARED_MEMBERS
    ASPOSECPP_SHARED_API System::Object::shared_members_type GetSharedMembers() const override;
    #endif
    /// @endcond

private:

    String _ns;
    SharedPtr<XmlSchemaAnnotation> _annotation;

    ThisType* CppMemberwiseClone() const override { return new ThisType(*this); } 

};

} // namespace Schema
} // namespace Xml
} // namespace System


