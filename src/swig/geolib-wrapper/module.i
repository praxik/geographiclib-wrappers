%module
#ifdef SWIGRUBY
geolibwrapper_ruby
#else
geolibwrapper
#endif
%{
    #include <geolib-wrapper/Geodesic.h>
%}

%include <exception_handler.i>

%import <std/module.i>

%import <geolib-wrapper/GeoLibWrapperConfig.h>

#ifdef SWIGCSHARP
%typemap( csimports ) SWIGTYPE
%{
    using System;
    using System.Runtime.InteropServices;

    using std;
%}
%pragma( csharp ) moduleimports=
%{
    using System;
    using System.Runtime.InteropServices;

    using std;
%}
#endif

%apply double& INOUT { double& };
%include <geolib-wrapper/Geodesic.h>
