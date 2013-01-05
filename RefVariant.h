// This work is licensed under a Creative Commons Attribution 3.0 Unported License.
// http://creativecommons.org/licenses/by/3.0/deed.en_US

#pragma once

#include "VariantBase.h"

class MetaData;

class RefVariant : public VariantBase
{
public:
  template <typename T>
  RefVariant( const T& value );
  RefVariant( const RefVariant& rhs );
  RefVariant( const Variant& rhs );
  RefVariant( const MetaData *m, void *d );
  RefVariant( );

  RefVariant& operator=( const RefVariant& rhs );
  RefVariant& operator=( const Variant& rhs );
  template <typename T>
  RefVariant& operator=( const T& rhs );
};

template <typename T>
RefVariant::RefVariant( const T& value ) : VariantBase( META_TYPE( T ), const_cast<T *>(&value) )
{
}

template <typename T>
RefVariant& RefVariant::operator=( const T& rhs )
{
  meta = META_TYPE( T );
  data = const_cast<T *>(&rhs);
  return *this;
}
