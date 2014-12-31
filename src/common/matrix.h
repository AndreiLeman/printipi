#ifndef COMMON_MATRIX_H
#define COMMON_MATRIX_H

/* 
 * Printipi/common/matrix.h
 * (c) 2014 Colin Wallace
 *
 * This file exposes classes and templates used to construct 3x3 matrices.
 * Matrices are useful in applying linear transformations. Notably, they can be used to adjust coordinates to a different coordinate-space in order to account for an unlevel bed.
 */



class Matrix3x3 {
    float a00, a01, a02;
    float a10, a11, a12;
    float a20, a21, a22;
    public:
        Matrix3x3() : a00(0), a01(0), a02(0), a10(0), a11(0), a12(0), a20(0), a21(0), a22(0) {}
        Matrix3x3(float a00, float a01, float a02,
                float a10, float a11, float a12,
                float a20, float a21, float a22) :
            a00(a00), a01(a01), a02(a02),
            a10(a10), a11(a11), a12(a12),
            a20(a20), a21(a21), a22(a22) {}
        template <typename VecT> VecT transform(const VecT &xyz) const {
            return VecT(
                a00*xyz.x() + a01*xyz.y() + a02*xyz.z(),
                a10*xyz.x() + a11*xyz.y() + a12*xyz.z(),
                a20*xyz.x() + a21*xyz.y() + a22*xyz.z()
            );
    }

};

#endif
