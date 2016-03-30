#pragma once

struct NoDefault
{
	NoDefault(int val) : number(val) { }
	int number;
};

struct C
{
	C() : obj(0) { }  // defautl constructor function
	NoDefault obj;
};