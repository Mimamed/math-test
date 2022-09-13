#pragma once
#include <iostream>

using namespace std;

class mat4
{
public:


	vec4 matrix[4];

	mat4()
	{
		for (int r = 0; r < 4; r++)
		{
			matrix[r] = vec4();
			matrix[r][r] = 1;
		}
	}

	mat4(const vec4& r1, const vec4& r2, const vec4& r3, const vec4& r4)
	{
		matrix[0] = r1;
		matrix[1] = r2;
		matrix[2] = r3;
		matrix[3] = r4;
	}

	mat4(mat4& m)
	{
		for (int i = 0; i < 4; i++)
		{
			matrix[i] = m[i];//fråga om detta (varför funkar inte [] operatornredan här?
		}
	}


	//const vec4& operator[](int index) const//testa runt denna
	//{
	//	return matrix[index];
	//}

	vec4& operator[](int index)
	{
		return matrix[index];
	}

	void operator=(mat4& rhs)
	{
		for (int i = 0; i < 4; i++)
		{
			matrix[i] = rhs[i];
		}
	}

	mat4 operator*(mat4& rhs)
	{
		mat4 answer(*this);

		for (int y = 0; y < 3; y++)
		{
			for (int x = 0; x < 3; x++)
			{
				answer[y][x] = 0;
				for (int i = 0; i < 3; i++)
				{
					answer[y][x] += matrix[y][i] * rhs[i][x];
				}
			}
		}
		return answer;
	}

	bool operator==(mat4& m)
	{
		for (int x = 0; x < 4; x++)
		{
			if (matrix[x] != m[x])
			{
				return false;
			}
		}
		return true;
	}

	bool operator!=(mat4& m)
	{
		for (int x = 0; x < 4; x++)
		{

			if (matrix[x] != m[x])
			{
				return true;
			}
		}
		return false;
	}


	

	void printMatrix()
	{
		mat4 m(*this);
		for (int r = 0; r < 4; r++)
		{
			for (int c = 0; c < 4; c++)
			{
				cout << m[r][c] << "  ";
			}
			cout << endl;
		}
		cout << endl;
	}

};




