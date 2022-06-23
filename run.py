import os
import sys
import shutil

if __name__ == '__main__':
    if len(sys.argv) != 3:
        print("usage: python run.py [luogu|leetcode|openjudge] ${problem}")
        sys.exit(-1)
    
    
    d = sys.argv[1] + '/' + sys.argv[2]
    if os.path.exists(d):
        print("already exist")
        sys.exit(0)

    os.mkdir(d)
    shutil.copyfile('template.cpp', d + '/' + sys.argv[2] + '.cpp')
    open(d + '/' + sys.argv[2] + '.md', 'w')
    open(d + '/in.txt', 'w')
    open(d + '/out.txt', 'w')