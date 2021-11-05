#include <vpi/vpihandle.hpp>
#include <string>

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

VPIHandle::VPIHandle(const std::string &name)
{
    this->nativeHandle = vpi_handle_by_name(name.c_str(),NULL);
}


int VPIHandle::getIntValue()
{
    struct t_vpi_value retVal;

    retVal.format = vpiIntVal;
    vpi_get_value(this->nativeHandle, &retVal);

    return retVal.value.integer;
}

VPIHandle::~VPIHandle()
{
    vpi_free_object(this->nativeHandle);
}