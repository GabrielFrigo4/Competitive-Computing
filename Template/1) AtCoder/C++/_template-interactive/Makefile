win:
	g++ -Wl,--stack=268435456 -std=c++23 -O2 main.cpp -o main -I ../../../
	main

win-run:
	main

win-del:
	del main.exe

win-clip:
	cat main.cpp | win32yank -i

unix:
	g++ -Wl,--stack=268435456 -std=c++23 -O2 main.cpp -o main -I ../../../
	./main

unix-run:
	./main

unix-rm:
	rm main

unix-clip:
	cat main.cpp | wl-copy
