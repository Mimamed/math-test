#pragma once
#include <iostream>

using namespace std;


class vec4
{
public:
	float v4[4];
	//float x = 0, y = 0, z = 0, w = 0;

	vec4() // zero length vector
	{
		for (int i = 0; i < 4; i++)
		{
			v4[i] = 0;
		}
	}

	vec4(float x, float y, float z, float w)
	{
		v4[0] = x;
		v4[1] = y;
		v4[2] = z;
		v4[3] = w;
	}

	vec4(const vec4& v)
	{
		*this = v;
	}


	bool operator==(vec4& vec4)
	{
		for (int i = 0; i < 4; i++)
		{
			if (v4[i] != vec4[i])
			{
				return false;
			}
		}

		return true;
	}


	bool operator!=(const vec4& vec4)
	{
		//cout << "  |    " << this->x << "   -   " << vec4.x << "  lika? " << (this->x != vec4.x) << "  |    " << this->y << "   -   " << vec4.y << "  |    " << this->z << "   -   " << vec4.z << "  |    " << this->w << "   -   " << vec4.w;
		for (int i = 0; i < 4; i++)
		{
			if (v4[i] != vec4[i])
			{
				return true;
			}
		}
		return false;
	}


	vec4 operator-(const vec4& v)
	{
		vec4 answer;
		for (int i = 0; i < 4; i++)
		{
			answer.v4[i] = v4[i] - v.v4[i];
		}
		return answer;

	}

	vec4 operator-()
	{
		vec4 answer;
		for (int i = 0; i < 4; i++)
		{
			answer.v4[i] = -v4[i];
		}
		return answer;
	}

	void operator-=(vec4& v)//test
	{
		for (int i = 0; i < 4; i++)
		{
			v4[i] = v4[i] - v.v4[i];
		}
	}

	void operator+=(vec4& v)
	{
		for (int i = 0; i < 4; i++)
		{
			v4[i] = v4[i] + v.v4[i];
		}
	}

	void operator*=(float scalar)
	{
		for (int i = 0; i < 4; i++)
		{
			v4[i] = v4[i] * scalar;
		}
	}

	vec4 operator+(const vec4& v)
	{
		vec4 answer;
		for (int i = 0; i < 4; i++)
		{
			answer.v4[i] = v4[i] + v[i];
		}
		return answer;
	}

	vec4 operator*(float scalar)
	{
		vec4 answer;
		for (int i = 0; i < 4; i++)
		{
			answer.v4[i] = v4[i] * scalar;
		}
		return answer;
	}

	float& operator[](int index)  //FRÅGA OM DETTA OCKSÅ &
	{
		return v4[index];
	}

	const float& operator[](int index) const //FRÅGA OM DETTA OCKSÅ &
	{
		return v4[index];
	}

	void printVector()
	{
		for (int i = 0; i < 4; i++)
		{
			cout << v4[i] << " -- ";
		}
		cout << endl;
	}

};
