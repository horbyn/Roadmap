/* PA 14/25, 看扣分相差 10+ 分, 基本就是思路错了 */
/*
 * 我以为题目给出的是 BST 的前序遍历序列让我判断是不是正序/反序 BST
 *     所以以下思路是"知前序序列判断是否 BST":
 *         因为是前序序列, 序列第一个元素必定是根。则对于正序(逆序) BST,
 *     其左子树均 ＜(≥) 根而右子树均 ≥(＜) 根, 所以序列中第一个出现 ≥(＜)
 *     根的结点便是右子树。利用这一特征可以对序列递归地进行左右子树的划分进
 *     而建树
 * 而题目实际的思路是给出的序列只是输入序列, 也就是顺序给出结点让你按 BST
 *     特性进行插入, 进入建树。那么思路就完全不同了(我感觉题目应该给得更明
 * 确一些, 比如应该将"Now given a sequence of integer keys, you are 
 * supposed to tell if..", 改为"Now given a sequence of INSERTION of
 * integer keys..")
 */
#include <iostream>
#include <vector>
using namespace std;

typedef struct node_t {
	int data;
	struct node_t* left, * right;
}node_t;

const int maxn = 1000;
int n;
int a[maxn];
vector<int > post;

/* 判断是否正序或反序的 BST: 若是正序则返回 1, 反序则返回 0, 若不是 BST 则返回 -1 */
int judge_bst_seq() {
	int k = 0;
	if (a[1] < a[0]) {//第二个元素比第一个少则为正序 BST
		for (int i = 2; i < n; ++i) {
			if (a[i] >= a[0]) {//遇到第一个 ≥ 根结点即右子树
				k = i;
				break;
			}
		}
		for (; k < n; ++k) {//检查右子树是否满足所有结点均 ≥ 根结点
			if (a[k] < a[0])    break;
		}
		if (k == n)    return 1;//若是 BST 则能遍历到底
		else    return -1;			//否则中途退出必定不是 BST
	} else {//第二个元素比第一个少则为逆序 BST
		for (int i = 2; i < n; ++i) {
			if (a[i] < a[0]) {//遇到第一个 ＜ 根结点即右子树
				k = i;
				break;
			}
		}
		for (; k < n; ++k) {//检查右子树是否满足所有结点均 ＜ 根结点
			if (a[k] >= a[0])    break;
		}
		if (k == n)    return 0;//若是 BST 则能遍历到底
		else    return -1;			//否则中途退出必定不是 BST
	}
}

/* 后序遍历 */
void post_travesal(node_t *t) {
	if (t == NULL)    return;

	post_travesal(t->left);
	post_travesal(t->right);
	post.push_back(t->data);
}

/* 根据正序或逆序 BST 创建树: 其中数组范围是闭区间即 [h, t] */
node_t* create(int h, int t, bool f) {
	node_t* node = new node_t;
	node->data = a[h];

	if (h == t) {
		node->left = node->right = NULL;
		return node;
	}

	int k = h;
	for (int i = h + 1; i <= t; ++i) {
		if ((f == true && a[i] >= a[k])
			|| (f == false && a[i] < a[k])) {//正序且当前结点 ≥ 根, 或逆序且当前结点＜根
			k = i;//k 是左右子树分界
			break;
		}
	}
	node->left = create(h + 1, k - 1, f);
	node->right = create(k, t, f);
	return node;
}

int main() {
	/* 1. INPUT MODULE */
	cin >> n;
	for (int i = 0; i < n; ++i)    cin >> a[i];

	/* 2. MAIN LOGIC */
	int flag = judge_bst_seq();
	if (flag == -1) {
		cout << "NO";
		return 0;
	}
	node_t* tree = create(0, n - 1, (bool)flag);
	post_travesal(tree);

	/* 3. OUTPUT MODULE */
	cout << "YES\n" << post[0];
	for (int i = 1; i < (int)post.size(); ++i)    cout << " " << post[i];

	return 0;
}