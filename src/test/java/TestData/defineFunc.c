#define FUNC(X,Y) (X * Y) * 2
FUNC(1,2)
FUNC(FUNC(1,2),3)
#FUNC(1,2)
FUNC("1,2",3)
/* comment FUNC(1,2) */
FUNC(1/* test*/,2)