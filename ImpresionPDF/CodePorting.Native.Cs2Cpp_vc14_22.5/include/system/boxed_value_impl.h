#pragma once

namespace System {

    template<class T>
    const System::TypeInfo& BoxedValue<T>::GetType() const
    {
            return System::ObjectExt::GetType<T>();
    }
}
