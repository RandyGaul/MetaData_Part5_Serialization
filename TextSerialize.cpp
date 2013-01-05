// This work is licensed under a Creative Commons Attribution 3.0 Unported License.
// http://creativecommons.org/licenses/by/3.0/deed.en_US

#include "Precompiled.h"
#include "TextSerialize.h"

// Takes a pointer and returns a pointer offset in bytes
#define PTR_ADD( PTR, OFFSET ) \
  ((void *)(((char *)(PTR)) + (OFFSET)))

static unsigned level = 0;

void Padding( std::ostream& os )
{
  for(unsigned i = 0; i < level; ++i)
    os << "  ";
}

void TextSerialize( std::ostream& os, RefVariant var )
{
  const MetaData *meta = var.Meta( );
  void *data = var.Data( );
  
  assert( meta->HasMembers( ) ); // This type does not have a SerializePrim associated with it for some reason.

  os << meta->Name( ) << std::endl;

  const Member *mem = meta->Members( );
  Padding( os );
  os << "{" << std::endl;

  while(mem)
  {
    ++level;
    void *offsetData = PTR_ADD( var.Data( ), mem->Offset( ) );
    mem->Meta( )->Serialize( os, RefVariant( mem->Meta( ), offsetData ) );
    mem = mem->Next( );
    --level;
  }

  Padding( os );
  os << "}" << std::endl;
}
