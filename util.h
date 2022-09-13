#pragma once
#include "vec3.h"
#include "vec4.h"
#include "mat4.h"


float length(vec3& v3);
float length(const vec4& v4);
vec3 cross(vec3& a, vec3& b);
float dot(vec3& a, vec3& b);
float dot(const vec4& a, const vec4& b);
vec3 normalize(vec3& v3);
vec4 normalize(const vec4& v4);
float determinant4D(mat4& m);
float determinant3D(vec3 m3d[]);
float determinant2D(float colum1[], float colum2[]);
mat4 rotationx(float rad);
mat4 rotationy(float rad);
mat4 rotationz(float rad);
mat4 rotationaxis(vec3 v, float rad);
vec4 multiplyMatrix(mat4& rhs, vec4& v);
mat4 transpose(mat4& m);
mat4 inverse(mat4& m);


inline vec3 max(vec3 a, vec3 b)
{
    return vec3(fmax(a[0], b[0]), fmax(a[1], b[1]), fmax(a[2], b[2]));
}

inline vec4 max(vec4 a, vec4 b)
{
    return vec4(fmax(a[0], b[0]), fmax(a[1], b[1]), fmax(a[2], b[2]), fmax(a[3], b[3]));
}

inline bool cmple(vec3 a, vec3 b)
{
    return a[0] <= b[0] && a[1] <= b[1] && a[2] <= b[2];
}

inline bool cmple(vec4 a, vec4 b)
{
    return a[0] <= b[0] && a[1] <= b[1] && a[2] <= b[2] && a[3] <= b[3];
}

inline bool n_fequal(float f0, float f1, float tol)
{
    float f = f0 - f1;
    return ((f > (-tol)) && (f < tol));
}

inline bool nearequal(vec3 v0, vec3 v1, vec3 epsilon)
{
	vec3 delta = v0 - v1;
	vec3 temp = vec3(0,0,0);
	temp = temp - delta;
	temp = max(temp, delta);
	return cmple(temp, epsilon);
}

inline bool nearequal(vec4 v0, vec4 v1, vec4 epsilon)
{
	vec4 delta = v0 - v1;
	vec4 temp = vec4(0,0,0,0);
	temp = temp - delta;
	temp = max(temp, delta);
	return cmple(temp, epsilon);
}

inline bool matnearequal(mat4 lhs, mat4 rhs)
{
	const float E = 0.00001f;
    const vec4 E4(E, E, E, E);
	return nearequal(lhs[0], rhs[0], E4) && nearequal(lhs[1], rhs[1], E4) && nearequal(lhs[2], rhs[2], E4) && nearequal(lhs[3], rhs[3], E4);
}

float length(vec3& v3)
{
    return (float)sqrt(pow(v3[0], 2) + pow(v3[1], 2) + pow(v3[2], 2));
}

float length(const vec4& v4)
{
    return (float)sqrt(pow(v4[0], 2) + pow(v4[1], 2) + pow(v4[2], 2) + pow(v4[3], 2));
}



vec3 cross(vec3& a, vec3& b)
{
    return vec3((a[1] * b[2]) - (b[1] * a[2]), -(a[0] * b[2]) + (b[0] * a[2]), (a[0] * b[1]) - (b[0] * a[1]));
}


float dot(vec3& a, vec3& b)
{
    return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
}

float dot(const vec4& a, const vec4& b)
{
    return a[0] * b[0] + a[1] * b[1] + a[2] * b[2] + a[3] * b[3];
}

vec3 normalize(vec3& v3)
{
    float temp = length(v3);
    return vec3(v3[0] / temp, v3[1] / temp, v3[2] / temp);
}

vec4 normalize(const vec4& v4)
{
    float temp = length(v4);
    return vec4(v4[0] / temp, v4[1] / temp, v4[2] / temp, v4[3] / temp);
}


float determinant4D(mat4& m)//kan säkert förbättras
{
    int inverter = 1;
    float answer = 0;
    for (int i = 0; i < 4; i++)
    {
        vec3 tempMatrix[3];
        int nextcolumPos = 0;
        for (int u = 1; u < 4; u++)
        {
            if (i == 0)
            {
                tempMatrix[nextcolumPos] = vec3(m[u][1], m[u][2], m[u][3]);
            }
            else if (i == 1)
            {
                tempMatrix[nextcolumPos] = vec3(m[u][0], m[u][2], m[u][3]);
            }
            else if (i == 2)
            {
                tempMatrix[nextcolumPos] = vec3(m[u][0], m[u][1], m[u][3]);
            }
            else if (i == 3)
            {
                tempMatrix[nextcolumPos] = vec3(m[u][0], m[u][1], m[u][2]);
            }
            nextcolumPos++;
        }
        //cout << /*inverter * m[0][i] << endl; **/ determinant3D(tempMatrix) << endl;
        answer += inverter * m[0][i] * determinant3D(tempMatrix);
        inverter *= -1;
    }
    return answer;
}

