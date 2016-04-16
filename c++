Main函数：
1. 当main函数没有写明返回值时候，默认为0.
2. 命名空间： 若头文件为include <iostream>，则在程序中需使用 using namespace std 来表明调用std这个命名空间,相当于 std::cout<<“nihao ” 。
命名空间的建立：
在所需包涵的类的头文件及cpp文件中用 namespace xxx{代码} 包含即可。

输入输出：
1. 输出cout<<“nihao”<<endl; // endl表示换行 同\n
2. 输入 cin>>””  ;


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