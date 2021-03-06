#extern "C"

##extern:
[baike](http://baike.baidu.com/view/963932.htm)
extern可以置于变量或者函数前，以表示变量或者函数的定义在别的文件中，提示编译器遇到此变量和函数时在其他模块中寻找其定义。另外，extern也可用来进行链接指定。

在一个源文件里定义了一个数组：char a[6];
在另外一个文件里用下列语句进行了声明：extern char *a；
请问，这样可以吗？

答案与分析：

1)不可以，程序运行时会告诉你非法访问。原因在于，**指向类型T的指针并不等价于类型T的数组**。

extern char *a声明的是一个指针变量而不是字符数组，因此与实际的定义不同，从而造成运行时非法访问。

应该将声明改为extern char a[]。

2)具体分析如下，如果a[] = "abcd",则外部变量a=0x12345678 (数组的起始地址)，而

*a是重新定义了一个指针变量，a的地址可能是0x87654321,

直接使用*a是错误的.

3)这提示我们，在使用extern时候要严格对应声明时的格式，在实际编程中，这样的错误屡见不鲜。

4)extern用在变量声明中常常有这样一个作用，你在*.c文件中声明了一个全局的变量，这个全局的变量如果要被引用，就放在
*.h中并用extern来声明。

这个关键字真的比较可恶，在定义（函数）的时候，这个extern居然可以被省略，所以会让你搞不清楚到底是声明还是定义，下面分变量和函数两类来说：

尤其是对于变量来说。

1. extern int a;//声明一个全局变量a
2. int a; //定义一个全局变量a
3. extern int a =0 ;//定义一个全局变量a 并给初值。一旦给予赋值，一定是定义，定义才会分配存储空间。
4. int a =0;//定义一个全局变量a,并给初值，声明之后你不能直接使用这个变量，需要定义之后才能使用。

第四个等于第三个，都是定义一个可以被外部使用的全局变量，并给初值。

糊涂了吧，他们看上去可真像。但是定义只能出现在一处。也就是说，不管是int a;还是int a=0;都只能出现一次，而那个extern int a可以出现很多次。

当你要引用一个全局变量的时候，你就要声明extern int a;这时候extern不能省略，因为省略了，就变成int a;这是一个定义，不是声明。


---
编译、链接
编辑

声明外部变量
现代编译器一般采用按文件编译的方式，因此在编译时，各个文件中定义的全局变量是互相不透明的。也就是说，在编译时，全局变量的可见域限制在文件内部。
下面举一个简单的例子：
创建一个工程，里面含有A.cpp和B.cpp两个简单的C++源文件：

//A.cpp
inti;
int main()
{
}
//B.cpp
int i;

这两个文件极为简单，在A.cpp中我们定义了一个全局变量i，在B中我们也定义了一个全局变量i。
我们对A和B分别编译，都可以正常通过编译，但是进行链接的时候，却出现了错误，错误提示如下：

Linking...
B.obj:errorLNK2005:"inti"(?i@@3HA)alreadydefinedinA.obj
Debug/A.exe:fatalerrorLNK1169:oneormoremultiplydefinedsymbolsfound
Errorexecutinglink.exe.
A.exe-2error(s),0warning(s)
这就是说，在编译阶段，各个文件中定义的全局变量相互是不透明的，编译A时觉察不到B中也定义了i，同样，编译B时觉察不到A中也定义了i。
但是到了链接阶段，要将各个文件的内容“合为一体”，因此，如果某些文件中定义的全局变量名相同的话，在这个时候就会出现错误，也就是上面提示的重复定义的错误。
因此，各个文件中定义的全局变量名不可相同。

在链接阶段，各个文件的内容（实际是编译产生的obj文件）是被合并到一起的，因而，定义于某文件内的全局变量，在链接完成后，它的可见范围被扩大到了整个程序。
**这样一来，按道理说，一个文件中定义的全局变量，可以在整个程序的任何地方被使用**
，举例说，如果A文件中定义了某全局变量，那么B文件中应可以使用该变量。修改我们的程序，加以验证：

//A.cpp
int main()
{
i=100;//试图使用B中定义的全局变量
}
//B.cpp
int i;
编译结果如下：

Compiling...
A.cpp
C:\DocumentsandSettings\wangjian\桌面\tryextern\A.cpp(5):errorC2065:'i':undeclaredidentifier
Errorexecutingcl.exe.
A.obj-1error(s),0warning(s)
编译错误。
其实出现这个错误是意料之中的，**因为文件中定义的全局变量的可见性扩展到整个程序是在链接完成之后，而在编译阶段，他们的可见性仍局限于各自的文件。**
编译器的目光不够长远，编译器没有能够意识到，某个变量符号虽然不是本文件定义的，但是它可能是在其它的文件中定义的。
虽然编译器不够有远见，但是我们可以给它提示，帮助它来解决上面出现的问题。这就是extern的作用了。
extern的原理很简单，就是告诉编译器：“你现在编译的文件中，有一个标识符虽然没有在本文件中定义，但是它是在别的文件中定义的全局变量，你要放行！”

