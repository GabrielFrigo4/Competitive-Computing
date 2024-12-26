win:
	gcc -std=c17 -O2 main.c -o main
	main < input.txt

win-run:
	main < input.txt

win-del:
	del main.exe

win-clip:
	cat main.c | win32yank -i

unix:
	gcc -std=c17 -O2 main.c -o main
	./main < input.txt

unix-run:
	./main < input.txt

unix-rm:
	rm main

unix-clip:
	cat main.c | wl-copy
