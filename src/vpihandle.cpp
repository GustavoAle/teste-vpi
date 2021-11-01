#include <vpi/vpihandle.hpp>

VPIHandle::VPIHandle(int type)
{
    this->nativeHandle = vpi_handle(type, NULL);
}

VPIHandle::VPIHandle(int type, vpiHandle nativeRef)
{
    this->nativeHandle = vpi_handle(type, nativeRef);
}

VPIHandle::VPIHandle(vpiHandle nativeRef)
: nativeHandle(nativeRef)
{
}
