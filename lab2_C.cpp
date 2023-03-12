//В игре в пьяницу карточная колода раздается поровну двум игрокам.

#include <iostream>
#include <queue>
using namespace std;
int main()
{
    int N = 10;
    int x;
    queue<int> a;
    queue<int> b;                        
    for (int i = 0; i < N / 2; i++) {
        cin >> x;
        a.push(x);
    }
    for (int i = 0; i < N / 2; i++) {
        cin >> x;
        b.push(x);
    }                                   
    int moves = 0;                      
    for (; !a.empty() && !b.empty() && moves <= 1000000; ++moves) {
        int ac = a.front(), bc=b.front();           
        a.pop(); b.pop();                           
        queue<int>* win = (ac == 0 && bc == N - 1) ? &a :   
            (bc == 0 && ac == N - 1) ? &b :
            (ac > bc) ? &a : &b;
        win->push(ac); win->push(bc);       
    }
    if (a.empty()) cout << "second " << moves;
    else if (b.empty()) cout << "first " << moves;  
    else cout << "botva";          
    return 0;
}

