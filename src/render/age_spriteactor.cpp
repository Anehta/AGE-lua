#include <../include/age_spriteactor.h>

#include <QDomDocument>
#include <qfile.h>
#include <qdebug.h>
#include <stdlib.h>
namespace AGE2D
{
ASpriteActor::ASpriteActor()
{
	this->m_type=SPRITE_ACTOR_ENTITY;
    initializeAll();
    this->m_parent=NULL;
}

ASpriteActor::ASpriteActor(ATexture * bigDick)
{
	this->m_type=SPRITE_ACTOR_ENTITY;
	this->m_parent=NULL;
    bindTexture(bigDick);
    initializeAll();
}

ASpriteActor::~ASpriteActor()
{
	initializeGLFunctions();
    glDeleteBuffers(2,m_geometric.getVboId()); //1
    delete m_geometric.getVboId(); //2
}

void ASpriteActor::addAnimation(AAnimation)
{

}

void ASpriteActor::animate(QString actionName, int frames, bool isCycle)
{

	AAnimation* animation=m_animation_set->findAnimation (actionName);
	if(isCycle)
	{
		frames=frames%(animation->totalFrames ());
	}
	AFrame frame=animation->getFrame (frames);
	this->setShowRect (frame.bottomLeft ().x (),frame.bottomLeft ().y (),
			   frame.topRight ().x (),frame.topRight ().y ()
			   );
}

void ASpriteActor::loadAnimationsFromFile(QString fileName)
{

QFile file(fileName);
 QDomDocument doc("superdick");
file.open( QIODevice::ReadOnly );
doc.setContent (&file);
 file.close();
   QDomElement root = doc.documentElement();//获得根节点

   //遍历添加animation
   QDomElement child=root.firstChildElement ();
   while(!child.isNull ())
   {
	   AAnimation animation(child.attribute (QString("name")));
	   addAnimationFromFile (&animation,child);
	   m_animationlist.push_back (animation);
	   child=child.nextSiblingElement ();
   }
}

void ASpriteActor::bindAnimationSet(AAnimationSet *animation_set)
{
	this->m_animation_set=animation_set;
}

void ASpriteActor::addAnimationFromFile(AAnimation *animation, QDomElement node)
{
	//加入帧
	QDomElement child =node.firstChildElement ();
	while(!child.isNull ())
	{

		QDomElement rect=child.firstChildElement ();
		//左下角
		double bl_x= rect.attribute (QString("x")).toDouble ();
		double bl_y= rect.attribute (QString("y")).toDouble ();
		AVector2D bl(bl_x,bl_y);
	//qDebug()<<" bottom left is"<<bl;

		rect=rect.nextSiblingElement ();
		//右上角
		double tr_x=rect.attribute (QString("x")).toDouble ();
		double tr_y=rect.attribute (QString("y")).toDouble ();
		AVector2D tr(tr_x,tr_y);
	//qDebug()<<" top right is"<<tr;
		//添加一帧
		animation->addFrame(AFrame(bl,tr));
		child=child.nextSiblingElement ();
	}
}

void ASpriteActor::action()
{

}

}
