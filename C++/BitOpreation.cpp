/**
 * 代码在于演示思路，所以本身没管什么C++代码风格之类的问题。
 * 虽然后缀名是cpp.但是其实就是C方式完成的。 之所以不选择
 * Python做，可能是习惯吧。潜意识就替换到C/C++来了，无奈我
 * 创建了C++这个文件夹了。干脆就这么写了。所以代码风格不要吐
 * 槽我就是。
 *
 * 位操作是我认为比较重要的一点，而且这个容易错，许多人都对其
 * 望而却步。但是请相信不动手就没有什么可以学的好的～学位操作
 * 如此，学其他任何东西都是如此。
 * 位操作首先知道的是：一切是按位进行运算的。所以叫位操作，以下
 * 代码和注释希望能帮助所以学的不好的人。一般有以下6个位操作。
 * ------------------------------------------------
 *     操作符  功能           用法          运算规则
 *       ~      位求反     ~expr         0变1，1变0
 *       <<     左移       expr1 << expr2      -
 *       >>     右移       expr1 >> expr2      -
 *       &      位与       expr1 & expr2  位都为1时，结果才为1
 *       ^      位异或  expr1 ^ expr2  位相同为0，相异为1
 *       |      位或       expr1 | expr2  位都为0时，结果才为0
 * -------------------------------------------------
 * 位操作符的运算优先级比较低，因此尽量使用括号来确保运算顺序。
 * 另外位操作还有一些复合操作符，如&=、|=、 ^=、<<=、>>=。本处不展示。
 *
 * 具体请参考代码。
 */
#include <iostream>

/**
 * 获取给定的数字num的2进制形式在第position位置上的值.
 *
 * 思路：
 *      将数字1左移动position位,然后这个时候就会得倒形式如
 *      0010 0000,接着，对这个值和num进行&运算。这样就会把其他不是
 *      1的地方全部置换位0了。然后就是检查这个位是不是0了。
 *      比如13.第3位。先将1左移3位，就是0000 1000，和13:0000 1101
 *      进行&运算，得到0000 1000=>8，不为0，则i位就是1，否则就是0
 * 
 * @param  num          需要获取的数字
 * @param  position     需要获取的位置
 * @return              该位置上的值，0/1
 */
int get_bit(int num, int position){
    return (num & (1 << position)) != 0;
}


/**
 * 置位：
 *      设置给定的数字num的2进制形式在第position位置上的值为1
 *
 * 思路：
 *      将数字1左移动position位,然后这个时候就会得倒形式如0010
 *      0000,接着，对这个值和num进行|运算，因位该掩码除position
 *      位上的位均为0】这样就不会影响其他位置上的值。比如5.第3位。
 *      先将1左移3位，就是0000 1000，和5:00000101 进行|运算，得
 *      到0000 1101 => 13
 * 
 * @param  num          需要修改的数字
 * @param  position     需要修改的位置
 * @return              修改之后的值
 */
int set_bit(int num, int position){
    return num | (1 << position);
}


/**
 * 清零：
 *      设置给定的数字num的2进制形式在第position位置上的值为0
 *
 * 思路：
 *      将数字1左移动position位,然后这个时候就会得倒形式如0010
 *      0000,接着，对这个值执行～运算，得到11011111的值，然后对该
 *      位置进行&运算。这样只会修改position位置的值，不会影响其他
 *      位置上的值。比如13.第3位。先将1左移3位求反，就是1111 0111.
 *      【这个数就是-9】，和13:0000 1101 进行&运算，得0000 0101。
 *      是5
 * 
 * @param  num          需要修改的数字
 * @param  position     需要修改的位置
 * @return              修改之后的值
 */
int clear_bit(int num, int position){
    return num & (~(1 << position));
}


/**
 * 更新：
 *      修改给定的数字num的2进制形式在第position位置上的值为value
 *
 * 思路：
 *      参考clear_bit和set_bit的实现
 * 
 * @param  num          需要修改的数字
 * @param  position     需要获取的位置
 * @param  value        需要写入的值0/1
 * @return              修改之后的值
 */
int update_bit(int num, int position, int value){
    int mask = ~(1<<position);
    return (num & mask) | (value << position);
}


/**
 * 判断奇偶，普通思路为num%2==0
 * 思路：
 *      显然只有最后一位决定是否为奇偶
 *      
 * @param  num          需要判断的值
 * @return 
 */
int is_even(int num){
    return num & 1 == 0;
}


/**
 * 交换俩数。普通思路为零时变量作为桶来存放
 * 或者采用轴上的+，-来交替【可能溢出】
 * 
 * @param a            需要交换的数字a
 * @param b            需要交换的数字b
 */
void swap(int &a, int &b){
    if(a != b){
        a ^= b;
        b ^= a;
        a ^= b;
    }
}

/**
 * 俩数相加 位操作
 * 参见：
 *      http://www.geeksforgeeks.org/add-two-numbers-without-using-arithmetic-operators/
 *      
 * @param  a 待加数a
 * @param  b 待加数b
 * @return   相加之后结果
 */
int add(int a, int b){
    int carry = 0;
    while(b != 0){
        carry = a & b;
        a = a ^ b;
        b = carry << 1; 
    }
    return a;
}

/**
 * 统计将一个整数a修改为整数b时，需要修改多少个位
 * 思路见代码。
 * @param  a            数字a
 * @param  b            数字b
 * @return              统计结果
 */
int bit_swap_count(int a,int b){
    int cnt = 0;
    int tmp = a ^ b;
    for(tmp = 0; tmp != 0; tmp = tmp>>1){
        cnt += tmp & 1;
    }
    //another method
    /*
    while(tmp!=0){
        tmp = tmp&(tmp-1);
        cnt ++;
    }*/
    return cnt;
}

/**
 * 变换符号
 * 
 * @param  num          需要变换的数字
 * @return              变换之后
 */
int sign_reverse(int num){
    return ~num + 1;
}

/**
 * 
 * 未实现
 * 在一群重复数字中出现3找出只唯一出现一次的数字
 * 假设输入的array一定是正确的。
 * 参见：
 *      http://www.geeksforgeeks.org/find-the-element-that-appears-once/
 *      http://blog.csdn.net/morewindows/article/details/8214003
 * @param  array 需要查找的这数据
 * @param  size  数据大小
 * @return       找到的值
 */
int find_unique(int array[], int size){
    return 0;
}


/**
 * 检查某个数字是否为2的次方
 * 此题来自于让我解释num&(num-1)==0的意思。
 * 
 * 参见：
 *      http://www.geeksforgeeks.org/write-one-line-c-function-to-find-whether-a-no-is-power-of-two/
 *  
 * @param  num 带检查数字
 * @return     检查结果0/1
 */
int is_power_of_two(int num){
    return num && (num & (num - 1));
}


int main(int argc, char const *argv[])
{
    return 0;
}