#pragma once
#include<iostream>

#ifdef ONLINE_JUDGE
#define debug(x) void(0)
#else
#define debug(x) cerr << __LINE__ << " : " << #x << " = " << (x) << endl
#endif