
class Base
{
public:
	void memfcn(Base &b) { b = *this; }
};

class Pub_Derv : public Base
{
public:
	void memfcn(Base &b) { b = *this; }
};

class Priv_Derv : private Base
{
public:
	void memfcn(Base &b) { b = *this; }
};

class Prot_Derv : protected Base
{
public:
	void memfcn(Base &b) { b = *this; };
};

class Derived_from_Public : public Pub_Derv
{
public:
	void memfcn(Base &b) { b = *this; }
};

class Deriver_from_Private : public Priv_Derv
{
public:
	//void memfcn(Base &b) { b = *this; }
};

class Deriver_from_protected : public Prot_Derv
{
public:
	void memfcn(Base &b) { b = *this; }
};

int main()
{
	Pub_Derv d1;
	Base *p = &d1;

	Priv_Derv d2;
	//p = &d2;

	Prot_Derv d3;
	//p = &d3;

	Derived_from_Public dd1;
	p = &dd1;

	Deriver_from_Private dd2;
	//p = &dd2;

	Deriver_from_protected dd3;
	//p = &dd3;
}