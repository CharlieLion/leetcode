# 0-9 构建 a+b =c 要求 数字使用且只用一次，要求 为xxx+yyy =zzzz
import struct
import numpy as np 
import time
import copy


def boolTrue(nums,label,n):
    # try:
    for i in range(n):
        x = int(nums%10)
        if(label[x]==0):
            return False
        nums = nums/10
        label[x]=0
    # except:
    #     return False
    return True

ans =[]
for a in range(1000):
    label = np.ones(10)
    if(boolTrue(a,label, 3)):
        # print('a=',a)
        for b in range(1000):
            _label = copy.deepcopy(label)
            if(boolTrue(b,_label, 3)):
                # print('b =',b)
                # print('a+b', a+b)
                label2 = copy.deepcopy(_label)
                if(boolTrue(a+b,label2,4)):

                    ans.append([a,b,a+b])
                    
                    
print(ans)
                
  