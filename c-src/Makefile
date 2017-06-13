obj/posit_conv.o: posit_conv.cpp
	gcc -c -Wall -Werror -fpic posit_conv.cpp -o obj/posit_conv.o

obj/posit_extended.o: posit_extended.cpp
	gcc -c -Wall -Werror -fpic posit_extended.cpp -o obj/posit_extended.o

obj/posit_basics.o: posit_basics.cpp
	gcc -c -Wall -Werror -fpic posit_basics.cpp -o obj/posit_basics.o

obj/posit_err.o: posit_err.cpp
	gcc -c -Wall -Werror -fpic posit_err.cpp -o obj/posit_err.o

obj/posit_full.o: posit_full.cpp
	gcc -c -Wall -Werror -fpic posit_full.cpp -o obj/posit_full.o


obj/P8e0.o: P8e0.cpp
	gcc -c -Wall -Werror -fpic P8e0.cpp -o obj/P8e0.o

obj/P8e1.o: P8e1.cpp
	gcc -c -Wall -Werror -fpic P8e1.cpp -o obj/P8e1.o

obj/P8e2.o: P8e2.cpp
	gcc -c -Wall -Werror -fpic P8e2.cpp -o obj/P8e2.o

obj/P16e0.o: P16e0.cpp
	gcc -c -Wall -Werror -fpic P16e0.cpp -o obj/P16e0.o

obj/P16e1.o: P16e1.cpp
	gcc -c -Wall -Werror -fpic P16e1.cpp -o obj/P16e1.o

obj/P16e2.o: P16e2.cpp
	gcc -c -Wall -Werror -fpic P16e2.cpp -o obj/P16e2.o

obj/P32e0.o: P32e0.cpp
	gcc -c -Wall -Werror -fpic P32e0.cpp -o obj/P32e0.o

obj/P32e1.o: P32e1.cpp
	gcc -c -Wall -Werror -fpic P32e1.cpp -o obj/P32e1.o

obj/P32e2.o: P32e2.cpp
	gcc -c -Wall -Werror -fpic P32e2.cpp -o obj/P32e2.o

obj/P32e3.o: P32e3.cpp
	gcc -c -Wall -Werror -fpic P32e3.cpp -o obj/P32e3.o


build: obj/posit_conv.o obj/posit_extended.o obj/posit_basics.o obj/posit_err.o obj/posit_full.o obj/P8e0.o obj/P8e1.o obj/P8e2.o obj/P16e0.o obj/P16e1.o obj/P16e2.o obj/P32e0.o obj/P32e1.o obj/P32e2.o obj/P32e3.o
	gcc -shared -o libfastposit.so obj/posit_conv.o obj/posit_extended.o obj/posit_basics.o obj/posit_err.o obj/posit_full.o obj/P8e0.o obj/P8e1.o obj/P8e2.o obj/P16e0.o obj/P16e1.o obj/P16e2.o obj/P32e0.o obj/P32e1.o obj/P32e2.o obj/P32e3.o


test: test.cpp
	gcc -Wall -o test test.cpp -lstdc++ -lfastposit
	chmod +x test
	./test

.PHONY: install
install:
	cp ./libfastposit.so /usr/lib
	chmod +r /usr/lib/libfastposit.so

.PHONY: clean
clean:
	-rm *.so
	-rm obj/*.o
