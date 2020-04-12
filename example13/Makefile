# 虽然file2.h包含file1.h，但是test.c用到了file1.c中的函数实现，因此依赖file1.c
test: test.o file2.o file3.o file1.o
	gcc -o test test.o file2.o file3.o file1.o

test.o: test.c file1.h file2.h file3.h
	gcc -c test.c

file1.o: file1.c file1.h
	gcc -c file1.c

file2.o: file2.c file2.h
	gcc -c file2.c

file3.o: file3.c file3.h
	gcc -c file3.c

.PHONY:clean
clean:
	rm -rf *.o
