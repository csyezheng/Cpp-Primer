int f(const int, const int);
typedef decltype(f) fp;
inline int NumAdd(const int n1, const int n2) { return n1 + n2; }
inline int NumSub(const int n1, const int n2) { return n1 - n2; }
inline int NumMul(const int n1, const int n2) { return n1 * n2; }
inline int NumDiv(const int n1, const int n2) { return n1 / n2; }