#include <ev.h>
#include <stdio.h>

ev_io stdin_watcher;
ev_timer timeout_watcher;

static void stdin_cb(EV_P_ ev_io *w, int revents)
{
    puts("stdin ready");
    ev_io_stop(EV_A_ w);
    //ev_break(EV_A_ EVBREAK_ALL);
}

static void timeout_cb(EV_P_ ev_timer *w, int revents)
{
    puts("timeout");
    //ev_break(EV_A_ EVBREAK_ONE);
}

int main()
{
    struct ev_loop *loop = EV_DEFAULT;  /*创建一个事件循环*/
    ev_io_init(&stdin_watcher, stdin_cb, 0, EV_READ);/*读取标准输入事件，将此事件注册到
                                                        事件循环上，在满足注册条件时，会
                                                        触发观察器，调用回调函数*/
    ev_io_start(loop, &stdin_watcher);

    ev_timer_init(&timeout_watcher, timeout_cb, 5.5, 2);/*超时事件*/
    ev_timer_start(loop, &timeout_watcher);

    ev_run(loop, 0);

    return 0;
}
