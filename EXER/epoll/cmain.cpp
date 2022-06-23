#include <iostream>
#include <sys/epoll.h>
using namespace std;

inline int
cons_mess(const char *mess, int retval) {
    perror(mess);
    return retval;
}

int main() {
    int epfd = -1;
    int err  = -1;

    /* Step 1: create epoll fd */
    epfd = epoll_create(1);
    if (epfd == -1)    return cons_mess("epoll_create() failed: ", -1);

    /* Step 2: add event to epoll fd */
    err  = epoll_ctl(epfd, EPOLL_CTL_ADD, )

    return 0;
}