我们为上面的错误程序加上extern关键字：

//A.cpp
extern int i;
int main()
{
i=100;//试图使用B中定义的全局变量
}
//B.cpp
int i;

顺利通过编译，链接。

##
函数

###常见extern放在函数的前面成为函数声明的一部分，那么，C语言的关键字extern在函数的声明中起什么作用？

答案与分析：

如果函数的声明中带有关键字extern，仅仅是暗示这个函数可能在别的源文件里定义，没有其它作用。

即下述两个函数声明没有明显的区别：
extern int f(); 和int f();
当然，这样的用处还是有的，就是在程序中取代include “*.h”来声明函数，在一些复杂的项目中，我比较习惯在所有的函数声明前添加extern修饰。

###当函数提供方单方面修改函数原型时，如果使用方不知情继续沿用原来的extern申明，这样编译时编译器不会报错。但是在运行过程中，因为少了或者多了输入参数，往往会造成系统错误，这种情况应该如何解决？
答案与分析：
目前业界针对这种情况的处理没有一个很完美的方案，通常的做法是提供方在自己的xxx_pub.h中提供对外部接口的声明，然后调用包涵该文件的头文件，从而省去extern这一步。以避免这种错误。
宝剑有双锋，对extern的应用，不同的场合应该选择不同的做法。

###extern “C”
在C++环境下使用C函数的时候，常常会出现编译器无法找到obj模块中的C函数定义，从而导致链接失败的情况，应该如何解决这种情况呢？
答案与分析：
C++语言在编译的时候为了解决函数的多态问题，会将函数名和参数联合起来生成一个中间的函数名称，而C语言则不会，因此会造成链接时找不到对应函数的情况，此时C函数就需要用extern “C”进行链接指定，这告诉编译器，请保持我的名称，不要给我生成用于链接的中间函数名。
下面是一个标准的写法：

		//在.h文件的头上
		#ifdef __cplusplus
			#if __cplusplus
				extern "C"{
			#endif
		#endif /* __cplusplus */
		…
		…
		//.h文件结束的地方
		#ifdef __cplusplus
			#if __cplusplus
				}
			#endif
		#endif /* __cplusplus */

##C++中extern c的深层探索
C++语言的创建初衷是“a better C”，但是这并不意味着C++中类似C语言的全局变量和函数所采用的编译和连接方式与C语言完全相同。作为一种欲与C兼容的语言，C++保留了一部分过程式语言的特点（被世人称为“不彻底地面向对象”），因而它可以定义不属于任何类的全局变量和函数。但是，C++毕竟是一种面向对象的程序设计语言，为了支持函数的重载，C++对全局函数的处理方式与C有明显的不同。

2.从标准头文件说起
某企业曾经给出如下的一道面试题：
面试题
为什么标准头文件都有类似以下的结构？

		#ifndef __INCvxWorksh
			#define __INCvxWorksh
			#ifdef __cplusplus
				extern "C" {
			#endif
			/*...*/
			#ifdef __cplusplus
			}
			#endif
		#endif /* __INCvxWorksh */
分析
显然，头文件中的编译宏“#ifndef __INCvxWorksh、#define __INCvxWorksh、#endif” 的作用是防止该头文件被重复引用。

那么

		#ifdef __cplusplus
			extern "C" {
		#endif
		#ifdef __cplusplus
			}
		#endif
的作用又是什么呢？我们将在下文一一道来。

3.深层揭密extern "C"

extern "C" 包含双重含义，从字面上即可得到：
	
* 首先，被它修饰的目标是“extern”的；
* 其次，被它修饰的目标是“C”的。让我们来详细解读这两重含义。

被extern "C"限定的函数或变量是extern类型的；


extern是C/C++语言中表明函数和全局变量作用范围（可见性）的关键字，该关键字告诉编译器，其声明的函数和变量可以在本模块或其它模块中使用，记住，下列语句：
extern int a;
仅仅是一个变量的声明，其并不是在定义变量a，并未为a分配内存空间。变量a在所有模块中作为一种全局变量只能被定义一次，否则会出现连接错误。


引用一个定义在其它模块的全局变量或函数（如，全局函数或变量定义在A模块，B欲引用）有两种方法，

* 一、B模块中include模块A的头文件。
* 二、模块B中对欲引用的模块A的变量或函数重新声明一遍，并前加extern关键字。

通常，在模块的头文件中对本模块提供给其它模块引用的函数和全局变量以关键字extern声明。

例如，如果模块B欲引用该模块A中定义的全局变量和函数时只需包含模块A的头文件即可。 这样，模块B中调用模块A中的函数时，在编译阶段，模块B虽然找不到该函数，但是并不会报错；它会在连接阶段中从模块A编译生成的目标代码中找到此函数。

与extern对应的关键字是static，被它修饰的全局变量和函数只能在本模块中使用。因此，一个函数或变量只可能被本模块使用时，其不可能被extern “C”修饰。

