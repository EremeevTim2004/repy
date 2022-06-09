from random import randint

a = []
for i in range(10):
    a += [str(randint(0, 9))]
print(', '.join(a))