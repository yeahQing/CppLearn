# :左边是目标文件右边是依赖文件
all: overrideUsing.o
	g++ overrideUsing.o -o main

# 自动化变量
# main: overrideUsing.o
# 	g++ $^ -o $@

OBJ=overrideUsing.o

main:${OBJ}
	g++ -o main ${OBJ}


# main: overrideUsing.o
# 	g++ overrideUsing.o -o main
# overrideUsing.o: overrideUsing.cpp
# 	g++ -c overrideUsing.cpp -o overrideUsing.o

.PHONY: clean
clean:
	rm *.o main