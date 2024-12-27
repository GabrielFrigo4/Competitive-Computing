win:
	gcc -Wl,--stack=268435456 -std=c17 -O2 main.c -o main
	main

win-run:
	main

win-del:
	del main.exe

win-clip:
	cat main.c | win32yank -i

unix:
	gcc -Wl,--stack=268435456 -std=c17 -O2 main.c -o main
	./main

unix-run:
	./main

unix-rm:
	rm main

unix-clip:
	cat main.c | wl-copy
