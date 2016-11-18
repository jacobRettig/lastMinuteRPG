from __future__ import print_function
from subprocess import check_call
from fnmatch import filter as fnfilter
from os import walk, remove
from os.path import join, isfile
from time import time

if __name__ == '__main__':
    rootDir = '.\\'

    pngs = set()
    for root, dirnames, filenames in walk(rootDir):
        for filename in fnfilter(filenames, '*.png'):
            pngs.add(join(root, filename))
    print('found {} png files in root directory {} to convert to webp'.format(len(pngs), rootDir))

    percentage = ''
    tStart = time()
    i = 0
    for png in pngs:
        print('{b}{s}{b}'.format(b='\b'*len(percentage), s=' '*len(percentage)), end='')
        percentage = '{}/{} ({:.1f}%) png files converted webp'.format(i, len(pngs), 100.0*i/len(pngs))
        print(percentage, end='')
        if not isfile('{}webp'.format(png[:-3])):
           check_call(['magick', 'mogrify', '-format', 'webp', png])
        i += 1

    print('\ndeleteing all pngs')
    for png in pngs:
        remove(png)
    print('Finished deleted all of the original png files')
