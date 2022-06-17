import os
import shutil

if __name__ == '__main__':
    m = ['./leetcode', './luogu', './openjudge']
    for d in m:
        for path, dirs, files in os.walk(d, topdown=False):
            for file in files:
                os.mkdir(path + '/' + file[:-4])
                shutil.move(path + '/' + file, path + '/' + file[:-4])
