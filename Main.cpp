// This work is licensed under a Creative Commons Attribution 3.0 Unported License.
// http://creativecommons.org/licenses/by/3.0/deed.en_US

#include "Precompiled.h"
#include "Object.h"

DEFINE_META_POD( int );
DEFINE_META_POD( int * );
DEFINE_META_POD( char );
DEFINE_META_POD( char * );
DEFINE_META_POD( float );
DEFINE_META_POD( bool );
DEFINE_META_POD( double );
DEFINE_META_POD( std::string );

void main( void )
{
  int x = 5;
  
  RefVariant refv;

  refv = x;

  const char *c = "String";
  
  Variant v = c;

  refv = v;

  v.Serialize( std::cout );

  Object ob( 14 );

  RefVariant object = ob;

  object.Serialize( std::cout );

  getchar( );
}
