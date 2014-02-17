#include <../include/age_matrix4x4.h>
#include <../include/age_vector4d.h>

namespace AGE2D
{
AMatrix4x4::AMatrix4x4()
{
}

AMatrix4x4::AMatrix4x4(QMatrix4x4 matrix)
{
    AVector4D first(matrix.column(0)),
		second(matrix.column(1)),
		third(matrix.column(2)),
		forth(matrix.column(3));

    setColumn(0,first);
    setColumn(1,second);
    setColumn(2,third);
    setColumn(3,forth);
}

AMatrix4x4::AMatrix4x4(float m11,float m12,float m13,float m14,
			       float m21,float m22,float m23,float m24,
			       float m31,float m32,float m33,float m34,
			       float m41,float m42,float m43,float m44)
{
    AVector4D first(m11,m12,m13,m14),
		second(m21,m22,m23,m24),
		thrid(m31,m32,m33,m34),
		forth(m41,m42,m43,m44);

    setColumn(0,first);
    setColumn(1,second);
    setColumn(2,thrid);
    setColumn(3,forth);
}

}