float determinant3D(vec3 m3d[])
{
    int inverter = 1;
    float answer = 0;
    for (int i = 0; i < 3; i++)
    {
        float tempMatrix1[2];
        float tempMatrix2[2];

        int nextcolumPos = 0;
        for (int u = 1; u < 3; u++)
        {
            if (i == 0)
            {
                tempMatrix1[nextcolumPos] = m3d[u][1]; //vec3(m[u][1], m[u][2], m[u][3]);
                tempMatrix2[nextcolumPos] = m3d[u][2];
            }
            else if (i == 1)
            {
                tempMatrix1[nextcolumPos] = m3d[u][0]; //vec3(m[u][1], m[u][2], m[u][3]);
                tempMatrix2[nextcolumPos] = m3d[u][2];
            }
            else if (i == 2)
            {
                tempMatrix1[nextcolumPos] = m3d[u][0]; //vec3(m[u][1], m[u][2], m[u][3]);
                tempMatrix2[nextcolumPos] = m3d[u][1];
            }
            nextcolumPos++;
        }

        answer += inverter * m3d[0][i] * determinant2D(tempMatrix1, tempMatrix2);
        inverter *= -1;
    }
    return answer;
}

float determinant2D(float row1[], float row2[])
{
    //cout << "tete: " << row1[0] * row2[1] - row2[0] * row1[1];
    return row1[0] * row2[1] - row2[0] * row1[1];
}


mat4 rotationx(float rad)                                           //ska man ignorera den fjärde rad och colum?? FRÅGA OM DETTA
{
    return transpose(mat4(vec4(1, 0, 0, 0), vec4(0, cos(rad), -sin(rad), 0), vec4(0, sin(rad), cos(rad), 0), vec4(0, 0, 0, 1)));
}

mat4 rotationy(float rad)//ska man ignorera den fjärde rad och colum?? FRÅGA OM DETTA
{
    return transpose(mat4(vec4(cos(rad), 0, sin(rad), 0), vec4(0, 1, 0, 0), vec4(-sin(rad), 0, cos(rad), 0), vec4(0, 0, 0, 1)));
}

mat4 rotationz(float rad)//ska man ignorera den fjärde rad och colum?? FRÅGA OM DETTA
{
    return transpose(mat4(vec4(cos(rad), -sin(rad), 0, 0), vec4(sin(rad), cos(rad), 0, 0), vec4(0, 0, 1, 0), vec4(0, 0, 0, 1)));
}

mat4 rotationaxis(vec3 v, float rad)//kan vara fel
{
    return transpose(mat4(vec4(cos(rad) + v[0] * v[0] * (1 - cos(rad)), v[0] * v[1] * (1 - cos(rad)) - v[2] * sin(rad), v[0] * v[2] * (1 - cos(rad)) + v[1] * sin(rad), 0), vec4(v[1] * v[0] * (1 - cos(rad)) + v[2] * sin(rad), cos(rad) + v[1] * v[1] * (1 - cos(rad)), v[1] * v[2] * (1 - cos(rad)) - v[0] * sin(rad), 0), vec4(v[2] * v[0] * (1 - cos(rad)) - v[1] * sin(rad), v[2] * v[1] * (1 - cos(rad)) + v[0] * sin(rad), cos(rad) + v[2] * v[2] * (1 - cos(rad)), 0), vec4(0, 0, 0, 1)));
}

vec4 multiplyMatrix(mat4& rhs, vec4& v) //FRÅGA OM DENNA, VARFÖR KAN JAG INTE HA 2 stycknar operator*?
{
    vec4 answer;

    for (int y = 0; y < 4; y++)
    {
        for (int x = 0; x < 4; x++)
        {
            answer[x] += v[y] * rhs[y][x];
        }
    }
    return answer;
}

mat4 transpose(mat4& m)
{
    mat4 answer;
    for (int y = 0; y < 4; y++)
    {
        for (int x = 0; x < 4; x++)
        {
            answer[y][x] = m[x][y];
        }
    }
    return answer;
}

mat4 inverse(mat4& m)
{
    float factor = determinant4D(m);
    if (factor != 0)
    {
        mat4 answer;
        int inverter = 1;
        for (int ym = 0; ym < 4; ym++)
        {
            for (int xm = 0; xm < 4; xm++)
            {
                vec3 tempMatrix[3];
                int nextRow = 0;

                for (int y = 0; y < 4; y++)
                {
                    if (y != ym)
                    {
                        int nextColum = 0;
                        for (int x = 0; x < 4; x++)
                        {
                            if (x != xm)
                            {
                                //cout << "ym: " << ym << "  xm: " << xm << "  y: " << y << "  x: " << x << "  value: " << m[y][x] << endl;
                                tempMatrix[nextRow][nextColum] = m[y][x];
                                nextColum++;
                            }
                        }
                        nextRow++;
                    }
                }
                /*for (int i = 0; i < 3; i++)
                {
                    tempMatrix[i].test();
                }
                cout << endl;*/

                answer[ym][xm] = inverter * (determinant3D(tempMatrix) / factor);
                inverter = -inverter;
            }
            inverter = -inverter;
        }

        answer = transpose(answer);
        /*cout << endl;
        answer.printMatrix();*/
        return answer;
    }
    else
    {
        return mat4(vec4(0, 0, 0, 0), vec4(0, 0, 0, 0), vec4(0, 0, 0, 0), vec4(0, 0, 0, 0));
    }

}
