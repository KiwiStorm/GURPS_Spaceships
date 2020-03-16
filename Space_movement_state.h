#pragma once
#include <math.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include "globalfunctions.h"
#include "configs.h"

typedef long long ll;
typedef long double ld;

class Space_movement_state
{
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

	Space_movement_state(point p, vect v, vect a, ld mx_spd, ll t = 20) 
	{
		posititon = p;
		acceleration = a;
		velocity = v;
		turn_time = t;
		max_speed = mx_spd;
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
		(velocity * turn_time).move_point(posititon);
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

