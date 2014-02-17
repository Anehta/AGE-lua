#ifndef AVIEWPORTMATRIX_H
#define AVIEWPORTMATRIX_H

#include <QGLShaderProgram>
#include <../include/age_eventmgr.h>
#include <../include/age_vector2d.h>
#include <../include/age_vector3d.h>
#include <../include/age_matrix4x4.h>
namespace AGE2D
{
class AGE_Scene;
class AGE_KeyBoardEvent;
class AGE_MouseInfo;
class AGE_Vector2D;
class AGE_Vector3D;
struct VertexData
{
    AGE_Vector3D postion;
    AGE_Vector2D texture;
};

AGE_Matrix4x4 getViewPortMatrix();
void setViewPortMatrix(AGE_Matrix4x4);

QGLShaderProgram * getDefalutShaderProgram();
void initDefalutShaderProgram();

AGE_Scene * getCurrentScene();
void setCurrentScene(AGE_Scene * fuckyourasshole);

QKeyEvent * getCurrentKeyEvent();
QMouseEvent* getCurrentMouseEvent();
void setCurrentKeyEvent(QKeyEvent * keyboardEvent);
void setCurrentMouseEvent(QMouseEvent * mouseEvent);
void setTimeStep(int time);
int getTimeStep();

AGE_Widget * getCurrentWidget();
void setCurrentWidget(AGE_Widget *);
}

#endif // AVIEWPORTMATRIX_H
