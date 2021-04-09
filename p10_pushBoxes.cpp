#include "p10_push.h"

int main()
{
    // init_hard_version();
    int to=0,now=1,x,y; //初始化输出一次
    while(task<=4)
    {
        switch(task)
        {
            case 1: freopen("round1.in","r",stdin); break;
            case 2: freopen("round2.in","r",stdin); break;
            case 3: freopen("round3.in","r",stdin); break;
            case 4: freopen("round4.in","r",stdin); break;
        }
        initconsolveScreenBuffer(x,y); Score=0;
        fclose(stdin); 
        now=1; to=5; show(output[now],x,y,to); now^=1;
        while(to=get_toward())
        {
            show(output[now],x,y,to);
            if(Score==End) 
                { n=n; break; }
            now^=1;
        }
        LPDWORD num=0;
        // coord.Y=n+3;
        WriteConsoleA(output[now],"\n",1,num,NULL);
        put_str(output[now],FG|FB|FI,"Congratulations!\n",1);
        if(task==4) break;
        Sleep(3000);
        task++;
    }
    put_str(output[now],FG|FB|FI,"YOU WIN!!!\n",1);
    Sleep(1000000);
    return 0;
}

// #：墙
// @：玩家位置
// $：箱子
// ?：目标地点
// %：已经得分

