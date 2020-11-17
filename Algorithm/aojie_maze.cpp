#include <iostream>
#include <stack>           
using namespace std;       
                           
struct Offsets                     
{                                                     
    int a, b; // a和b是x,y方向的偏移                         
    // char *dir; // dir是方向 ISO C++11是不允许字符指针指向（存储）字符串
};                                                    
                                                      
Offsets direction[4] = {                              
    {-1, 0}, // 北：{-1, 0, "N"}                        
    {0, 1},  // 东：{0, 1, "E"}                             
    {1, 0},  // 南：{1, 0, "S"}                             
    {0, -1}, // 西：{0, -1, "W"}                            
};                                                        
// 栈结点定义                                                  
struct items                                              
{                                                          
    int x, y, dir;                                         
};                                                    
                                                      
int maze[15][15] =                                    
    {                                                 
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1},
        {1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1},
        {1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1},
        {1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1},
        {1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1},
        {1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1},         
        {1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 1},         
        {1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1},         
        {1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1},         
        {1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1},         
        {1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1},         
        {1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},         
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};        
// 解决迷宫问题的非递归算法（栈）                                             
void Path(int x, int y, int m, int n)                          
{ // (x,y)为入口坐标;(m,n)为出口坐标                                     
    int i, j, g, h, d;                                         
    stack<items> st; // 设置工作栈                                  
    items tmp;                                                 
    maze[x][y] = 1; // (x,y)是入口                                
    tmp.x = x, tmp.y = y;                                      
    tmp.dir = 0;  // 从N方向开始                                    
    st.push(tmp); // 把入口坐标进栈                                   
    while (!st.empty())                                        
    {                                                          
        // 当栈不空，一直走下去                                          
        tmp = st.top(); // 取栈顶元素                               
        st.pop();       // 退栈                                  
        i = tmp.x;                                             
        j = tmp.y;   // 取得当前位置坐标                               
        d = tmp.dir; // 方向                                     
        while (d < 4)                                          
        {                                                      
            // 找下一位置（g, h）                                     
            g = i + direction[d].a;                            
            h = j + direction[d].b;                            
            if (g == m && h == n)                              
            { // 到达出口                                          
                // 逆向输出路径                                      
                //Repush i,j                                   
                tmp.x = i;                                     
                tmp.y = j;                                     
                tmp.dir = d;                                   
                st.push(tmp);                                  
                cout << m << ", " << n << ", " << d << endl;   
                while (!st.empty())                            
                {                                              
                    // 输出栈中存的路径                                
                    tmp = st.top(); // 取栈顶元素                   
                    st.pop();       // 出栈                      
                    cout << tmp.x << ", " << tmp.y << ", " << tmp.dir << endl;
                }                                              
                return;                                        
            }                                                  
            // 未到达出口                                           
            if (maze[g][h] == 0 )                              
            {                                                  
                // 如果通且未被访问过                                   
                maze[g][h] = 1; // 标记为已访问过                     
                tmp.x = i;                                     
                tmp.y = j;                                     
                tmp.dir = d;  // 记忆已走过的位置和前进的方向                
                st.push(tmp); // 进栈                            
                i = g;                                         
                j = h;                                         
                d = 0; // 移动到（g,h）,再次向各个方向试探                   
            }                                                  
            else                                               
            {                                                  
                d++; // 试探下一个方向;                               
                g = i;                                         
                h = j;                                         
            }                                                  
        }                                                      
    }                                                          
    cout << "没找到从入口到出口的路径!" << endl;                           
}                                                              
                                                               
int main()                                                     
{                                                              
    int i, j, x, y, m, n;                                      
    x = y = 1;                                                 
    m = n = 13;                                                
    Path(x, y, m, n); // 调用求解迷宫问题的非递归算法                        
    return 0;                                                  
}                                                              