// This work is licensed under a Creative Commons Attribution 3.0 Unported License.
// http://creativecommons.org/licenses/by/3.0/deed.en_US

#include "Precompiled.h"

Member::Member( std::string string, unsigned val, MetaData *meta ) : name( string ), offset( val ), data( meta ), next( NULL )
{
}

Member::~Member( )
{
}

const std::string& Member::Name( void ) const
{
  return name;
}

unsigned Member::Offset( void ) const
{
  return offset;
}

const MetaData *Member::Meta( void ) const
{
  return data;
}

Member *& Member::Next( void )
{
  return next;
}

Member *const& Member::Next( void ) const
{
  return next;
}

MetaData::MetaData( std::string string, unsigned val ) : name( string ), size( val ), members( NULL ), lastMember( NULL )
{
}

MetaData::~MetaData( )
{
}

void MetaData::Init( std::string string, unsigned val )
{
  name = string;
  size = val;
}

const std::string& MetaData::Name( void ) const
{
  return name;
}

unsigned MetaData::Size( void ) const
{
  return size;
}

void MetaData::AddMember( const Member *member )
{
  if(!members)
    members = const_cast<Member *>(member);
  else
    lastMember->Next( ) = const_cast<Member *>(member);

  lastMember = const_cast<Member *>(member);
}

bool MetaData::HasMembers( void ) const
{
  return (members) ? true : false;
}

void MetaData::Copy( void *dest, const void *src ) const
{
  memcpy( dest, src, size );
}

void MetaData::Delete( void *data ) const
{
  delete[] reinterpret_cast<char *>(data);
  data = NULL;
}

void *MetaData::NewCopy( const void *src ) const
{
  void *data = new char[size];
  memcpy( data, src, size );
  return data;
}

void *MetaData::New( void ) const
{
  return new char[size];
}

const Member *MetaData::Members( void ) const
{
  return members;
}

void MetaData::PrintMembers( std::ostream& os ) const
{
  const Member *mem = members;

  os << "Members for Meta: " << name << std::endl;

  while(mem)
  {
    os << "  " << mem->Meta( )->Name( ) << " " << mem->Name( ) << std::endl;
    mem = mem->Next( );
  }
}

void MetaData::SetSerialize( SerializeFn fn )
{
  serialize = fn;
}

void MetaData::Serialize( std::ostream& os, RefVariant var ) const
{
  if(serialize)
    serialize( os, var );
  else
    TextSerialize( os, var );
}
