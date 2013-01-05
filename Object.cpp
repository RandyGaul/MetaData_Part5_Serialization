// This work is licensed under a Creative Commons Attribution 3.0 Unported License.
// http://creativecommons.org/licenses/by/3.0/deed.en_US

#include "Precompiled.h"
#include "Object.h"

DEFINE_META( Object )
{
  ADD_MEMBER( ID );
  ADD_MEMBER( active );
  ADD_MEMBER( x );
}

Object::Object( int id ) : ID( id ), active( true ), x( 13.37 )
{
}

Object::~Object( )
{
}