被extern "C"修饰的变量和函数是按照C语言方式编译和连接的；

1. 未加extern “C”声明时的编译方式
首先看看C++中对类似C的函数是怎样编译的。
作为一种面向对象的语言，C++支持函数重载，而过程式语言C则不支持。函数被C++编译后在符号库中的名字与C语言的不同。例如，假设某个函数的原型为：
void foo( int x, int y );
该函数被C编译器编译后在符号库中的名字为_foo，
而C++编译器则会产生像_foo_int_int之类的名字（不同的编译器可能生成的名字不同，但是都采用了相同的机制，生成的新名字称为“mangled name”）。

_foo_int_int这样的名字包含了函数名、函数参数数量及类型信息，C++就是靠这种机制来实现函数重载的。
例如，在C++中，函数void foo( int x, int y )与void foo( int x, float y )编译生成的符号是不相同的，后者为_foo_int_float。

同样地，C++中的变量除支持局部变量外，还支持类成员变量和全局变量。用户所编写程序的类成员变量可能与全局变量同名，我们以"."来区分。而本质上，编译器在进行编译时，与函数的处理相似，也为类中的变量取了一个独一无二的名字，这个名字与用户程序中同名的全局变量名字不同。

2. 未加extern "C"声明时的连接方式

假设在C++中，模块A的头文件如下：
	
	// 模块A头文件　moduleA.h
	#ifndef MODULE_A_H
	#define MODULE_A_H
		int foo( int x, int y );
	#endif

在模块B中引用该函数：
	
	// 模块B实现文件　moduleB.cpp
	#include "moduleA.h"
	foo(2,3);

实际上，在连接阶段，连接器会从模块A生成的目标文件moduleA.obj中寻找_foo_int_int这样的符号！

1. 加extern "C"声明后的编译和连接方式

加extern "C"声明后，模块A的头文件变为：

	// 模块A头文件　moduleA.h
	#ifndef MODULE_A_H
	#define MODULE_A_H
		extern "C" int foo( int x, int y );
	#endif
	
在模块B的实现文件中仍然调用foo( 2,3 )，其结果是：
（1）模块A编译生成foo的目标代码时，没有对其名字进行特殊处理，采用了C语言的方式；
（2）连接器在为模块B的目标代码寻找foo(2,3)调用时，寻找的是未经修改的符号名_foo。

如果在模块A中函数声明了foo为extern "C"类型，而模块B中包含的是extern int foo( int x, int y ) ，则模块B找不到模块A中的函数；反之亦然。
所以，可以用一句话概括extern “C”这个声明的真实目的（任何语言中的任何语法特性的诞生都不是随意而为的，来源于真实世界的需求驱动。我们在思考问题时，不能只停留在这个语言是怎么做的，还要问一问它为什么要这么做，动机是什么，这样我们可以更深入地理解许多问题）：
实现C++与C及其它语言的混合编程。
明白了C++中extern "C"的设立动机，我们下面来具体分析extern "C"通常的使用技巧。


4.extern "C"的惯用法
（1）在C++中引用C语言中的函数和变量，在包含C语言头文件（假设为cExample.h）时，需进行下列处理：

	extern "C"
	{
		#include "cExample.h"
	}

而在C语言的头文件中，对其外部函数只能指定为extern类型，C语言中不支持extern "C"声明，在.c文件中包含了extern "C"时会出现编译语法错误。

笔者编写的C++引用C函数例子工程中包含的三个文件的源代码如下：
	
	/*c语言头文件：cExample.h */
	#ifndef C_EXAMPLE_H
		#define C_EXAMPLE_H
		extern int add(int x,int y);
	#endif

	/*c语言实现文件：cExample.c */
	#include "cExample.h"
	int add( int x, int y )
	{
		return x + y;
	}
	
	//c++实现文件，调用add：cppFile.cpp
	extern "C"
	{
		#include "cExample.h"
	}
	
	int main(int argc, char* argv[])
	{
		add(2,3);
		return 0;
	}
如果C++调用一个C语言编写的.DLL时，当包括.DLL的头文件或声明接口函数时，应加extern "C" {　}。

(2)在C++引用C语言中的函数和变量时，C++的头文件需添加extern "C"，但是在C语言中不能直接引用声明了extern "C"的该头文件，应该仅将C文件中将C++中定义的extern "C"函数声明为extern类型。

笔者编写的C引用C++函数例子工程中包含的三个文件的源代码如下：

	//C++头文件 cppExample.h
	#ifndef CPP_EXAMPLE_H
		#define CPP_EXAMPLE_H
		extern "C" int add( int x, int y );
	#endif

	//C++实现文件 cppExample.cpp
	#include "cppExample.h"
	int add( int x, int y )
	{
		return x + y;
	}
	
	/* C实现文件 cFile.c
	/* 这样会编译出错：#include "cppExample.h" */
	extern int add( int x, int y );
	int main( int argc, char* argv[] )
	{
		add( 2, 3 );
		return 0;
	}