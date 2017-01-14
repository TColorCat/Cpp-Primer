	class A{ public:A() = default;virtual ~A(){} };
	class B :public A{ public:B() = default; ~B(){} };
	class C :public A{ public:C() = default; ~C(){} };
	class D :public B, public A{ public:D() = default; ~D(){} };
	
void test()
	{
		A *pa = new D;
		A*c = new C;
		B*pd = new B;

		B*ce = dynamic_cast<B*>(c);
		//NULL

		C*pc = dynamic_cast<C*>(pd);
		//NULL
		B* se = dynamic_cast<B*>(pa);
		//right
	}//dynamic_cast 只能从派生类到基类的指针或者引用类型转换
