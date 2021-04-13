#本knn仅仅实现将六万个手写数字进行分类，用KNN进行识别

from numpy import *
import matplotlib.pyplot as plt
from random import *
learning_num=60000 #学习样本数
K=10 #分类
N=60000 #总样本
data = load("mnist.npz")
x_train = data['x_train'] # 60000数据集
belong=[0 for i in range(N)]
# 0->5 1->0 2->4 3->1 4->9 5->2 6->1 7->3 8->1 9->4 10->3 11->5 12->3 13->6 14->1 15->7
y_train = data['y_train'] # 60000数据集
x_test = data['x_test'] # 10000数据集
y_test = data['y_test'] # 10000数据集

def classification(): #归类并判断是否归类成功
    global centre
    finish=True
    for i in range(0,learning_num): #确定归属
        previous_belong=belong[i] #保存之前的归属
        min_i=100000
        for j in range(0,10):
            distance=dis(fig[i],centre[j])
            if distance>min_i:
                belong[i]=j
                min_i=distance
        if belong[i]!=previous_belong: # 归属有变，说明未归类完成
            finish=False
    if finish==True: # 迭代结束
        return finish 
    num=[0 for k in range(0,10)] #每个簇的个体数
    centre=[[0 for k in range(28*28)] for k in range(0,10)] #每个簇清零
    for i in range(learning_num): #重新确定聚类中心
        num[belong[i]]+=1
        for j in range(28*28):
            centre[belong[i]][j]+=fig[i][j]
    for i in range(10):
        for j in range(28*28):
            centre[i][j]/=num[i]
    return finish # 迭代继续

def init_centre(): #初始化中心点
    for i in range(K):
        for j in range(0,28*28):
            centre[i].append(randint(0,1)) # 随机初始化起始点

def print_centre(): #打印中心点
    for i in range(10):
        print("1")
        show_fig(centre[i])
        print("")

def dis(a,b): #距离函数
    sum=0
    for i in range(0,28*28):
        sum+=(a[i]-b[i])**2
    return sum

def show_fig(a): # 在编译器中展示数据
    p=0
    for i in range(0,28):
        for j in range(0,28):
            if(a[p]>=0.5):
                print('*',end='  ')
            else:
                print(' ',end='  ')
            p+=1
        print("\n")


fig=[[0 for col in range(28*28)] for num in range(0,N)]
p=-1
for k in x_train: #学习x_train 中内容
    p+=1 #先训练四千个试试
    if p>learning_num:
        break
    c=0
    for i in range(0,28):
        for j in range(0,28):
            r=int(k[i][j]) # 将图像转为黑白
            if(r):
                fig[p][c]=1
            else:
                fig[p][c]=0
            c+=1

centre=[[] for i in range(K)]
init_centre()

while classification()==False:
    continue

print_centre()