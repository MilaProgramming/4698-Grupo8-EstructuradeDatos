/// @file system/details/porter.h
#pragma once


namespace CodePorting { namespace Native { namespace Cs2Cpp {

/// API to get information from porter.
class Porter
{
public:
    /// Checks whether code is ported or running in C#.
    /// @return Always returns true.
    static bool get_IsPorted()
    {
        return true;
    }
};

} } } // namespace CodePorting::Native::Cs2Cpp

