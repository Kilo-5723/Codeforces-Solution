from sys import stdout, exit

closer = ""
further = ""
flg = False


def submit(x, y):
    print(x, y)
    stdout.flush()
    s = input()
    if s[-1] == '!':
        exit(0)
    if flg:
        if s == closer:
            return -1
        if s == further:
            return 1
        return 0
    else:
        return s


def init():
    global closer, further
    submit(0, 0)
    a = submit(1, 1)
    b = submit(0, 0)
    if a == b:
        submit(0, 1)
        submit(1, 0)
    closer = a
    further = b


def main():
    global flg
    init()
    flg = True
    lx = ly = 0
    rx = ry = 1000000
    while True:
        a = 0
        b = 0
        if rx > lx:
            a = submit(rx, ly)
        if ry > ly:
            b = submit(rx, ry)

        if a == 0:
            lx = rx = (lx+rx)//2
        elif a == 1:
            rx = (lx+rx+1)//2
        else:
            lx = (lx+rx)//2+1

        if b == 0:
            ly = ry = (ly+ry)//2
        elif b == 1:
            ry = (ly+ry+1)//2
        else:
            ly = (ly+ry)//2+1
        submit(lx, ly)


main()
