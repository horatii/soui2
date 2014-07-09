/***********************************************************************
    filename:     SSingleton.h
    created:    25/8/2012

    purpose:    Singleton Base Class
*************************************************************************/

#pragma once

#include <assert.h>

namespace SOUI
{

template <typename T> 
class SOUI_EXP SSingleton
{
protected:
    static    T* ms_Singleton;

public:
    SSingleton( void )
    {
        assert( !ms_Singleton );
        ms_Singleton = static_cast<T*>(this);
    }
    virtual ~SSingleton( void )
    {
        assert( ms_Singleton );
        ms_Singleton = 0;
    }
    static T& getSingleton( void )
    {
        assert( ms_Singleton );
        return ( *ms_Singleton );
    }
    static T* getSingletonPtr( void )
    {
        return ( ms_Singleton );
    }

private:
    SSingleton& operator=(const SSingleton&)
    {
        return *this;
    }
    SSingleton(const SSingleton&) {}
};

}//namespace SOUI