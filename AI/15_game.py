import random
import time

l = [];

for i in range(15):
    l.append(i+1);

print();

for i in l:
    print(i, end = "\t");
    if i % 4 == 0:
        print("\n");

print();
