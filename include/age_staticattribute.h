#ifndef AVIEWPORTMATRIX_H
#define AVIEWPORTMATRIX_H

#include <QGLShaderProgram>
#include <../include/age_eventmgr.h>
#include <../include/age_vector2d.h>
#include <../include/age_vector3d.h>
#include <../include/age_matrix4x4.h>
namespace AGE2D
{
class AScene;
class AKeyBoardEvent;
class AMouseInfo;
class AVector2D;
class AVector3D;
struct VertexData
{
    AVector3D postion;
    AVector2D texture;
};

AMatrix4x4 getViewPortMatrix();
void setViewPortMatrix(AMatrix4x4);

QGLShaderProgram * getDefalutShaderProgram();
void initDefalutShaderProgram();

AScene * getCurrentScene();
void setCurrentScene(AScene * fuckyourasshole);

QKeyEvent * getCurrentKeyEvent();
QMouseEvent* getCurrentMouseEvent();
void setCurrentKeyEvent(QKeyEvent * keyboardEvent);
void setCurrentMouseEvent(QMouseEvent * mouseEvent);
void setTimeStep(int time);
int getTimeStep();

AWidget * getCurrentWidget();
void setCurrentWidget(AWidget *);
}

#endif // AVIEWPORTMATRIX_H
