#include "../include/age_baseentity.h"
namespace AGE2D
{
ABaseEntity::ABaseEntity()
{
}


int ABaseEntity::type()
{
	return m_type;
}

std::string ABaseEntity::name()
{
	return identity_name;
}

void ABaseEntity::setName(std::string new_name)
{
	identity_name=new_name;
}
}

