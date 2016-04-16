Main函数：
1. 当main函数没有写明返回值时候，默认为0.
2. 命名空间： 若头文件为include <iostream>，则在程序中需使用 using namespace std 来表明调用std这个命名空间,相当于 std::cout<<“nihao ” 。
命名空间的建立：
在所需包涵的类的头文件及cpp文件中用 namespace xxx{代码} 包含即可。
－－－－－－－－－－
输入输出：
1. 输出cout<<“nihao”<<endl; // endl表示换行 同\n
2. 输入 cin>>””  ;
－－－－－－－－－－－

类的引用：
(1)新建一个包含hpp的cpp文件，在hpp头文件中，定义该类及接口：
class people 
{public:
int age();

}
(2)在cpp文件中，定义具体的方法：
int people::age()      // ::定义类的方法
{

return 0;
}
－－－－－－－－－－－
构造方法和析构方法：
(1)例如：
class people{
public:

people(){};        //构造方法
~people(){};	   //析构方法

}


int main(){

people *person=new people();  //此时，调用构造方法

delete person;   //调用析构方法


}

(2)可利用定义局部代码块变量，会自动释放

void run(){

people person;

printf(“asda”);     //此时，会先执行构造，然后运行 run（）里的剩余的代码，最后会自动执行析构，释放掉person。


}


——————————————
虚函数，纯虚函数：
（1）定义： virtual void sayhi();  //虚函数，系统可动态定位此函数，用于子类中的重写。
  virtual void sayhi()=0;  //纯虚函数，类似接口，不必实现，可在子类中实现。


————————————————
运算符重载：
使用  operator 来定义：
int operator +=( , ){  return   };   //传入两个类的实例

——————————————————
函数指针：
（1）定义： 返回值类型 （＊指针名）（传入参数）；   
（2）获取地址： 指针名＝函数名；
（3）调用： （＊指针名）（传入参数）；   

利用typedef来定义函数指针：
（1） 定义：typedef  返回值类型（＊指针名）（传入参数）；
（2）调用： 指针名 指针变量名；  //定义指针变量
         指针变量名＝函数名；
 	  指针变量名（传入参数）； 

利用typedef来引用类里的函数：
（1） 定义：typedef 返回值 （类名::＊指针名）（传入参数）；
（2）调用： 实例化类；
         指针名 指针变量名＝&类::函数名；
         (类实例.*指针变量名)(传入参数)；   