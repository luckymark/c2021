# 五子棋AI

## 界面

 `json`

为了好设计算法，用数组存储棋盘，从存储数组到打印的棋盘之间要通过转换函数

画棋盘，15*15 其要下在交界点上

column：60/4=15，分界线占一个字符，每个棋格是3个字符宽度

row：30/2=15，分界线在最上端

数组：0-16，0,16边界，棋盘是1-15，

（1,1）--（1,0）

gotoxy坐标和数组索引之间要调换，行--y，列--x

定位功能

## 算法

规则：五子棋15*15 

平衡先手优势，双3禁手，走五步换棋

### 暴力遍历看连子

全部遍历一遍，每个空位子看横竖撇捺，上下，左右，斜着分别比较选最大值k，k的最大值记为value，分别算电脑的value作为进攻值，玩家的value作为防守指

<font color='red'>！！</font>只考虑了连子，完全没考虑布局问题

判断输赢，只用看新下的这颗棋子的横竖撇捺有无成五活四



### max-min分数评估

伪代码

递归代码的魅力，简短的代码浓缩了很强的逻辑

注意这是一个递归，第一次输入搜索深度是4，然后再遇到minimax，depth-1，往下钻一层，最后钻到最深一层，返回当前评分，然后递归回溯，开始做min-max决策。

#### 博弈树

先不管决策，找到所有可能的情况，生成决策树，不能在最底层就选一个值最大的，因为双方决策的原因不可能达到

再考虑两个人的策略，从叶子结点开始从下往上做min-max决策，得到在考虑决策的情况下的最优走法

#### AB剪枝

α和β是有用节点的上下界，有用的节点一定在这个上下界之间，更新节点，节点P是min，P的父节点Q是max，P的下界α=Q的下界β；子节点R是max，P的上界=R的上界

判断

确定有用

更新父节点

#### 整盘棋评估

<font color='green'>表示整盘棋局</font>

15*15的二维数组

<font color='green'>怎么找出连子</font>

遍历？从每个点出发前后左右，很复杂

直接存储，横竖撇捺都存储成一维数组

<font color='green'>分数的表示和计算</font>

1.给一些情况打分

<font color='red'>？不是连着的</font>

- 成五，100000
- 活四, 10000
- 活三 1000
- 活二 100
- 活一 10

如果一侧被封死但是另一侧没有，则评分降一个档次，也就是死四和活三是相同的分

- 死四, 1000
- 死三 100
- 死二 10

2.综合考虑电脑和玩家

按照这个规则把棋盘上电脑的所有棋子打分，之和即为电脑的单方面得分 `scoreComputer`，然后对玩家的棋子同样打分 得到 `scoreHuman`。

`scoreComputer - scoreHuman` 即为当前局势的总分数

用一般的遍历方法

横竖斜各遍历一次，四次遍历会把一颗棋子算四次

遍历一次，找到棋子后横竖斜着检查，同一颗棋子会被计分很多次

##### 连子搜索

写八个方向变成用循环遍历八个方向简化代码

它沿着一条路一直走下去，直到走不动了然后返回上一个岔路口选择另一条路继续前进，一直如此，直到走完所有能够到达的地方！

沿着一条路径入栈

该节点没有连其它分支-->出栈，连了其他节点-->其他节点入栈

1.遍历棋局找到黑子，进入dfs

2.从这颗子向八个方向搜索，找到连子最多的方向记录得分，搜索过的就标记上，不再作为搜索的起点

3.遍历完八个方向之后，判断死活，记录这颗棋子已经被遍历过了，vis和board一致(vis在函数中初始化，每次评估都要先初始化为0)

总是开头的第一颗最先被遍历到吗?

BFS

队列结构

generator

是否有邻居，有邻居就进入评估函数，而不是进入评估之后再判断邻居

#### IDDFS

AI好像舍近取远，在耍我？

explain：AI只比较最终结果，并没有考虑到路径长短。随机选择能赢的走法，绕了远路

所以这里我们定义一个最优解的概念：分数最高的走法中路径最短的那一个走法。那么现在问题就是我们如何找到最优解。

iddfs是一种仿bfs，时间不比bfs慢很多，但是节省空间

dfs的搜索方式和递归程序结合起来理解

