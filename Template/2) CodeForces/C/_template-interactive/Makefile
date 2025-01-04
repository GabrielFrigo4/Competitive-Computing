win:
	gcc -Wl,--stack=268435456 -std=c23 -O2 main.c -o main
	./main.exe

win-run:
	./main.exe

win-del:
	del "./main.exe"

win-clip:
	cat "./main.c" | win32yank -i

unix:
	gcc -Wl,-z,stack-size=268435456 -std=c23 -O2 main.c -o main
	./main

unix-run:
	./main

unix-rm:
	rm "./main"

unix-clip:
	cat "./main.cpp" | wl-copy