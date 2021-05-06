#include <bits/stdc++.h>
using namespace std;
#define maxn 60000
#define size 784 // 图片大小
#define learning_num 1000
#define learning_times 200
#define test_num 100
inline void read(int &a) // 快速读入
{
    char c = getchar();
    while (c < '0' || c > '9')
        c = getchar();
    while (c >= '0' && c <= '9')
    {
        a = (a << 1) + (a << 3) + c - '0';
        c = getchar();
    }
}

inline const double Sigmoid(double x) // Sigmoid
{
    return 1.0 / (1 + exp(-x));
}

inline const double Dif_Sigmoid(double x) // Sigmoid导数
{
    return Sigmoid(x) * (1.0 - Sigmoid(x));
}

struct Fig // 图片
{
    int l;                       // 标签
    double label[10], vec[size]; // 标签 向量
    void read_fig()              // 读入一个图片
    {
        memset(label, 0, sizeof(label));
        read(l);
        label[l] = 1.0;                // 仅有标签项为1
        for (int i = 0; i < size; i++) // 将图像每一格转化为小于1的值，并转为向量形式
        {
            int x;
            read(x);
            vec[i] = double(x) / 400.0; // 图像格灰度值大约在200左右
        }
    }
} train_fig[60000], test_fig[10000];

struct NeuralNetworks // 神经网络
{
    double label[10];                            // 图像标签，除标签项为1外其余全为0
    double layer1[size], layer2[15], layer3[10]; // 初始层 隐藏层 输出层
    int layer4;
    double bias2[15], bias3[10];      // 隐藏层 输出层偏置
    double w1[size][15], w2[15][10];  // 初始层 隐藏层权值
    double loss;                      // 损失值
    inline const double rand_weight() // 随机生成一个-100到100的double型权值
    {
        return double(rand() % 2 | 1) * double(rand() % 100);
    }
    void init() // 初始设置权值为随机数
    {
        for (int i = 0; i < 15; i++) // 隐藏层
            bias2[i] = rand_weight();
        for (int i = 0; i < 10; i++) // 输出层
            bias3[i] = rand_weight();
        for (int i = 0; i < size; i++) // 初始层
            for (int j = 0; j < 15; j++)
                w1[i][j] = rand_weight();
        for (int i = 0; i < 15; i++) // 隐藏层
            for (int j = 0; j < 10; j++)
                w2[i][j] = rand_weight();
    }
    void transmit(Fig *f) // 根据初始层进行传播，传入一个样本数据
    {
        for (int i = 0; i < 10; i++) // 填充label
        {
            label[i] = f->label[i];
        }
        for (int i = 0; i < size; i++) // 填充输入层
            layer1[i] = f->vec[i];
        for (int i = 0; i < 15; i++) // 填充隐藏层
            layer2[i] = bias2[i];
        for (int i = 0; i < size; i++)
            for (int j = 0; j < 15; j++)
                layer2[j] += w1[i][j] * layer1[i];
        for (int i = 0; i < 15; i++)
            layer2[i] = Sigmoid(layer2[i]);
        for (int i = 0; i < 10; i++) // 填充输出层
            layer3[i] = bias3[i];
        for (int i = 0; i < 15; i++)
            for (int j = 0; j < 10; j++)
                layer3[j] += w2[i][j] * layer2[i];
        for (int i = 0; i < 10; i++)
            layer3[i] = Sigmoid(layer3[i]);
        layer4 = 0; // 填充答案
        for (int i = 0; i < 10; i++)
            if (layer3[i] > layer3[layer4]) // 取值最大的那一个
                layer4 = i;
    }
    void loss_function() // 计算损失函数
    {
        // loss = sigma (label[i]-layer[3])^2
        loss = 0;
        for (int i = 0; i < 10; i++) // 仍然逐项做差表示损失
            loss += (label[i] - layer3[i]) * (label[i] - layer3[i]);
    }
    void train(double x) // 使用x作为学习速率进行一轮学习
    {
        /*
        loss = sigma( (label[i]-layer[3])^2 )
        layer3[j] = sigmoid( sigma( layer2[i]*w2[i][j] ) + bias3[j] )
        layer2[j] = sigmoid( sigma( layer1[i]*w1[i][j] ) + bias2[j] )
        */
        double dif_layer1[size], dif_layer2[15], dif_layer3[10];
        // 初始层 隐藏层 输出层除去sigmoid关于loss偏导
        double dif_bias2[15], dif_bias3[10];     // 隐藏层 输出层偏置关于loss的偏导
        double dif_w1[size][15], dif_w2[15][10]; // 初始层 隐藏层权值关于loss的偏导
        double step_len = x;                     // 确定学习步长
        for (int i = 0; i < learning_num; i++)   // 逐个样本进行学习
        {
            transmit(&train_fig[i]);     // 进行传播
            loss_function();             // 计算损失
            for (int i = 0; i < 10; i++) // 计算dif_layer3
                dif_layer3[i] = Dif_Sigmoid(layer3[i]);
            for (int i = 0; i < 10; i++) // 计算dif_bias3
                dif_bias3[i] = dif_layer3[i];
            for (int i = 0; i < 15; i++)
                for (int j = 0; j < 10; j++) // 计算dif_w2 i j 与 dif_layer2 i
                {
                    dif_w2[i][j] = dif_layer3[j] * layer2[i];
                    dif_layer2[i] = Dif_Sigmoid(dif_layer3[j] * w2[i][j]);
                }
            for (int i = 0; i < 15; i++) // 计算dif_bias2
                dif_bias2[i] = dif_layer2[i];
            for (int i = 0; i < size; i++)
                for (int j = 0; j < 15; j++) // 计算dif_w1 i j 与 dif_layer1 i
                {
                    dif_w1[i][j] = dif_layer2[j] * layer1[i];
                    dif_layer1[i] = Dif_Sigmoid(dif_layer2[j] * w1[i][j]);
                }
            // 更新权值与偏置
            for (int i = 0; i < 10; i++) // 更新bias3
                bias3[i] -= dif_layer3[i] * step_len;
            for (int i = 0; i < 15; i++)
                for (int j = 0; j < 10; j++) // 更新w2 i j
                    w2[i][j] -= dif_w2[i][j] * step_len;
            for (int i = 0; i < 15; i++) // 更新bias2
                bias2[i] -= bias2[i] * step_len;
            for (int i = 0; i < size; i++)
                for (int j = 0; j < 15; j++) // 更新w1 i j
                    w1[i][j] -= dif_w1[i][j] * step_len;
        }
    }
} N;

void Read_data() // 读入所有所需图片
{
    freopen("fig_data1.txt", "r", stdin);
    for (int i = 0; i < learning_num; i++)
        train_fig[i].read_fig(); // 读入训练数据
    freopen("CON", "r", stdin);
    freopen("fig_data2.txt", "r", stdin);
    for (int i = 0; i < test_num; i++)
        test_fig[i].read_fig(); // 读入测试数据
    freopen("CON", "r", stdin);
}

int main()
{
    N.init();    // 初始化
    Read_data(); // 读入所有数据
    for (int i = 1; i <= learning_times; i++)
        N.train(0.4); // 学习权值
    double rate = 0;
    for (int i = 1; i <= test_num; i++)
    {
        N.transmit(&test_fig[i]);
        if (N.layer4 == test_fig[i].l)
            rate += 1.0;
    }
    rate = rate * 100.0 / test_num;
    printf("accuracy rario: %d%\n", int(rate));
    return 0;
}
