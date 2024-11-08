#include <stdio.h>
#include <stdbool.h>

void distribuiCameras(const int N, const int M, const int K, const int matriz[N][M], int cameras[N], const int index);

void inputTest(int input[3]);
void inputMatriz(const int N, const int M, int matriz[N][M]);

void memorySet(const int n, int buffer[n], const int val);
void memoryCopy(const int n, const int in_buffer[n], int out_buffer[n]);
int memoryAccumulate(const int n, const int buffer[n]);
bool memoryOk(const int n, const int buffer[n]);

int main(void) {
	int input[3];
	inputTest(input);
	const int N = input[0], M = input[1], K = input[2];

	int matriz[N][M];
	inputMatriz(N, M, matriz);

	int cameras[N];
	memorySet(N, cameras, 0);

	distribuiCameras(N, M, K, matriz, cameras, 0);
	if (cameras[0] < 0) {
		printf("-1");
	}
	else {
		for (int i = 0; i < N; i++) {
			if (cameras[i] > 0)
				printf("%i ", i);
		}
	}
	return 0;
}

void distribuiCameras(const int N, const int M, const int K, const int matriz[N][M], int cameras[N], const int index) {
	int vigiada[M];
	memorySet(M, vigiada, 0);

	if (memoryAccumulate(N, cameras) == K) {
		for (int i = 0; i < N; i++) {
			if (cameras[i] <= 0)
				continue;
			for (int j = 0; j < M; j++) {
				vigiada[j] += matriz[i][j];
			}
		}
		if (memoryOk(M, vigiada)) {
			return memoryLayer(N, cameras);
		}
		else {
			return -1;
		}
	}
}

void inputTest(int input[3]) {
	scanf("%i %i %i", &input[0], &input[1], &input[2]);
}

void inputMatriz(const int N, const int M, int matriz[N][M]) {
	int i, j;
	for (i = 0; i < N; i++)
		for (j = 0; j < M; j++)
			scanf("%i", &matriz[i][j]);
}

void memorySet(const int n, int buffer[n], const int val) {
	int i;
	for (i = 0; i < n; i++)
		buffer[i] = val;
}

void memoryCopy(const int n, const int in_buffer[n], int out_buffer[n]) {
	int i;
	for (i = 0; i < n; i++)
		out_buffer[i] = in_buffer[i];
}

int memoryAccumulate(const int n, const int buffer[n]) {
	int i, ac = 0;
	for (i = 0; i < n; i++)
		ac += buffer[i];
	return ac;
}

bool memoryOk(const int n, const int buffer[n]) {
	int i;
	for (i = 0; i < n; i++)
		if (buffer[i] <= 0)
			return false;
	return true;
}
