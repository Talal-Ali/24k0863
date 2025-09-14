#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char *name;
    float rate;
    int len;
} Meta;

typedef struct {
    int w, h;
    double bw;
} Dev;

double **makeEng(int u, int c) {
    double **m = malloc(u * sizeof(double*));
    for(int i = 0; i < u; i++) {
        m[i] = calloc(c, sizeof(double));
    }
    return m;
}

Dev **makeDev(int u, int d) {
    Dev **m = malloc(u * sizeof(Dev*));
    for(int i = 0; i < u; i++) {
        m[i] = calloc(d, sizeof(Dev));
    }
    return m;
}

Meta **makeMeta(int c, int n) {
    Meta **m = malloc(c * sizeof(Meta*));
    for(int i = 0; i < c; i++) {
        m[i] = calloc(n, sizeof(Meta));
    }
    return m;
}

void setEng(double **m, int u, int c, double v) {
    m[u][c] = v;
}

void setDev(Dev **m, int u, int d, int w, int h, double b) {
    m[u][d].w = w;
    m[u][d].h = h;
    m[u][d].bw = b;
}

void setMeta(Meta **m, int c, int n, char *name, float rate, int len) {
    m[c][n].name = name;
    m[c][n].rate = rate;
    m[c][n].len = len;
}

void printEng(double **m, int u, int c) {
    printf("\nEngagement Matrix:\n");
    for(int i = 0; i < u; i++) {
        for(int j = 0; j < c; j++) {
            printf("%.2f ", m[i][j]);
        }
        printf("\n");
    }
}

void printDev(Dev **m, int u, int d) {
    printf("\nDevice Settings:\n");
    for(int i = 0; i < u; i++) {
        for(int j = 0; j < d; j++) {
            printf("User %d, Device %d: %dx%d, BW: %.1f\n", 
                   i, j, m[i][j].w, m[i][j].h, m[i][j].bw);
        }
    }
}

void printMeta(Meta **m, int c, int n) {
    printf("\nContent Metadata:\n");
    for(int i = 0; i < c; i++) {
        for(int j = 0; j < n; j++) {
            if(m[i][j].name) {
                printf("Category %d, Content %d: %s, Rate: %.1f, Length: %d\n", 
                       i, j, m[i][j].name, m[i][j].rate, m[i][j].len);
            }
        }
    }
}

void freeEng(double **m, int r) {
    for(int i = 0; i < r; i++) {
        free(m[i]);
    }
    free(m);
}

void freeDev(Dev **m, int r) {
    for(int i = 0; i < r; i++) {
        free(m[i]);
    }
    free(m);
}

void freeMeta(Meta **m, int r) {
    for(int i = 0; i < r; i++) {
        free(m[i]);
    }
    free(m);
}

int main() {
    int users = 3;
    int cats = 2;
    int devs = 2;

    double **eng = makeEng(users, cats);
    Dev **dev = makeDev(users, devs);
    Meta **meta = makeMeta(cats, 2);

    setEng(eng, 0, 0, 0.9);
    setEng(eng, 0, 1, 0.8);
    setEng(eng, 1, 0, 0.7);
    setEng(eng, 1, 1, 0.6);

    setDev(dev, 0, 0, 1920, 1080, 5.0);
    setDev(dev, 0, 1, 3840, 2160, 15.0);
    setDev(dev, 1, 0, 1280, 720, 2.0);

    setMeta(meta, 0, 0, "Movie1", 4.5, 120);
    setMeta(meta, 0, 1, "Movie2", 4.0, 90);
    setMeta(meta, 1, 0, "Series1", 4.8, 45);

    printEng(eng, users, cats);
    printDev(dev, users, devs);
    printMeta(meta, cats, 2);

    freeEng(eng, users);
    freeDev(dev, users);
    freeMeta(meta, cats);

}