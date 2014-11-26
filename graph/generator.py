import random
import sys,getopt

total = len(sys.argv)

try:
    options,args = getopt.getopt(sys.argv[1:],"n:e:t:")

except getopt.GetoptError as e:
    print (str(e))
    print "Usage: %s [-n nodes] [-e edges] [-t graph|digraph]" % sys.argv[0]
    sys.exit(2)

n = 10
e = 20

for o, a in options:
    if o == '-n':
        n = int(a)

    elif o == '-e':
        e = int(a)

    elif o == '-t':
        if a == "digraph":
            print "unidirecional"

        elif a == "graph":
            print "bidirecional"

        else:
            print "Usage: %s [-n nodes] [-e edges] [-t graph|digraph]" % sys.argv[0]
            sys.exit(2)

    else:
        print "Usage: %s [-n nodes] [-e edges]" % sys.argv[0]

for i in range(0,e):
    a=0
    b=0
    while a==b:
        a = random.randint(1,n+1)
        b = random.randint(1,n+1)

    print "%d %d" % (a,b)
