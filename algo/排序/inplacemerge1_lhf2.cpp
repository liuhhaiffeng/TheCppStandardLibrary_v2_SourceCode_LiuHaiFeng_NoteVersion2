// 转：C++学习【原创】归并排序（inplace_merge函数的应用）
// 
// inplace_merge函数的作用和merge函数差不多，只不过是在一个容器中进行归并。
// 函数参数：inplace_merge(first,mid,last,compare);//将[first,mid) 和 [mid,last)
// 这两个区间进行归并成一个有序序列。
// 
// 注意：[first,mid)和[mid,last)都要呈升序或降序排列！
// 
// 还记得归并排序的写法么？归并排序利用了分治的思想，将一个容器分割，
// 然后再将它们一个个合并起来，最后形成一个有序的序列。归并排序的核心
// 代码就在于合并两个序列，不过STL的开发人员已经为我们完成了，我们直接调用就可以了。
// 
// 例题：给你n个学生的信息，根据它们的分数从小到大排序，注意：如果遇到分数相等的同学，
// 按照原来的顺序排列。
// 因为归并排序是一个稳定的排序，所以我们不需要理睬注意事项。
// 代码：

#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;
struct student
{
    string name;
    int score;
    bool operator <(const student &t) const
    {
        return score<t.score;
    };
};
typedef vector <student> ::iterator Iter;
vector <student> V;

void merge_sort(Iter a,Iter b)
{
    if(a>=b) return ;
    Iter mid=((a-V.begin())+(b-V.begin()))/2+V.begin();
    merge_sort(a,mid);
    merge_sort(mid+1,b);
    inplace_merge(a,mid,b,less<student>());
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        student t;
        cin>>t.name>>t.score;
        V.push_back(t);
    }
    merge_sort(V.begin(),V.end());
    for(Iter it=V.begin();it!=V.end();it++)
        cout<<it->name<<" "<<it->score<<endl;
    return 0;
}
