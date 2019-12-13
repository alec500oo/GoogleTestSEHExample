# GoogleTestSEH

This project was created to explore a sudden change in googlemock functionality. Since Visual Studio 2019 update 16.4,
googlemock has failed to work correctly when tests are run. This change was not noticed until the update occurred. All
other googletest entities work as expected. The result of this update is a SEH exception with the code 0xc0000005. This
code corresponds to a memory access violation. This exception type is caused by a program attempting to access memory
that it does not have permission to, or memory that has been cleared prior to attempted access.

## Intricate details

In this case the memory has been cleared the googlemock framework attempts to access it. The
exception gets thrown within the `TypedExpectation<F>* FindMatchingExpectationLocked(const ArgumentTuple& args)`
function in `gmock-spec-builders.h`. A vector `get()` operation is triggering the exception. Since the exception is
occurring within a C++ standard library class the bug has most likely been introduced within an update to the C++ build
tools distributed by Microsoft. This memory access bug may show itself in other ways within C++ standard library code. The
build tools for C++11 and C++14 still seem to build googlemock correctly; while the build tools for C++17 cause the
exception.

The GitHub [Issue #2628](https://github.com/google/googletest/issues/2628) has been created to notify the developers of
googletest of the issue. Googletest developers may attempt to fix the issue. However, a permanent solution will
likely immerge in a patched version of Visual Studio in a few weeks.

The only indication of that a change was made to the standard library in this release of Visual Studio it a single
bullet point in the [changelog](https://docs.microsoft.com/en-us/visualstudio/releases/2019/release-notes#cpp-164GA).
The bullet point indicates that implementation of the C++17 standard is complete.

```plaintext
C++17: Implemented to_chars() general precision, completing P0067R5 Elementary String Conversions (charconv). This
completes implementation of all library features in the C++17 Standard.
```

Obviously, a new bug has been introduced in the standard library.  For now, my recommendation for solving this issue in
HoodTechnology projects is to downgrade the C++ version to C++14. This should allow the use of most new language feature
with the added benefit of stability.
