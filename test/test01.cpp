#include <vpi/vpihandle.hpp>
#include <vpi_user.h>

struct functions_t
{
    const char *name;
    int (*callback)(char *);
};

static int val(char *userdata)
{
    VPIHandle arglist = VPIHandle(vpiSysTfCall);
    // VPIHandle first;


    VPIHandle &fval = arglist.iterate(vpiArgument).scan();

    int x = fval.getIntValue();


    printf("X: %d\n",x);


    return 0;
}

struct functions_t funcs[] = {
    {"$clkval", val},
    0
};

void register_functions()
{
    struct functions_t *aux = funcs; 
    while(aux->callback != 0)
    {
        s_vpi_systf_data data = {vpiSysTask, 0, funcs->name, funcs->callback, 0, 0, 0 };
        vpi_register_systf(&data);
        aux++;
    }
}

void (*vlog_startup_routines[])() = {
    register_functions,
    0
};