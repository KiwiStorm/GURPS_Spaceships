#ifndef GLOBALFUNCTIONS_H
#define GLOBALFUNCTIONS_H
#include "vector"
#include "string"
#include "random"


using namespace std;

typedef long long ll;
typedef long double ld;

static int roll3d6() {
    return rand() % 6 + rand() % 6 + rand() % 6 + 3;
}

static int skillCheck(int bonus, int skill) { //0 - крит провал, 1 - провал, 2 - успех, 3 - крит успех, 4 - ошибка
    int rollResult = roll3d6();
    int effectiveSkill = skill + bonus;
    if(rollResult == 3 && effectiveSkill >= 3)  {return 3;}  //куча строк, зато красиво и понятно
    if(rollResult == 4 && effectiveSkill >= 4)  {return 3;}
    if(rollResult == 5 && effectiveSkill >= 15) {return 3;}
    if(rollResult == 6 && effectiveSkill >= 16) {return 3;}
    if(rollResult == 18) {return 0;}
    if(rollResult == 17 && effectiveSkill <  16) {return 0;}
    if(rollResult == 17 && effectiveSkill >= 16) {return 1;}
    if(rollResult >= effectiveSkill + 10) {return 0;}
    if(rollResult <= effectiveSkill) {return 2;}
    if(rollResult > effectiveSkill) {return 1;}
    else { return 4; }
}

static long double gurpsScaling1(const long double baseValue,const  int cycles) { //для увеличения стоимости и большинства характеристик
    long double ans = baseValue;
    if(cycles < 0) {
        throw "WrongDataGS1";
    }
    for(int i = 0;i < cycles;i++) {
        if(i % 2 == 0) {
            ans*= 10;
            ans/= 3;
        }
        else {
            ans*= 3;
        }
    }
    return ans;
}

static long double gurpsScaling2(const long double baseValue,const  int cycles) {//для увеличения размера, пока пробный вариант, там сложнее всё
    long double ans = baseValue;
    if(cycles < 0) {
        throw "WrongData : GS2";
    }
    for(int i = 0;i < cycles;i++) {
            ans*=3;
            ans/=2;
    }
    return ans;
}

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
		return { v1.y * v2.z - v1.z * v2.y, v1.z * v2.x - v1.x * v2.z, v1.x * v2.y - v1.y * v2.x };
	}

	static ld dot_product(const vect &v1, const vect &v2)
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

#endif // GLOBALFUNCTIONS_H