设置优先情况返回IDDFS没起作用，因为不是第一个搜索到杀棋的，也没有返回0

#### 启发式搜索

生成可搜索的空位+排序

搜索邻居位置

快排 qsort

## 学习能力

## bug list

- [x] 显示这里已经被下过了？

  移动光标的函数出问题，gotoxy对应位置与i，j的关系出错

- [x] AI一直下在一个地方

- [x] 两头都堵死了还往中间下？

  改进evaluate函数，如果两侧都被封死，除非是已有五颗棋子，否则连棋没有意义得分为0

- [x] 棋盘传参失败，想保护原有的棋盘，在做minmax时新建棋盘拷贝

- [x] is_neighbor必须要传参，进到决策树里面之后不能用board来判断；judge_winner也要传参

- [x] 左边边界有bug，判断边界出错，clearlocation的时候被清除了

  如果坐标出现负值，光标就会在原来的位置，不移动

  给clearlocation加上范围

- [x] 已经有活四不继续下了，对方有活四了不堵

  1）evaluate中有连成五就不用再看头尾是否堵死了，把成五的分值加到最最大

  2）minmax函数中加上成五就直接退出-->迭代加深
  
  


## To-do list

- [x] 实现判断输赢

  用分数判断？利用评估中的结果剪短时间

  从新下的这颗棋子开始遍历搜索

- [x] 要怎么遍历棋盘，活一被重复算了？

  DFS，八个方向上连子最多的记分，而且这些子不再重复做起点搜索

- [x] 遍历的边界？

  用3表示wall

- [x] 判断有无邻居，边界怎么算

- [x] 奇数层是min，evaluate要相减

- [ ] 堵的时候隔了一颗棋子  判断死活value不用+1

- [x] 设置一些优先情况

- [x] 悔棋功能

- [ ] 完善人机对战功能和界面

- [ ] 启发式搜索

  生成空位置能不能仅生成一次

  


## 项目感悟

多文件

头文件中声明全局变量（extern），声明函数，不要在头文件中定义，会在link时重定义报错

分解问题，to-do list

程序的高级性

完备性：特殊情况的处理，边界

大项目慎用全局变量

项目的模块化拆解

之前评估函数的基础

瓶颈

![image-20210611164858685](D:\应用软件\Typora2\Typora\typora-user-images\image-20210611164858685.png)

![image-20210611162646865](D:\应用软件\Typora2\Typora\typora-user-images\image-20210611162646865.png)

![image-20210523192853958](D:\应用软件\Typora2\Typora\typora-user-images\image-20210523192853958.png)

![image-20210523121456857](D:\应用软件\Typora2\Typora\typora-user-images\image-20210523121456857.png)

![image-20210523094842624](D:\应用软件\Typora2\Typora\typora-user-images\image-20210523094842624.png)

![image-20210523102221522](D:\应用软件\Typora2\Typora\typora-user-images\image-20210523102221522.png)

已有活四却没有继续下，evaluate函数的估分方式有问题

![image-20210523121706279](D:\应用软件\Typora2\Typora\typora-user-images\image-20210523121706279.png)

在min_max里加上优先情况，可能被剪枝剪掉了

![image-20210523101848152](D:\应用软件\Typora2\Typora\typora-user-images\image-20210523101848152.png)

![image-20210606193743892](D:\应用软件\Typora2\Typora\typora-user-images\image-20210606193743892.png)

![image-20210608132439531](D:\应用软件\Typora2\Typora\typora-user-images\image-20210608132439531.png)中间留空电脑选择了延长自己的活三

```c
function alphabeta_minmax(node, depth, α, β, Player)         
    if  depth = 0 or node is a terminal node//递归终止条件，搜索到最深一层就停止搜索，返回评估
        return the heuristic value of node
    if  Player = MaxPlayer //判断是玩家还是AI做决策，AI决策则为max层，玩家决策则为min层
        //极大节点
        for each child of node//极小节点 
            α := max(α, alphabeta(child, depth-1, α, β, not(Player) ))//极大节点
            //孩子节点的α，β继承自父节点  
            if β ≤ α 
            // 该极大节点的值>=α>=β，该极大节点后面的搜索到的值肯定会大于β，因此不会被其上层的极小节点所选用了。对于根节点，β为正无穷
                break                             (* Beta cut-off *)
        return α
    else // 极小节点
        for each child of node // 极大节点
            β := min(β, alphabeta(child, depth-1, α, β, not(Player) )) // 极小节点
            if β ≤ α // 该极大节点的值<=β<=α，该极小节点后面的搜索到的值肯定会小于α，因此不会被其上层的极大节点所选用了。对于根节点，α为负无穷
                break                             (* Alpha cut-off *)
        return β 
(* Initial call *)
alphabeta(origin, depth, -infinity, +infinity, MaxPlayer)
```

