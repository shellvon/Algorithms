/**
 * 二叉树是一种常用的数据结构。我们可以用大写的英文字母表示二叉树的节点。
 *   如下：
 *           B   
 *          /  \    
 *         /    \    
 *        C      A
 *                \
 *                 \
 *                  D
 *  对于二叉树，有前序、中序和后序三种遍历方式。
 *  先:
 *      从树根节点开始,往左边节点绕，当所有节点都绕完回到根节点，按照第1次经过的点就是先序:
 *          B(1)->C(1)->C(2)->C(3)->B(2)->A(1)->A(2)->D(1)->D(2)->D(3)->A(3)->B(3) ===>BCAD
 *  中:
 *      从树根节点开始,往左边节点绕，当所有节点都绕完回到根节点，按照第2次经过的点就是中序:
 *      对于上面的例子来看就是：
 *          CBAD
 *  后:
 *      从树根节点开始,往左边节点绕，当所有节点都绕完回到根节点，按照第3次经过的点就是中序:
 *      对于上面的例子来看就是：
 *          CDAB
 *  Warnnings:
 *      遍历的时候，假设了叶子节点有儿子，遍历经过的时候第一次到达C，然后会往左边儿子走，发现没有，就回来，这时第二次遇到C，
 *      然后往右边儿子走，这时也没有，又回来，第三次遇见C，所以上面的遍历顺序才是：[括号里面表示经过次数]
 *      B(1)->C(1)->C(2)->C(3)->B(2)->A(1)->A(2)->D(1)->D(2)->D(3)->A(3)->B(3)
 *      
 *  See:
 *      Wikipedia
 *  For exampe:
 *      1).BCAD CBAD -->CDAB
 *      2).ABDGKLRVWSXCEHMNFIOTUJPYQZ KGVRWLSXDBAMHNECTOUIFPYJZQ->KVWRXSLGDBMNHETUOIYPZQJFCA
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <map>
#define N 1000
using namespace std;
/**
 * C++ 获取后序遍历，慢~
 * @string  pre 前序
 * @string  ino 中序
 * @return     后序
 */
string fuck(string pre,string ino)
{
    if(pre.length()<=1)
        return pre;
    char node = pre[0];
    int index = ino.find(node);
    int len = pre.length();
    string left = fuck(pre.substr(1,index),ino.substr(0,index));
    string right=fuck(pre.substr(index+1,len-index-1),ino.substr(1+index,len-index-1));
    return left+right+node;
}
/**
 * the binary tree structure.
 */
struct tree
{
    struct tree* left;
    struct tree* right;
    char  elem;
};
/**
 * 对于二叉树，有前序、中序和后序三种遍历方式。 现在给你一棵二叉树的前序和中序遍历，请你求出这棵二叉树的后序遍历结果。
 * 
 * @char* pre  前序
 * @char* ino  中序
 * @int   len  长度
 */
void quik_fuck(char *pre,char *ino,int len)
{
    if(len==0)
        return;
    tree *node = new tree;
    node->elem = *pre;
    int i=0;
    for(; i<len&&ino[i]!=*pre; i++);
    quik_fuck(pre+1,ino,i);
    quik_fuck(pre+i+1,ino+1+i,len-i-1);
    printf("%c",node->elem);
}

int main()
{
    char pre[27],mid[27];
    while(~scanf("%s%s",pre,mid)){
        int len =strlen(mid);
        quik_fuck(pre,mid,len);
        printf("\n");
    }
    return 0;
}