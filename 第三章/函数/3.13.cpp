#include<iostream>
using namespace std;

static void move(char x, char y)
{
	cout << x << "->" << y << '\t';
}
//注意 递归的思想是从最后一个n 到倒数第二个n-1……到1，去思考规律，而非是从1……n-1思考到n，这是递推了。
//其次要注意函数本身定义的是什么行为？譬如这里就是一个宽泛的行为即，把n个盘子，从x借助t放到y上。从而一步步递推到把最上面的盘子该怎么放，再回归到“最后”一个盘子。
void hanoi(int n, char x, char t, char y)//n是第几个盘子，即序号,x是源，t是跳板，y是目的
{
	if (n == 1)//说明是最后一个盘子。但实际上是第一个盘子。，也就是相当于树的叶子般
		move(x, y);//此时不需要借助跳板，直接移动即可，这里也是递归终止条件，即实际上第一次执行的位置。

	//1、把第n-1个盘子，从x，借助y，移动到t。
	//2、把第n个盘子，从x，直接移动到t。
	//3、把第n-1个盘子，从t，借助x，移动到y。
	//关键要理解，借助这个动作为什么能成立。倒着推比如最后要把n放到c，那么就得先把n-1放到b，再把n-1放到c，但n-1上方还有n-2,要想把n-1放到b，就得先把n-2放到c，一步步向上，为什么能放（得满足大盘在下）？，
	//那么问题在于，当有俩个2盘子时，自然而然知道可以借助空盘子，那么为什么为n时还能借助呢？
	//因为我们是倒推，实际上并不是“始终是会保持一个柱子为空”，我们倒推是为了使得下一步的“前提”必须满足，为此一步步递推知道最终结束递推的条件能够满足。
	//所以只要一开始的条件能满足，那么下面的模式也都能满足。

	//借助另一个即可，因为x要给到y如果不是最后一个的话，就得把上面的盘子拿走，此时抽象为上面不管多少个盘子，只是定义要把上面的盘子全部拿走这个动作（不去管怎么拿走的），此时再去看，如果上面是多个
	//再把这个问题看作最下方的盘子和上面全部盘子的问题，而又可以知道如果是最后一个，直接给到目的即可，但如果不是则还是拿走这个动作，那么此时又变成n和n-1的关系，
	//如果到了最后，即找到最上方的盘子了，那么直接给到目的，不需要借助这个动作，而开始回归，第二个发现第一个动作已经执行，说明满足了可以直接拿走的条件，那么它也是一个1对1的动作，
	//由此继续往下，第三个发现第二个也执行完毕了，继续执行第三个自己。那么始终发现是最下方的盘子和其上面已经摆好了的盘子的运算关系。

	//换种方式理解，也是注意这个动作，是把n个盘子拿到另外一个柱子上，那么其实默认另一个柱子就是空的，或者说可用的，因为最终变化的还是x,y即起始和目的
	//只要这个动作完整的执行下来，中间的柱子是没有变化的，他只是一个tmp。那么只要一开始（递归终止条件处）第一个能够满足完整的执行了，那么第二个也可以执行，由此直到最后第n个动作
	//，哪怕在实际过程并非如此，但一开始便是这样抽象的，那么不停去执行这个动作时，一直是完整的，符合条件的，说到底还是要去理解上面的1、2、3点。

	//再具体，精华，得到一个结论，或者说递归里面的重点：就是要抽象出来一个动作，这个动作这里指的就是把n个盘子从一个柱子放到另一个柱子上，可以选择借助一个tmp柱子。
	//从而，为了把n个盘子放到另一个柱子上，要满足先把n-1个盘子放到另一个柱子上，可以发现还是要调用这个动作，但只是变了参数，说明要执行这个动作，得先执行这个动作的“前情提要”
	//用这个动作本身去定义动作，还是要注意n和n-1项的关系，他和递推很像，但是多了一点，就是之前递推的时候，n和n-1之间的关系不需要自身参与，像是第三人称，而递归就是第一人称。

	//抽象出来的这个动作，得能描述出和下一项直接的关系。


	//感觉下方的代码是在为上面开始行动规划路线般。实际上我们正常思路，也正是先移动最上方的盘子，再思考如何移动下方的盘子，而递归正是说明了最上方的盘子与其下面盘子的关系，该如何定义行动的，而他定义的路线和实际操作正好相反，他是从最后一个盘子向上定义行为。
	else
	{	//否则，要把上方的盘子移走。
		hanoi(n - 1, x, y, t);
		move(x, y);
		//再把跳板上的盘子移到目标位置。
		hanoi(n - 1, t, x, y);
	}
	//递归的递推和回归在这里的过程分别是：从第n个递推到第1个，再从第1个回归到最后。
}

int main13()
{
	hanoi(4, 'A', 'B', 'C');
	return 0;
}
