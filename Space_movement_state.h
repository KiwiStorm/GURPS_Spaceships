#pragma once
#include <math.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

typedef long long ll;
typedef long double ld;

class Space_movement_state
{

	struct point
	{
		ld x, y, z;
	};

	struct vect : point
	{
		vect() {}

		vect(ld x, ld y, ld z)
		{
			this->x = x;
			this->y = y;
			this->z = z;
		}

		ld get_size()
		{
			return sqrt(x * x + y * y + z * z);
		}

		void normalize()
		{
			ld size = get_size();
			x /= size;
			y /= size;
			z /= size;
		}

		void set_diriction(ld nx, ld ny, ld nz)
		{
			ld old_size = get_size();
			x = nx;
			y = ny;
			z = nz;
			set_size(old_size);
		}

		void set_size(ld sz)
		{
			ld temp_sz = get_size();
			x *= sz / temp_sz;
			y *= sz / temp_sz;
			z *= sz / temp_sz;
		}

		static vect cross_product(const vect &v1, const vect &v2)
		{
			return {v1.y * v2.z - v1.z * v2.y, v1.z * v2.x - v1.x * v2.z, v1.x * v2.y - v1.y * v2.x};
		}

		static ld dot_product(const vect &v1,const vect &v2)
		{
			return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
		}

		void move_point(point &p)
		{
			p.x += x;
			p.y += y;
			p.z += z;
		}

		vect& operator*=(const int & a)
		{
			x *= a;
			y *= a;
			z *= a;
			return *this;
		}

		vect& operator*(const int & a) const
		{
			vect res = *this;
			res *= a;
			return res;
		}

		vect& operator+=(const vect &v)
		{
			x += v.x;
			y += v.y;
			z += v.z;
			return *this;
		}

		vect& operator+(const vect &v) const
		{
			vect res = *this;
			res += v;
			return res;
		}
	};

public:
	
	const ld C = 299792458;
	vect velocity, acceleration;
	point posititon;
	ll turn_time;
	ld max_speed = 0.2 * C;

	Space_movement_state() 
	{
		velocity = acceleration = { 0, 0, 0 };
		posititon = { 0, 0, 0 };
		turn_time = 20;
	}

	Space_movement_state(point p, vect v, vect a, ld m, ll t = 20) 
	{
		posititon = p;
		acceleration = a;
		velocity = v;
		turn_time = t;
		max_speed = m;
	}

	ld get_acceleration_g()
	{
		return acceleration.get_size() / 10;
	}

	ld get_speed_miles_per_second()
	{
		return velocity.get_size() / 1800;
	}

	static ld get_distance(Space_movement_state s1, Space_movement_state s2)
	{
		return sqrt((s1.posititon.x - s2.posititon.x) * (s1.posititon.x - s2.posititon.x) + (s1.posititon.y - s2.posititon.y) * (s1.posititon.y - s2.posititon.y) + (s1.posititon.z - s2.posititon.z) * (s1.posititon.z - s2.posititon.z));
	}

	void set_sturn_time(ll t)
	{
		turn_time = t;
	}

	void set_acceleration(ld x, ld y, ld z)
	{
		acceleration = {x, y, z};
	}

	void set_velocity(ld x, ld y, ld z)
	{
		velocity = {x, y, z};
	}

	void set_position(ld x, ld y, ld z)
	{
		posititon = {x, y, z};
	}

	void next_turn()
	{
		velocity.move_point(posititon);
		vect acc_mov = acceleration;
		ld l = 0, r = turn_time;
		acc_mov.normalize();
		for (int i = 0; i < 60; ++i) 
		{
			ld m = (r + l) / 2;
			if ((velocity + acc_mov * m).get_size() >= max_speed)
			{
				r = m;
			}
			else
			{
				l = m;
			}
		}
		acc_mov.set_size(acceleration.get_size() * turn_time * turn_time / 2 - acceleration.get_size() * (turn_time - r) * (turn_time - r) / 2);
		velocity += acceleration;
		acc_mov.move_point(posititon);
		velocity.set_size(std::min(velocity.get_size(), max_speed));
	}

	void print()
	{
		std::cout << "position : " << posititon.x << " " << posititon.y << " " << posititon.z << std::endl;
		std::cout << "velocity : " << velocity.get_size() << " " << velocity.x << " " << velocity.y << " " << velocity.z << std::endl;
		std::cout << "acceleration : " << acceleration.get_size() << " " << acceleration.x << " " << acceleration.y << " " << acceleration.z << std::endl;
	}

	~Space_movement_state() {}
};

