void printTempMat(int m, int n);
void printTempVec(int n);
void transposeMat(float* A, int m, int n);
void normalizeVec(float* v, int n);
float calculateLen(float* v, int n);
void scaleMat(float* A, int m, int n, float c);
int multiplyMat(float* A, int m, int n, float* B, int l, int k);
int addMat(float* A, int m, int n, float* B, int l, int k);
void getTempMat(float* A, int m, int n); 