%{
#ifdef POCO_FOUND
    #include <Poco/Exception.h>
#endif
%}

%include <exception.i>
%allowexception;
%exception
{
    try
    {
        $action
    }
#ifdef POCO_FOUND
    catch( Poco::Exception const& e )
    {
        SWIG_exception( SWIG_RuntimeError, e.displayText().c_str() );
    }
#endif
    catch( std::exception const& e )
    {
        SWIG_exception( SWIG_RuntimeError, e.what() );
    }
    catch(...)
    {
        SWIG_exception( SWIG_RuntimeError, "Unknown exception" );
    }
} 
