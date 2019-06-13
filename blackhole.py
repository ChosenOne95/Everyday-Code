# -*- coding: utf-8 -*-
"""
Created on Thu Jun 13 14:03:29 2019

@author: QIAN
"""
global limit
limit = 0
def blackhole(n):
    tmp = str(n)
    count = len(tmp)
    result = 0
    for i in range(count):
        result = result + int(tmp[i])*int(tmp[i])
    print("current result is {}".format(result))
    global limit
    limit = limit + 1
    if limit > 1000:
        return result
    blackhole(result)
    
if __name__ == "__main__":
    blackhole(input("enter a num:"))
    
