#!python3

def  test(flag):

    if flag:
        yield  1
        yield  2
        yield  3
    else:
        pass

g1 = test(True)
g2 = test(False)

print(f"{g1=} {list(g1)=}")
print(f"{g2=} {list(g2)=}")
