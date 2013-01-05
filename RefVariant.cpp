// This work is licensed under a Creative Commons Attribution 3.0 Unported License.
// http://creativecommons.org/licenses/by/3.0/deed.en_US

#include "Precompiled.h"

RefVariant::RefVariant( void ) : VariantBase( NULL, NULL )
{
}

RefVariant::RefVariant( const MetaData *m, void *d ) : VariantBase( m, d )
{
}

RefVariant::RefVariant( const RefVariant& rhs ) : VariantBase( rhs.Meta( ), rhs.Data( ) )
{
}

RefVariant::RefVariant( const Variant& rhs ) : VariantBase( rhs.Meta( ), rhs.Data( ) )
{
}

RefVariant& RefVariant::operator=( const RefVariant& rhs )
{
  meta = rhs.meta;
  data = rhs.data;
  return *this;
}

RefVariant& RefVariant::operator=( const Variant& rhs )
{
  meta = rhs.Meta( );
  data = rhs.Data( );
  return *this;
}
