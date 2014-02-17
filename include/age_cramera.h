#ifndef ACRAMERA_H
#define ACRAMERA_H
namespace AGE2D {
class ACramera
{
public:
    ACramera();
    void lookAt();
    void translate();
    void rotate();
    //这个是用来全局控制用户视角的，主要是做愤怒的小鸟那种拉伸之类的东西
};
}


#endif // ACRAMERA_H
