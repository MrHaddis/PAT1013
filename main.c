#include<stdio.h>
#include <limits.h>
#include<math.h>

//MrHaddis
//https://github.com/MrHaddis/PAT1013

int main() {
    //定义m 和 n
    int m = 0, n = 0;
    //获取输入
    scanf("%d%d", &m, &n);
    //边界条件
    if (m > n && m < 0 && n > 10000) {
        return 0;
    }
    int j;
    //第多少个素数的下标
    int count = 0;
    //判断是否换行的
    int number = 0;
    //这里循环到int最大值
    //通过m n 去中断
    for (int i = 2; i < INT_MAX; i++) {
        //开根算素数
        for (j = 2; j <= sqrt(i); j++) {
            if (i % j == 0)
                break;
        }
        //这里的大于则是素数
        if (j > sqrt(i)) {
            //下标+1
            count++;
            //去判断是m和n吗
            if (count >= m && count <= n) {
                number++;
                //到10了要换行
                if (number == 10) {
                    printf("%d\n", i);
                    //然后重置计数器
                    number = 0;
                } else if (count < n) {
                    //这里是中间值的输出
                    printf("%d ", i);
                } else {
                    //这里代表count =n了 是我们要输出的最后位数了
                    printf("%d", i);
                    break;
                }
            } else if (count > n) {
                break;
            }
        }
    }
    return 0;
}