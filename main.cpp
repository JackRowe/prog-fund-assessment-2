#include "main.h"

int main()
{
    outputFile("grid.txt", { 0,0 });
    outputFile("menu.txt", { 14, 0 });
    outputFile("x.txt", outputPositions[1]);
    outputFile("o.txt", outputPositions[8]);
    setOuputCursorPosition({ 10,11 });
}

// TIC TAC TOE
/*

\/ /\
/\ \/

    |    |
 \/ | /\ | /\
 /\ | \/ | \/
____|____|____
    |    |
 \/ | /\ | /\
 /\ | \/ | \/
____|____|____
    |    |
 \/ | /\ | /\
 /\ | \/ | \/
    |    |

    |    |
 1  | 2  | 3
    |    |
____|____|____
    |    |
 4  | 5  | 6
    |    |
____|____|____
    |    |
 7  | 8  | 9
    |    |
    |    |

*/