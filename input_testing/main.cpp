#include <iostream>
#include <curses.h>

using namespace std;

int main() {

    initscr();
    cbreak();

    WINDOW* inputwin = newwin(3, 12, 5, 5);
    box(inputwin, 0, 0);
    refresh();
    wrefresh(inputwin);

    int c = wgetch(inputwin);
    cout << "you pressed: " << (char)c << endl;

    /* if (c == 'j') {
        //mvprintw(inputwin, 1, 1, "you pressed j");
        wrefresh(inputwin);
    } */

    getch();
    endwin();

    return 0;
}