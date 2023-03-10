#ifdef ONLINE_JUDGE
#define debug(x) void(0)
#else
#define _GLIBCXX_DEBUG
#define debug(x) cerr << __LINE__ << " : " << #x << " = " << (x) << endl
#endif