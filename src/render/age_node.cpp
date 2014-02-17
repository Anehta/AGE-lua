#include <../include/age_matrix4x4.h>
#include <../include/age_node.h>

namespace AGE2D
{
ANode::~ANode()
{

}

ANode::ANode()
{
    m_x = 0;
    m_y = 0;
}

void ANode::setX(float x)
{
    m_x = x;
}

void ANode::setY(float y)
{
	m_y = y;
}

void ANode::setPos(AVector2D pos)
{
	m_x=pos.x ();
	m_y=pos.y ();
}

void ANode::setScale(float value)
{
    m_scale = value;
}

float ANode::getX()
{
    return m_x;
}

float ANode::getY()
{
	return m_y;
}

AVector2D ANode::pos()
{
	AVector2D a;
	a.setX (getX());
	a.setY (getY());
	return a;
}

float ANode::getScale()
{
    return m_scale;
}

AMatrix4x4 ANode::getMatrix()
{
    AMatrix4x4 temp;
    temp.translate(m_x,m_y,0);
    //m_matrix.scale(m_scale);
    return temp;
}

}
