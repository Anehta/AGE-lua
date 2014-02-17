#ifndef ABASEENTITY_H
#define ABASEENTITY_H
#include <string>
namespace AGE2D {


class ABaseEntity
{
public:
	ABaseEntity();
	virtual int type();
	virtual std::string name();
	virtual void setName(std::string new_name);
protected:
	int m_type;
	std::string identity_name;
};
enum ABaseEntityType
{
	LAYER_ENTITY,
	SPRITE_ENTITY,
	SPRITE_ACTOR_ENTITY
};
}


#endif // ABASEENTITY_H