```c
int minMax_AB(int depth, int me, int Alpha, int Beta, int tmp_board[][L + 2])
//分数传递,t为1表示红棋，为2表示白棋,调用时Alpha，Beta赋为NGIF,PTIF
{
    int i, j;
    int c[L + 2][L + 2];
    int minmax;
    int rival;
    Tree tree;
    tree.Alpha = Alpha;
    tree.Beta = Beta;
    tree.X = 0;
    tree.Y = 0;
    if (me == 1)
        rival = 2;
    else
        rival = 1;
    if (depth == 0 || judge_winner(tree.X, tree.Y, me) == me)
        return evaluate(me, tmp_board) - evaluate(rival, tmp_board);
    if (depth % 2 == 0)//判断是min层还是max层,偶数是min层
        if (depth == 0 || judge_winner(tree.X, tree.Y, me) == me)
            return evaluate(me, tmp_board) - evaluate(rival, tmp_board);
    if (depth % 2)//判断是min层还是max层,奇数是min层
    {
        for (i = 1;i < L + 1;i++)
            for (j = 1;j < L + 1;j++)
            {
                if (!board[i][j] && neighbor(i, j) && tree.Alpha < tree.Beta)
                    if (!tmp_board[i][j] && neighbor(i, j) && tree.Alpha < tree.Beta)
                    {
                        memcpy(c, tmp_board, sizeof(int) * L * L);//更新棋盘
                        c[i][j] = me;
                        minmax = minMax_AB(depth - 1, rival, tree.Alpha, tree.Beta, c);
                        if (judge_winner(i, j, white) == white && depth == rank - 1)
                            //优先情况：对方已经有活四就必须堵

                        {
                            AI_x = j;
                            AI_y = i;
                            return 0;
                        }
                        minmax = minMax_AB(depth - 1, rival, tree.Alpha, tree.Beta, c);
                        c[i][j] = 0;
                        if (minmax < tree.Beta)
                        {
                            tree.Beta = minmax;
                            tree.X = j;
                            tree.Y = i;
                            if (tree.Alpha >= tree.Beta)
                                return tree.Alpha;//α剪枝，抛弃后续节点
                        }
                    }
            }
        return tree.Beta;
    }
    else
    {
        for (i = 1;i < L + 1;i++)
            for (j = 1;j < L + 1;j++)
            {
                if (!board[i][j] && neighbor(i, j) && tree.Alpha < tree.Beta)
                    if (!tmp_board[i][j] && neighbor(i, j) && tree.Alpha < tree.Beta)
                    {
                        memcpy(c, tmp_board, sizeof(int) * L * L);
                        //用一个新的数组表示棋盘，以免破坏原棋盘
                        c[i][j] = me;
                        minmax = minMax_AB(depth - 1, rival, tree.Alpha, tree.Beta, c);
                        if (judge_winner(i, j, red) == red && depth == rank)
                            //优先情况：自己已经有活四就必须接着下
                        {
                            AI_x = j;
                            AI_y = i;
                            return 0;
                        }
                        minmax = minMax_AB(depth - 1, rival, tree.Alpha, tree.Beta, c);
                        c[i][j] = 0;
                        if (minmax > tree.Alpha)
                        {
                            tree.Alpha = minmax;
                            tree.X = j;
                            tree.Y = i;
                            if (tree.Alpha >= tree.Beta)
                                return tree.Beta;//α剪枝，抛弃后续节点
                        }
                    }
            }
        AI_x = tree.X;
        AI_y = tree.Y;
        return tree.Alpha;
    }
}
```

![image-20210613213456813](D:\应用软件\Typora2\Typora\typora-user-images\image-20210613213456813.png)

