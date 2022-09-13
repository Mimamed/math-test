#pragma once
#include <math.h>
#include <iostream>


using namespace std;


class vec3
{

private:
		

public:
		
	float v3[3];

	//Constructors

	vec3() // zero length vector
	{
		for (int i = 0; i < 3; i++)
		{
			v3[i] = 0;
		}
	}
		
	vec3(float x, float y, float z)
	{
		v3[0] = x;
		v3[1] = y;
		v3[2] = z;
	}
		
	vec3(const vec3& v)
	{
		*this = v;
	}

	//Functions
	bool operator==(vec3& v)
	{
		for (int i = 0; i < 3; i++)
		{
			if (v3[i] != v[i])
			{
				return false;
			}
		}
		return true;
	}

	bool operator!=(vec3& v)
	{
		for (int i = 0; i < 3; i++)
		{
			if (v3[i] != v[i])
			{
				return true;
			}
		}
		return false;
	}

	vec3 operator-(vec3& v)
	{
		vec3 answer;
		for (int i = 0; i < 3; i++)
		{
			answer[i] = v3[i] - v[i];
		}

		return answer;
			
	}

	vec3 operator-()
	{
		vec3 temp;
		for (int i = 0; i < 3; i++)
		{
			temp[i] = -v3[i];
		}
		return temp;
	}

	void operator-=(vec3& v)
	{
		for (int i = 0; i < 3; i++)
		{
			v3[i] = v3[i] - v[i];
		}
	}

	void operator+=(vec3& v)
	{
		for (int i = 0; i < 3; i++)
		{
			v3[i] = v3[i] + v[i];
		}
	}

	vec3 operator+(vec3& v)
	{
		vec3 answer;
		for (int i = 0; i < 3; i++)
		{
			answer[i] = v3[i] + v[i];
		}

		return answer;
	}

	void operator*=(float scalar)
	{
		for (int i = 0; i < 3; i++)
		{
			v3[i] = v3[i] * scalar;
		}
	}

	vec3 operator*(float scalar)
	{
		vec3 answer;
		for (int i = 0; i < 3; i++)
		{
			answer[i] = v3[i] * scalar;
		}

		return answer;
	}

	float& operator[](int index)
	{
		return v3[index];
	}


	void printVector()
	{
		for (int i = 0; i < 3; i++)
		{
			cout << v3[i] << " -- ";
		}
		cout << endl;
	}

};


