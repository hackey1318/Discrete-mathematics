#include<stdio.h>
int team[12][82];
int main() {
	FILE *input_fp, *output_fp;
	if ((input_fp = fopen("soccer.inp", "rt")) == NULL) {
		fprintf(stderr, "Can't open %s\n", "block.inp");
	}
	if ((output_fp = fopen("soccer.out", "wt")) == NULL) {
		fprintf(stderr, "Can't open %s\n", "block.out");
	}
	int testcase = 0;
	int n = 0, k = 0;
	int a = 0;
	int i = 0, j = 0, w = 0, o = 0;
	int away = 0, home = 0, score1 = 0, score2 = 0;
	int totaladd = 0, totalsub = 0, totaladdsub = 0;
	int addsub = 0;
	char enter = NULL;
	int max = 0;
	int t1 = 0, t2 = 0;
	int totalscore1 = 0, totalscore2 = 0;
	int place1 = 0, place2 = 0, finalnum = 1;
	fscanf(input_fp, "%d\n", &testcase);
	for (a = 0; a < testcase; a++) {
		fscanf(input_fp, "%d %d\n", &n, &k);
		for (i = 0; i < n; i++) {
			team[0][i] = i + 1;
		}
		for (o = 0; o < k * 2 * (n - 1); o++) {
			for (j = 0; j < 2 * (n - 1); j++) {
				fscanf(input_fp, "%d-%d %d %d%c", &away, &home, &score1, &score2, &enter);
				if (score1 > score2) {
					totalscore1 = 3;
					totalscore2 = 0;
				}
				else if (score1 < score2) {
					totalscore1 = 0;
					totalscore2 = 3;
				}
				else if (score1 == score2) {
					totalscore1 = 1;
					totalscore2 = 1;
				}
				for (w = 0; w < n; w++) {
					if (team[0][w] == away) {
						t1 = team[4][w];
						t2 = team[5][w];
						addsub = team[6][w];
						addsub = addsub + (score1 - score2);
						t1 = t1 + score1;
						t2 = t2 + score2;
						team[4][w] = t1;
						team[5][w] = t2;
						team[6][w] = addsub;
						t1 = 0, t2 = 0, addsub = 0;
						break;
					}
					else {
						continue;
					}
				}
				for (w = 0; w < n; w++) {
					if (team[0][w] == home) {
						t1 = team[1][w];
						t2 = team[2][w];
						addsub = team[3][w];
						addsub = addsub + (score2 - score1);
						t1 = t1 + score2;
						t2 = t2 + score1;
						team[1][w] = t1;
						team[2][w] = t2;
						team[3][w] = addsub;
						t1 = 0, t2 = 0, addsub = 0;
						break;
					}
					else {
						continue;
					}
				}
				if (team[4][away - 1] < team[1][home - 1]) {
					team[7][away - 1] = team[7][away - 1] + totalscore1;
					team[7][home - 1] = team[7][home - 1] + totalscore2;
				}
				else if (team[4][away - 1] > team[1][home - 1]) {
					team[7][away - 1] = team[7][away - 1] + totalscore1;
					team[7][home - 1] = team[7][home - 1] + totalscore2;
				}
				else if (team[4][away - 1] == team[1][home - 1]) {
					team[7][away - 1] = team[7][away - 1] + totalscore1;
					team[7][home - 1] = team[7][home - 1] + totalscore2;
				}
				if (enter == '\n') {
					break;
				}
			}
		}
		for (i = 0; i < n; i++) {
			totaladd = team[1][i] + team[4][i];
			totalsub = team[2][i] + team[5][i];
			totaladdsub = team[3][i] + team[6][i];
			team[9][i] = totaladdsub;
			team[8][i] = team[7][i];
			team[10][i] = team[9][i];
			team[11][i] = team[4][i];
		}
		for (i = 0; i < n; i++) {
			for (j = i; j < n; j++) {
				if (team[7][i] < team[7][j]) {
					max = team[7][i];
					team[7][i] = team[7][j];
					team[7][j] = max;
					place1 = team[9][i];
					team[9][i] = team[9][j];
					team[9][j] = place1;
					place2 = team[4][i];
					team[4][i] = team[4][j];
					team[4][j] = place2;
				}
				if (team[7][i] == team[7][j]) {
					if (team[9][i] < team[9][j]) {
						max = team[7][i];
						team[7][i] = team[7][j];
						team[7][j] = max;
						place1 = team[9][i];
						team[9][i] = team[9][j];
						team[9][j] = place1;
						place2 = team[4][i];
						team[4][i] = team[4][j];
						team[4][j] = place2;
					}
				}
				if (team[7][i] == team[7][j] && team[9][i] == team[9][j]) {
					if (team[4][i] < team[4][j]) {
						max = team[7][i];
						team[7][i] = team[7][j];
						team[7][j] = max;
						place1 = team[9][i];
						team[9][i] = team[9][j];
						team[9][j] = place1;
						place2 = team[4][i];
						team[4][i] = team[4][j];
						team[4][j] = place2;
					}
				}
			}
		}
		fprintf(output_fp, "Test Case #%d: ", a + 1);
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				if (team[8][i] == team[7][j]) {
					if (team[10][i] != team[9][j]) {
						continue;
					}
					else if (team[10][i] == team[9][j]&& team[11][i] != team[4][j]) {
						continue;
					}
					else if (team[10][i] == team[9][j] && team[11][i] == team[4][j]) {
						fprintf(output_fp, "%d ", j + 1);
						break;
					}
				}
			}
		}
		fprintf(output_fp, "\n");
		for (i = 0; i < 10; i++) {
			for (j = 0; j < 82; j++) {
				team[i][j] = 0;
			}
		}
	}
	fclose(input_fp);
	fclose(output_fp);
}