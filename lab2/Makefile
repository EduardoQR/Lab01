test: solve.c hybrid.c
	gcc -I$(PYTHONPATH) -std=c99 -o test solve.c hybrid.c -l$(PYTHONVERSION) -lm
PYTHONVERSION=python2.7
PYTHONPATH=/usr/include/$(PYTHONVERSION)
