#include <../include/age_sprite.h>
#include <../include/age_staticattribute.h>
#include <memory>
#include <QGLShader>

using namespace std;

namespace AGE2D
{
ASprite::~ASprite()
{
    //delete &m_geometric; //3
}

ASprite::ASprite()
{
	this->m_type=SPRITE_ENTITY;
	this->m_parent=NULL;
    initializeAll();
}

ASprite::ASprite(ATexture * bigDick)
{
	this->m_type=SPRITE_ENTITY;
	this->m_parent=NULL;
    bindTexture(bigDick);
    initializeAll();
}

void ASprite::release()
{
    glDeleteBuffers(2,m_geometric.getVboId()); //1
    delete m_geometric.getVboId(); //2
}

void ASprite::action()
{

}

void ASprite::setShowRect(float lx, float ly, float rx, float ry)
{
    m_geometric.setShowRect(lx,ly,rx,ry);
}

void ASprite::setShowDet(int col, int row, int gridWidth, int gridHeigth)
{
    m_geometric.setShowRect(gridWidth*row,gridHeigth*col,
			    gridWidth*row+gridWidth,gridHeigth*col+gridHeigth);
}

void ASprite::deleteThis()
{

}

void ASprite::render()
{
    m_program->bind();
    shaderAction();
    glDepthMask(GL_FALSE);

    computeMatrix();
    computePolygon();
    GLuint * vboId = m_geometric.getVboId();

    glBindBuffer(GL_ARRAY_BUFFER,vboId[0]);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,vboId[1]);
    quintptr offset = 0;
    glBindTexture(GL_TEXTURE_2D, m_texId);

    // Tell OpenGL programmable pipeline how to locate vertex position data
    int vertexLocation = m_program->attributeLocation("a_position");
    m_program->enableAttributeArray(vertexLocation);
    glVertexAttribPointer(vertexLocation,3, GL_FLOAT, GL_FALSE, sizeof(VertexData), (const void *)offset);

    offset += sizeof(AVector3D);

    // Tell OpenGL programmable pipeline how to locate vertex texture coordinate data
    int texcoordLocation = m_program->attributeLocation("a_texcoord");
    m_program->enableAttributeArray(texcoordLocation);
    glVertexAttribPointer(texcoordLocation, 2, GL_FLOAT, GL_FALSE, sizeof(VertexData), (const void *)offset);

    m_program->setUniformValue("source",0);
    m_program->setUniformValue("age_Opacity",m_alpha);
    m_program->setUniformValue("red",m_color.red);
    m_program->setUniformValue("green",m_color.green);
    m_program->setUniformValue("blue",m_color.blue);

    glDrawElements(GL_TRIANGLE_FAN, 4, GL_UNSIGNED_SHORT, 0);

    glDepthMask(GL_TRUE);

