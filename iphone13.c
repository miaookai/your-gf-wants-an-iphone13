/*========================================
 *    iphone13.h: version 0.0.1
 *========================================
 */

#include <curses.h>
#include <signal.h>
#include <unistd.h>
#include "iphone13.h"

int
add_iphone13(int x);

int
my_mvaddstr(int y, int x, char *str);

int
my_mvaddstr(int y, int x, char *str) {
    for ( ; x < 0; ++x, ++str)
        if (*str == '\0')  return ERR;
    for ( ; *str != '\0'; ++str, ++x)
        if (mvaddch(y, x, *str) == ERR)  return ERR;
    return OK;
}

int
main() {
    int x;

    initscr();
    signal(SIGINT, SIG_IGN);
    noecho();
    curs_set(0);
    nodelay(stdscr, TRUE);
    leaveok(stdscr, TRUE);
    scrollok(stdscr, FALSE);

    for (x = COLS - 1; ; --x) {
        if (add_iphone13(x) == ERR) break;
        getch();
        refresh();
        usleep(40000);
    }

    mvcur(0, COLS - 1, LINES - 1, 0);
    endwin();

    return 0;
}


int
add_iphone13(int x) {
    static char * your[LOGOHEIGHT] = { YOUR0, YOUR1, YOUR2, YOUR3, YOUR4, YOUR5, YOUR6, YOUR7};

    static char * wants[LOGOHEIGHT] = { WANTSAN1, WANTSAN2, WANTSAN3, WANTSAN4, WANTSAN5, WANTSAN6, WANTSAN7, WANTSAN8 };

    static char * iphone[LOGOHEIGHT] = { IPHONE131, IPHONE132, IPHONE133, IPHONE134, IPHONE135, IPHONE136, IPHONE137, IPHONE138 };

    int i, y;

    if (x < - LOGOLENGTH)  return ERR;
    y = LINES / 2 - 3;

    for (i = 0; i <= LOGOHEIGHT - 1; ++i) {
        my_mvaddstr(y + i, x, your[i]);
        my_mvaddstr(y + i, x+YOURLENGTH, wants[i]);
        my_mvaddstr(y + i, x+YOURLENGTH+WANTSLENGTH, iphone[i]);
    }
    return OK;
}
