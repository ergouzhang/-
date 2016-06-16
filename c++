
1.p40.位与字节：
（1）C++中，位与字节的关系不是确定的，需要根据系统来定。
但是，short类型不小于16位， -32768~32767
int不小于short，long不小于32位，longlong至少64位。
float 类型通常为32位，double为64位。
通常1byte＝8bit, int为4byte.
（2）使用sizeof()来得到类型的长度，以字节为单位。
(3)溢出： 无符号类型益出为从0重新开始；有符号类型溢出为从最小值重新开始。
————————————————————————————
2.p59 运算符
（1）％ 为取余运算，x％y ，两个操作数需要均为整数。
(2) 使用｛｝去初始化变量时，不允许缩窄： 例如  int x=66; char y{x} 是不被允许的。
——————————————————————————————
3.p76
(1)字符串数组：
char string[]=“nihao”;  //初始化时，可不写数组的元素数。
char string[100]=“nihao”; //空余元素用 \0填充。 
sizeof() 计算的改数组的所有元素数，包含\0 。
strlen()计算有值的元素数，不包含\0。
可使用 string[1]=‘\0’来截断此字符串数组。
——————————————————————————
4.p80
字符串数组的输入：
(1)cin 识别到字符串的空格、换行停止；输入确定的回车键将留在输入序列中。
（2）cin.getline（arr，长度） ：识别到字符串的回车键为止，且不保留回车键。
（3）cin.get(arr,长度):识别到字符串回车键为止，且在输入缓存中保留回车，下一次输入识别的第一个字符将为回车。

________________
5.p86
string类型：
（1）string类型需要引入头文件 #include <string>;
 (2)string 类型的元素可以直接赋值给另一个string类型，也可以相加；
（3）输入：可使用cin>>string   //空格被视为完成。
   getline(cin,string) //效果等同于 cin.getline();

——————————————————————————————————
6.p90
结构 struct:
(1)定义： struct sth={string name; int age; float score;};  
(2)实例化：  sth zwj={“zwj”,20,100.0};
(3)调用：  zwj.name /zwj.age/zwj.score
(4)结构数组：  sth arr[10]={{“zwj”,20,100},{“zzz”,20,12}};   使用arr[0].name来调用
————————————————————————————————————
7.p94
公用体：
（1）定义：union sth＝｛int a； int b； ｝  每次只能给一个成员赋值。
（2）可在结构体内定义
——————————————————————————————
8.p95
枚举：
（1）定义：enum sth＝｛red，orange，yellow｝；  //不赋值的情况下，默认值从0开始。
（2）赋值： enum sth＝｛red＝100，orange，yellow｝； //赋值的成员之后的成员默认依次＋1.

——————————————————————————————
9.p100
指针：
（1）定义： int *p= new int;   //调用 delete p来删除p指向的内存的内容。
p为地址值；

（2）指针数组:
int *p=new int [10]; //使用p[2]来调用。   调用delete ［ ］p来删除。
p的地址为p[0];   
普通定义的数组，其数组名为第一个元素的地址。
int a[10];  // a即为&a［0］； &a即为10个int类型内存块的第一个元素的地址。例如，a＋1（移动4字节），&a＋1（移动40字节）

（3）字符串数组：
char *p=“nihao”; 
cout<<p<<endl<<*p;   //p的输出为nihao；＊p的输出为n。

（4）整型数组指针&字符串数组指针：
整型数组：
int a[10]={1,23,4,5}; 
int *p=a;
cout<<p<<endl<<*p;  //输出为&a［0］和1. 

字符串数组：
char a[10]={‘a’,’b’};
char *p=a;
cout<<p<<endl<<*p; //输出为ab和a.

________
11时间相关函数
#include<time.h>
(1)作为rand（）的种子：srand(time(NULL));
(2)获取时间:
time_t t=time(NULL); //当前日期转换为秒
tm* tm=localtime(&t);//转换为 年－月－日－时－分－秒
tm->tm_min;//min
tm->tm_month//从0开始

time_t tt=mk(tm)//由年－月－日－时－分－秒转换为秒

———————
12
文件操作
（1）写入
FILE* fp=fopen(“全路径”,”wb”); //打开
fwrite(buf,1,sizeof(buf),fp)  //写入


(2)读取
FILE *fp=fopen(“全路径”,”rb”);
size_t read=fread(buf,1,读取字节,fp);
(3)随机读取
fseek(fp,间隔字节,SEEK_SET);  SEEK_SET:从头／ SEEK_END：尾
（4） 按行写入、读取

fprint(fp,”port=%d\n”,port);  //将port字符串格式化后输入到文件中

fgets(buf,128,fp); //读取直到发现 ／n 

13
运算符重载
（1）＋
className operator +(const className& other)
(2)[]
element& operator[](int index)
(3) ==
bool operator ==(const className& other)
(4)() 类型转换
operator Type() // Type为目标类型
｛
…
return result;
｝

(5)