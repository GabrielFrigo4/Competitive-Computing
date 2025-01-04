win:
	gcc -Wl,--stack=268435456 -std=c23 -O2 main.c -o main
	cat "./input.txt" | "./main.exe"

win-run:
	cat "./input.txt" | "./main.exe"

win-del:
	del "./main.exe"

win-clip:
	cat "./main.c" | win32yank -i

unix:
	gcc -Wl,-z,stack-size=268435456 -std=c23 -O2 main.c -o main
	cat "./input.txt" | "./main"

unix-run:
	cat "./input.txt" | "./main"

unix-rm:
	rm "./main"

unix-clip:
	cat "./main.cpp" | wl-copy