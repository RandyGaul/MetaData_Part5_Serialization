// This work is licensed under a Creative Commons Attribution 3.0 Unported License.
// http://creativecommons.org/licenses/by/3.0/deed.en_US

#include "VariantBase.h"

#pragma once

class Variant : public VariantBase
{
public:
  template <typename T>
  Variant( const T& value );
  Variant( const MetaData *m, void *d );
  Variant( );

  Variant& operator=( const Variant& rhs );
  template <typename T>
  Variant& operator=( const T& rhs );
};

template <typename T>
Variant::Variant( const T& value ) : VariantBase( META_TYPE( T ) , NULL )
{
  data = meta->NewCopy( &value );
}

template <typename T>
Variant& Variant::operator=( const T& rhs )
{
  // We require a new copy if meta does not match!
  if(meta != META_TYPE( T ))
  {
    assert( META_TYPE( T ) ); // Cannot create instance of NULL meta!

    meta->Delete( data );
    meta = META_TYPE( T );
    data = meta->NewCopy( &rhs );
  }
  else
  {
    meta->Copy( data, &rhs );
  }
  return *this;
}