    glBindBuffer(GL_ARRAY_BUFFER,0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
}

void ASprite::computeMatrix()
{
    //m_program->bind();
    AMatrix4x4 viewMatrix = getViewPortMatrix() * getMatrix();

    AMatrix4x4 lbmatrix = viewMatrix;

    lbmatrix.translate(mx_offset,my_offset,0);
    lbmatrix.rotate(m_angle,0,0,1);
    lbmatrix.translate(-mx_offset,-my_offset,0);
    m_program->setUniformValue("mvp_matrix", lbmatrix);//set shader

    if(isNeedRealTime)
    {
	AMatrix4x4 ltmatrix = viewMatrix;
	AMatrix4x4 rbmatrix = viewMatrix;
	AMatrix4x4 rtmatrix = viewMatrix;

	//ltmatrix.translate(0,m_geometric.height(),0);
	//rbmatrix.translate(m_geometric.width(),0,0);
	//rtmatrix.translate(m_geometric.width(),m_geometric.height(),0);
	//ltmatrix.translate(0,-m_geometric.height(),0);

	ltmatrix.translate(mx_offset,my_offset,0);
	ltmatrix.rotate(m_angle,0,0,1);
	ltmatrix.translate(-mx_offset,-my_offset,0);
	ltmatrix.translate(0,m_geometric.height(),0);

	rbmatrix.translate(mx_offset,my_offset,0);
	rbmatrix.rotate(m_angle,0,0,1);
	rbmatrix.translate(-mx_offset,-my_offset,0);
	rbmatrix.translate(m_geometric.width(),0,0);

	rtmatrix.translate(mx_offset,my_offset,0);
	rtmatrix.rotate(m_angle,0,0,1);
	rtmatrix.translate(-mx_offset,-my_offset,0);
	rtmatrix.translate(m_geometric.width(),m_geometric.height(),0);

	AMatrix4x4 currentMatrix = getViewPortMatrix().inverted();
	AMatrix4x4 leftBottonMatrix =  currentMatrix * lbmatrix;
	AMatrix4x4 leftTopMatrix = currentMatrix * ltmatrix;
	AMatrix4x4 rightBottonMatrix = currentMatrix * rbmatrix;
	AMatrix4x4 rightTopMatrix = currentMatrix * rtmatrix;

	float lbx = leftBottonMatrix.row(0).w();
	float lby = leftBottonMatrix.row(1).w();

	m_leftBottonX = lbx;
	m_leftBottonY = lby;

	float ltx = leftTopMatrix.row(0).w();
	float lty = leftTopMatrix.row(1).w();

	m_leftTopX = ltx;
	m_leftTopY = lty;

	float rbx = rightBottonMatrix.row(0).w();
	float rby = rightBottonMatrix.row(1).w();

	m_rightBottonX = rbx;
	m_rightBottonY = rby;

	float rtx = rightTopMatrix.row(0).w();
	float rty = rightTopMatrix.row(1).w();

	m_rightTopX = rtx;
	m_rightTopY = rty;
    }

}

void ASprite::computePolygon()
{
    APolygon polygon_tmp;
    polygon_tmp.addPoint(this->leftTop());
    polygon_tmp.addPoint(this->rightTop());
    polygon_tmp.addPoint(this->rightBotton());
    polygon_tmp.addPoint(this->leftBotton());
    this->polygon=polygon_tmp;
}

void ASprite::bindDefalutProgram()
{
    m_program = getDefalutShaderProgram();
}

void ASprite::bindTexture(ATexture *fuckyou)
{
    initializeGLFunctions();
    m_texId = fuckyou->getTextureId();
    bindDefalutProgram();
    m_geometric.initParameter(fuckyou->width(),fuckyou->height(),
			      fuckyou->width(),fuckyou->height(),
			      0,0,
			      fuckyou->width(),fuckyou->height());
    initializeAll();
}

void ASprite::bindTexture(int textureId,int width,int height)
{
    initializeGLFunctions();
    m_texId = textureId;
    bindDefalutProgram();
    m_geometric.initParameter(width,height,
                  width,height,
                  0,0,
                  width,height);
    initializeAll();
}

int ASprite::getTextureId()
{
    return m_texId;
}

float ASprite::width()
{
    return m_geometric.width();
}

float ASprite::height()
{
	return m_geometric.height();
}

AVector2D ASprite::size()
{
	AVector2D size;
	size.setX (width());
	size.setY (height());
	return size;
}

void ASprite::setWidth(float width)
{
    m_geometric.setWidth(width);
}

void ASprite::setHeight(float height)
{
	m_geometric.setHeight(height);
}

ALayer *ASprite::parent()
{
	return m_parent;
}

void ASprite::setName(string new_name)
{
	if(m_parent && m_parent->parent ())
	{
		AScene *scene=m_parent->parent ();
		scene->updateBaseEntity (this->name (),new_name);
	}
	this->identity_name=new_name;
}

void ASprite::setPivotOffset(float x_offset, float y_offset)
{
    mx_offset = x_offset;
    my_offset = y_offset;
}

void ASprite::rotate(float angle)
{
    m_angle = angle;
}

void ASprite::initializeAll()
{
    setPivotOffset(0,0);
    rotate(0);
    //setX(0);
    //setY(0);
    setScale(0);
    m_color.setColor(1.0,1.0,1.0);
    m_alpha = 1.0;
    this->is_touchable=false;
}

void ASprite::OnTouchedPress(AVector2D pos)
{
    qDebug()<<"touch!!";
}

void ASprite::OnTouchedrelease(AVector2D pos)
{

}


float ASprite::leftTopX()
{
    isNeedRealTime = true;
    return m_leftTopX;
}

float ASprite::rightTopX()
{
    isNeedRealTime = true;
    return m_rightTopX;
}

float ASprite::leftBottonX()
{
    isNeedRealTime = true;
    return m_leftBottonX;
}

float ASprite::rightBottonX()
{
    isNeedRealTime = true;
    return m_rightBottonX;
}

float ASprite::leftTopY()
{
    isNeedRealTime = true;
    return m_leftTopY;
}

AVector2D ASprite::leftTop()
{
	AVector2D a;
	a.setX (leftTopX());
	a.setY (leftTopY());
	return a;
}

float ASprite::rightTopY()
{
    isNeedRealTime = true;
    return m_rightTopY;
}

AVector2D ASprite::rightTop()
{
	AVector2D a;
	a.setX (rightTopX());
	a.setY (rightTopY());
	return a;
}

float ASprite::leftBottonY()
{
    isNeedRealTime = true;
    return m_leftBottonY;
}

AVector2D ASprite::leftBotton()
{
	AVector2D a;
	a.setX (leftBottonX());
	a.setY (leftBottonY());
	return a;
}

float ASprite::rightBottonY()
{
    isNeedRealTime = true;
    return m_rightBottonY;
}

AVector2D ASprite::rightBotton()
{
	AVector2D a;
	a.setX (rightBottonX());
	a.setY (rightBottonY());
	return a;
}

void ASprite::destroy()
{
    isDeath = true;
}

float ASprite::middleX()
{
    return getX()+width()/2;
}

float ASprite::middleY()
{
	return getY()+height()/2;
}

AVector2D ASprite::middle()
{
	AVector2D a;
    a.setX (this->middleX());
    a.setY (this->middleY());
	return a;
}

void ASprite::loadShaderProgram(QGLShaderProgram * program)
{
    m_program = program;
}

QGLShaderProgram * ASprite::getShaderProgram()
{
    return m_program;
}

void ASprite::shaderAction()
{

}

void ASprite::setColor(float r, float g, float b)
{
    m_color.red = r;
    m_color.green = g;
    m_color.blue = b;
}

void ASprite::setColor(long int rgb)
{
    m_color.red = AGE_GetRValue(rgb);
    m_color.green = AGE_GetGValue(rgb);
    m_color.blue = AGE_GetBValue(rgb);
}

APolygon ASprite::getPolygon()
{
    return this->polygon;
}

void ASprite::setIsTouchable(bool is_touchable)
{
    this->is_touchable=is_touchable;
}

bool ASprite::isTouchable()
{
    return this->is_touchable;
}

AColor ASprite::getColor()
{
    AColor color(m_color.red,m_color.green,m_color.blue);
    return color;
}

void ASprite::setAlpha(float alpha)
{
    this->m_alpha=alpha;
}

float ASprite::getAlpha()
{
        return m_alpha;
}
}

