#define BOOST_TEST_MODULE Math
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include <OGDT/math.h>
#include <cfloat>
#include <cstdio>

using namespace OGDT;

bool vec3_eq (vec3 a, vec3 b, float eps, int ULPs)
{
    if (!R_eq (a.x, b.x, eps, ULPs)) return false;
    if (!R_eq (a.y, b.y, eps, ULPs)) return false;
    if (!R_eq (a.z, b.z, eps, ULPs)) return false;
    return true;
}

bool mat3_eq (const mat3& m1, const mat3& m2, float eps, int ULPs)
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (!R_eq (m1(i,j), m2(i,j), eps, ULPs)) return false;
        }
    }
    return true;
}

bool mat4_eq (const mat4& m1, const mat4& m2, float eps, int ULPs)
{
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            if (!R_eq (m1(i,j), m2(i,j), eps, ULPs)) return false;
        }
    }
    return true;
}

void print_mat (const mat4& m)
{
    for (int i = 0; i < 4; ++i)
    {
        printf ("%3.2f, %3.2f, %3.2f, %3.2f\n",
                m(i,0), m(i,1), m(i,2), m(i,3));
    }
    printf ("\n");
}

void print_mat (const mat3& m)
{
    for (int i = 0; i < 3; ++i)
    {
        printf ("%3.2f, %3.2f, %3.2f\n",
                m(i,0), m(i,1), m(i,2));
    }
    printf ("\n");
}

BOOST_AUTO_TEST_CASE (R_eq_0)
{
    BOOST_REQUIRE (R_eq (0.0f, 0.0f, 0, 0));
    BOOST_REQUIRE (R_eq (0.0f, -0.0f, 0, 0));
    BOOST_REQUIRE (R_eq (-0.0f, 0.0f, 0, 0));
    BOOST_REQUIRE (R_eq (-0.0f, -0.0f, 0, 0));
}

BOOST_AUTO_TEST_CASE (R_eq_test)
{
    BOOST_REQUIRE (R_eq (1.0f, 1.0f + FLT_EPSILON, 123, 1));
    BOOST_REQUIRE (!R_eq (1.0f, 1.0f + 2*FLT_EPSILON, 123, 1));
}

BOOST_AUTO_TEST_CASE (mat4_access)
{
    mat4 m = mat4
        ( 1,  2,  3,  4,
          5,  6,  7,  8,
          9, 10, 11, 12,
         13, 14, 15, 16);

    print_mat (m);
    
    BOOST_REQUIRE(m(0,0) == 1);
    BOOST_REQUIRE(m(0,1) == 2);
    BOOST_REQUIRE(m(0,2) == 3);
    BOOST_REQUIRE(m(0,3) == 4);
    BOOST_REQUIRE(m(1,0) == 5);
    BOOST_REQUIRE(m(1,1) == 6);
    BOOST_REQUIRE(m(1,2) == 7);
    BOOST_REQUIRE(m(1,3) == 8);
    BOOST_REQUIRE(m(2,0) == 9);
    BOOST_REQUIRE(m(2,1) == 10);
    BOOST_REQUIRE(m(2,2) == 11);
    BOOST_REQUIRE(m(2,3) == 12);
    BOOST_REQUIRE(m(3,0) == 13);
    BOOST_REQUIRE(m(3,1) == 14);
    BOOST_REQUIRE(m(3,2) == 15);
    BOOST_REQUIRE(m(3,3) == 16);
}

BOOST_AUTO_TEST_CASE (mat4_transpose)
{
    mat4 m = mat4
        (1,   2,  3,  4,
         5,   6,  7,  8,
         9,  10, 11, 12,
         13, 14, 15, 16);

    mat4 t = transpose (m);
    BOOST_REQUIRE (t(0,0) == 1);
    BOOST_REQUIRE (t(2,3) == 15);
    BOOST_REQUIRE (t(1,2) == 10);
}

BOOST_AUTO_TEST_CASE (mat4_product)
{
    mat4 m = mat4
        (1,   2,  3,  4,
         5,   6,  7,  8,
         9,  10, 11, 12,
         13, 14, 15, 16);
    
    mat4 p1 = mat4
        ( 90, 100, 110, 120
        ,202, 228, 254, 280
        ,314, 356, 398, 440
        ,426, 484, 542, 600);
    
    mat4 p2 = m*m;
    
    printf("Product:\n");
    print_mat(p2);
    
    BOOST_REQUIRE(mat4_eq(p1, p2, 0, 0));
}

