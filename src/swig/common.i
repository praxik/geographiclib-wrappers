%import <typemaps.i>
#ifdef SWIGWIN
%import <windows.i>
#define __in
#endif

#ifdef SWIGCSHARP
SWIG_CSBODY_PROXY( public, public, SWIGTYPE )
SWIG_CSBODY_TYPEWRAPPER( public, protected, public, SWIGTYPE )
#define SWIG_SHARED_PTR_TYPEMAPS( CONST, TYPE... ) \
    SWIG_SHARED_PTR_TYPEMAPS_IMPLEMENTATION( public, public, CONST, TYPE )

%import <enums.swg>
%csconst( 1 );
#endif //SWIGCSHARP

%import <operator_overload.i>
