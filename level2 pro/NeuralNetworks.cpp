#include <bits/stdc++.h>
using namespace std;
#define maxn 60000
#define size 784             // 图片大小
#define hidden_layer 2       // 隐藏层层数
#define learning_num 60000   // 学习样本数
#define hidden_num 20        // 隐藏层每层神经元数
#define learning_times 10000 // 学习代数
#define test_num 10000       // 测试样本数
inline void read(int &a)     // 快速读入
{
    a = 0;
    char c = getchar();
    while (c < '0' || c > '9')
        c = getchar();
    while (c >= '0' && c <= '9')
    {
        a = (a << 1) + (a << 3) + c - '0';
        c = getchar();
    }
    return;
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
            vec[i] = double(x) / 350.0; // 图像格灰度值大约在200左右
        }
    }
} train_fig[60000], test_fig[10000]; // 样本集 测试集

struct NeuralNetworks // 神经网络
{
    double label[10];                                                  // 图像标签，除标签项为1外其余全为0
    double layer1[size], layer2[hidden_layer][hidden_num], layer3[10]; // 初始层 隐藏层 输出层
    int layer4;
    double bias2[hidden_layer][hidden_num], bias3[10];             // 隐藏层 输出层偏置
    double w1[size][hidden_num], w2[hidden_layer][hidden_num][10]; // 初始层 隐藏层权值
    double loss;                                                   // 损失值
    inline const double rand_weight()                              // 随机生成一个权值
    {
        if (rand())
            return double(rand() % 1000) / 10000.0;
        else
            return -1.0 * double(rand() % 1000) / 10000.0;
    }
    inline const double rand_bias() // 随机生成一个偏置
    {
        if (rand())
            return double(rand() % 1000) / 100.0;
        else
            return -1.0 * double(rand() % 1000) / 100.0;
    }
    void init() // 初始设置权值为随机数
    {
        for (int k = 0; k < hidden_layer; k++) // 隐藏层
            for (int i = 0; i < hidden_num; i++)
                bias2[k][i] = rand_bias();
        for (int i = 0; i < 10; i++) // 输出层
            bias3[i] = rand_bias();
        for (int i = 0; i < size; i++) // 初始层
            for (int j = 0; j < hidden_num; j++)
                w1[i][j] = rand_weight();
        for (int k = 0; k < hidden_layer; k++) // 隐藏层
            for (int i = 0; i < hidden_num; i++)
                for (int j = 0; j < 10; j++)
                    w2[k][i][j] = rand_weight();
        for (int k = 0; k < hidden_layer; k++) // 隐藏层偏置
            for (int i = 0; i < hidden_num; i++)
                bias2[k][i] = rand_bias();
        for (int i = 0; i < 10; i++) // 输出层偏置
            bias3[i] = rand_bias();
    }
    void transmit(Fig *f) // 根据初始层进行传播，传入一个样本数据
    {
        for (int i = 0; i < 10; i++) // 填充label
            label[i] = f->label[i];
        for (int i = 0; i < size; i++) // 填充输入层
            layer1[i] = f->vec[i];
        for (int k = 0; k < hidden_layer; k++) // 填充隐藏层
            for (int i = 0; i < hidden_num; i++)
                layer2[k][i] = bias2[k][i];
        for (int i = 0; i < size; i++) // 填充第0层隐藏层
            for (int j = 0; j < hidden_num; j++)
                layer2[0][j] += w1[i][j] * layer1[i];
        for (int i = 0; i < hidden_num; i++)
            layer2[0][i] = Sigmoid(layer2[0][i]);
        for (int k = 1; k < hidden_layer; k++) // 填充其余隐藏层
            for (int i = 0; i < hidden_num; i++)
                for (int j = 0; j < hidden_num; j++)
                    layer2[k][j] += w2[k - 1][i][j] * layer2[k - 1][i];
        for (int k = 0; k < hidden_layer; k++)
            for (int i = 0; i < hidden_num; i++)
                layer2[k][i] = Sigmoid(layer2[k][i]);
        for (int i = 0; i < 10; i++) // 填充输出层
            layer3[i] = bias3[i];
        for (int i = 0; i < hidden_num; i++)
            for (int j = 0; j < 10; j++)
                layer3[j] += w2[hidden_layer - 1][i][j] * layer2[hidden_layer - 1][i];
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
        loss = 0.0;
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
        double dif_layer1[size], dif_layer2[hidden_layer][hidden_num], dif_layer3[10];
        // 初始层 隐藏层 输出层除去sigmoid关于loss偏导
        double dif_bias2[hidden_layer][hidden_num], dif_bias3[10];
        // 隐藏层 输出层偏置关于loss的偏导
        double dif_w1[size][hidden_num], dif_w2[hidden_layer][hidden_num][10];
        // 初始层 隐藏层权值关于loss的偏导
        double step_len = x;                   // 确定学习步长
        for (int i = 0; i < learning_num; i++) // 逐个样本进行学习
        {
            transmit(&train_fig[i]); // 进行传播
            loss_function();         // 计算损失
            memset(dif_layer2, 0, sizeof(dif_layer2));
            memset(dif_bias2, 0, sizeof(dif_bias2));
            for (int i = 0; i < 10; i++) // 计算dif_layer3
                dif_layer3[i] = 2 * (layer3[i] - label[i]) * Dif_Sigmoid(layer3[i]);
            for (int i = 0; i < 10; i++) // 计算dif_bias3
                dif_bias3[i] = dif_layer3[i];
            for (int i = 0; i < hidden_num; i++)
                for (int j = 0; j < 10; j++) // 计算dif_w2与dif_layer2第hidden_layer-1层
                {
                    dif_w2[hidden_layer - 1][i][j] = dif_layer3[j] * layer2[hidden_layer - 1][i];
                    dif_layer2[hidden_layer - 1][i] += dif_layer3[j] * w2[hidden_layer - 1][i][j] * Dif_Sigmoid(layer2[hidden_layer - 1][i]);
                }
            for (int k = hidden_layer - 2; k >= 0; k--)
                for (int i = 0; i < hidden_num; i++)
                    for (int j = 0; j < 10; j++) // 计算dif_w2与dif_layer2其余层
                    {
                        dif_w2[k][i][j] = dif_layer2[k + 1][j] * layer2[k][i];
                        dif_layer2[k][i] += dif_layer2[k + 1][j] * w2[k][i][j] * Dif_Sigmoid(layer2[k][i]);
                    }
            for (int k = hidden_layer - 2; k >= 0; k--) // 计算dif_bias2
                for (int i = 0; i < hidden_num; i++)
                    dif_bias2[k][i] = dif_layer2[k + 1][i];
            for (int i = 0; i < size; i++)
                for (int j = 0; j < hidden_num; j++) // 计算dif_w1 i j 与 dif_layer1 i
                {
                    dif_w1[i][j] = dif_layer2[0][j] * layer1[i];
                    dif_layer1[i] = dif_layer2[0][j] * w1[i][j] * Dif_Sigmoid(layer1[i]);
                }
            // 更新权值与偏置
            for (int i = 0; i < 10; i++) // 更新bias3
                bias3[i] -= dif_layer3[i] * step_len;
            for (int k = 0; k < hidden_layer; k++) // 更新w2 i j
                for (int i = 0; i < hidden_num; i++)
                    for (int j = 0; j < 10; j++)
                        w2[k][i][j] -= dif_w2[k][i][j] * step_len;
            for (int k = 0; k < hidden_layer; k++)
                for (int i = 0; i < hidden_num; i++) // 更新bias2
                    bias2[k][i] -= bias2[k][i] * step_len;
            for (int i = 0; i < size; i++)
                for (int j = 0; j < hidden_num; j++) // 更新w1 i j
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
    srand(time(NULL));
    N.init();    // 初始化
    Read_data(); // 读入所有数据
                 // printf("%lf\n", N.w1[1][1]);
    N.transmit(&train_fig[0]);
    for (int i = 1; i <= learning_times; i++)
        N.train(0.1); // 学习权值
    double ans = 0;
    for (int i = 0; i < test_num; i++) // 测试数据
    {
        N.transmit(&test_fig[i]);
        if (test_fig[i].l == N.layer4)
            ans += 1.0; // 测试正确
    }
    printf("%lf%\n", ans / learning_num * 100);
    return 0;
}
