#include"common.h"

//这里理解为什么传递参数matrix1[3][6]、middle[6][3]时，需要使用俩个不同的模板类型，因为matrix1和middle从C++的基本定义来看都是一维数组，保存
//的元素却有区别，前者保存的元素是int类型，但长度为6的数组，后者保存的元素是int类型，长度为3的数组，因此是不同类型。并不能从都是二维数组简单分类，也不能从最高维的类型看，而是去看一维数组保存的元素类型。
template<typename T1, typename T2> void inverse(T1* mat1, T2* mat2, int a, int b)
{
	int i = 0;
	for (; i < a; i++) {
		for (int j = 0; j < b; j++) {
			mat2[j][i] = mat1[i][j];
		}
	}
}
//注意，这里T1和T2并非int *[n]即数组指针，而是int[n]数组类型，譬如mat1首先是*即指针，其次，这个指针指向的类型是T1、T2，而T1、T2为数组
//思考，T1、T2可以直接声明为数组指针吗？优劣在哪？


//下面尝试使用统一类型，看是否能成功。
template<typename T> void inverse2(T* mat1, T* mat2, int a, int b)
{
	int i = 0;
	for (; i < a; i++) {
		for (int j = 0; j < b; j++) {
			mat2[j][i] = mat1[i][j];
		}
	}
}

void inverse3(int** mat1, int** mat2, int a, int b)
{
	int i = 0;
	for (; i < a; i++) {
		for (int j = 0; j < b; j++) {
			mat2[j][i] = mat1[i][j];
		}
	}
}
void inverse4(int(*mat1)[6], int(*mat2)[3], int a, int b)
{
	int i = 0;
	for (; i < a; i++) {
		for (int j = 0; j < b; j++) {
			mat2[j][i] = mat1[i][j];
		}
	}
}

template<typename T1, typename T2> void inverse5(T1 mat1, T2 mat2, int a, int b)
{
	int i = 0;
	for (; i < a; i++) {
		for (int j = 0; j < b; j++) {
			mat2[j][i] = mat1[i][j];
		}
	}
}

template<typename T> void inverse6(T mat1, T mat2, int a, int b)
{
	int i = 0;
	for (; i < a; i++) {
		for (int j = 0; j < b; j++) {
			mat2[j][i] = mat1[i][j];
		}
	}
}



template<typename T> void output(T* mat, int a, int b)
{
	int i = 0;
	for (; i < a; i++) {
		for (int j = 0; j < b; j++) {
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
}

//矩阵相乘，要求矩阵1的列数等于矩阵2的行数。
template<typename T1, typename T2> void multi(T1* mat1, T2* mat2, T2* result, int a, int b, int c)
{
	//a是矩阵1的行，b是矩阵1的列以及矩阵2的行，c是矩阵2的列

	int i = 0;
	for (; i < a; i++) {

		for (int k = 0; k < c; k++) {//ruslut矩阵的行跟从与矩阵1，列数跟从于矩阵2

			for (int j = 0; j < b; j++) {	//b是矩阵1的列，同时也是矩阵2的行
				result[i][k] += mat1[i][j] * mat2[j][k];

			}

		}
	}
}

int main2()
{
	int matrix1[3][6] = {
		8,10,12,23,1,3,
		5,7,9,2,4,6,
		34,45,56,2,4,6
	};
	int middle[6][3] = {};
	int martix2[3][4] = {
		3,2,1,0,
		-1,-2,9,8,
		7,6,5,4
	};
	int result[6][4] = {};

	//inverse(matrix1, middle, 3, 6);
	//inverse2(matrix1, middle, 3, 6);结果不能通过编译，因为函数模板参数列表并不认为matrix1和matrix1属于同一类型，所以找不到相应的函数模板进行实例化。
	//inverse3(matrix1, middle, 3, 6);同样不能通过编译，因为matrix1作为实参和形参类型进行匹配时，matrix1的类型是int*[6]而非int**，不知道C是否也是如此

	//inverse4(matrix1, middle, 3, 6);//和类型相匹配，但是当matrix1和middle的类型发生变化时，必须修改形参的类型，因此可见函数模板的作用。

	inverse5(matrix1, middle, 3, 6);//发现可以使用数组指针作为模板参数，而不用必须使用数组，但从优劣来看，是从编程思想上来看的，模板要把特殊，非共性的提取出来，因此，矩阵变化的是一维数组的元素类型，而不是整体，所以要提取变量，即元素类型。
	//inverse6(matrix1, middle, 3, 6);不能通过编译，原因如inverse2，虽然同样作为数组指针，但类型不同。

	output(middle, 6, 3);
	cout << endl;
	multi(middle, martix2, result, 6, 3, 4);
	output(result, 6, 4);
	return 0;
}