BOOST_AUTO_TEST_CASE (mat4_inverse)
{
    mat4 m = mat4
        (1, 2, 3, 4
        ,5, 6, 7, 8
        ,9, 0, 1, 0
        ,0, 4, 5, 6);
    
    mat4 i1 = mat4
        ( 0.166667,  0.166667,  0.000000, -0.333333
        ,-0.500000,  1.000000, -0.500000, -1.000000
        ,-1.500000, -1.500000,  1.000000,  3.000000
        , 1.583333,  0.583333, -0.500000, -1.666667);
    
    mat4 i2 = inverse(m);
    
    printf("Inverse:\n");
    print_mat(i2);
}

BOOST_AUTO_TEST_CASE (mat4_inverse_singular)
{
    mat4 m = mat4
        ( 0,  1,  2,  3
        , 4,  5,  6,  7
        , 8,  9, 10, 11
        ,12, 13, 14, 15);
    
    BOOST_REQUIRE(mat4_eq(inverse(m), mat4::id, 0, 0));
}

BOOST_AUTO_TEST_CASE (mat4_inverse_and_product)
{
    const float eps = 8*FLT_EPSILON;
    const int ULPs = 4;
    
    mat4 m1 = mat4
        (1, 2, 3, 4
        ,5, 6, 7, 8
        ,9, 0, 1, 0
        ,0, 4, 5, 6);
    
    mat4 m2 = inverse(m1);
    
    printf("m1:\n");
    print_mat(m1);
    
    printf("m1 inverse:\n");
    print_mat(m2);
    
    mat4 p1 = m1*m2;
    mat4 p2 = m2*m1;
    
    printf("m1*m2:\n");
    print_mat(p1);
    
    printf("m2*m1:\n");
    print_mat(p2);
    
    BOOST_REQUIRE(mat4_eq(p1, mat4::id, eps, ULPs));
    BOOST_REQUIRE(mat4_eq(p2, mat4::id, eps, ULPs));
}

BOOST_AUTO_TEST_CASE (mat4_inverse_transform)
{
    const float eps = FLT_EPSILON;
    const int ULPs = 2;

    Spatial s;
    s.setPosition (100.0f, 200.0f, 300.0f);
    s.yaw (45.0f);
    s.pitch (90.0f);

    mat4 m1 = s.inverseTransform();
    mat4 m2 = inverse(s.transform());

    BOOST_REQUIRE(mat4_eq (m1, m2, eps, ULPs));
}

BOOST_AUTO_TEST_CASE (mat3_transpose)
{
    mat3 m = mat3
        (1, 2, 3,
         4, 5, 6,
         7, 8, 9);

    mat3 t = transpose (m);
    BOOST_REQUIRE (t(0,0) == 1);
    BOOST_REQUIRE (t(0,1) == 4);
    BOOST_REQUIRE (t(2,0) == 3);
}

BOOST_AUTO_TEST_CASE (mat3_inverse)
{
    const float eps = FLT_EPSILON;
    const int ULPs = 1;

    mat3 m = mat3
        (1, 2, 3,
         0, 1, 4,
         5, 6, 0);

    mat3 i = inverse (m);
    mat3 mm = inverse(i);
    BOOST_REQUIRE(mat3_eq (m, mm, eps, ULPs));

    printf("m:\n");
    print_mat(m);
    
    printf("m inverse:\n");
    print_mat(i);

    mat3 id1 = m * i;
    mat3 id2 = i * m;
    BOOST_REQUIRE(mat3_eq (mat3::id, id1, eps, ULPs));
    BOOST_REQUIRE(mat3_eq (mat3::id, id2, eps, ULPs));
}

BOOST_AUTO_TEST_CASE (normal_matrix)
{
    const float eps = FLT_EPSILON;
    const int ULPs = 1;

    Spatial s;
    s.setPosition (1, 2, 3);
    s.yaw (30.0f);
    s.pitch (47.0f);

    vec3 x_obj = (1,0,0);
    vec3 y_obj = (0,1,0);
    vec3 normal_obj = cross (x_obj, y_obj);
    mat4 m = s.transform() * mat4::scale (1, 2, 3);
    vec3 x = transform (m, x_obj, 0);
    vec3 y = transform (m, y_obj, 0);
    vec3 n1 = normalise (cross (x, y));
    mat3 normalmat = transpose(inverse(m.to33()));
    vec3 n2 = normalise (normalmat * cross (x_obj, y_obj));

    BOOST_REQUIRE (vec3_eq (n1, n2, eps, ULPs));
}
