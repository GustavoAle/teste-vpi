#ifndef VPIHANDLE_HPP
#define VPIHANDLE_HPP

extern "C"
{
#include <vpi_user.h>
}

#include <string>

class VPIHandle
{
protected:
    vpiHandle nativeHandle;
    VPIHandle *iteratorHandle = NULL;

public:
    /**
     * @brief Construct a new VPIHandle object
     * 
     * @param type Object type 
     */
    VPIHandle(int type);

    /**
     * @brief Construct a new VPIHandle object
     * 
     * @param type Object type
     * @param nativeRef Native C vpiHandle object
     */
    VPIHandle(int type, vpiHandle nativeRef);

    /**
     * @brief Construct a new VPIHandle object 
     * from a native C vpiHandle
     * 
     * @param nativeRef 
     */
    VPIHandle(vpiHandle nativeRef);

    /**
     * @brief Obtain a handle to a iterator object
     * 
     * @param type Object type
     * @return VPIHandle 
     */
    VPIHandle &iterate(int type);

    /**
     * @brief Scan next object 
     * 
     * @return VPIHandle 
     */
    VPIHandle scan();

    /**
     * @brief Get the int value of object 
     * 
     * @return int 
     */
    int getIntValue();

    /**
     * @brief Get the string value of object
     * 
     * @return char* 
     */
    char *getStrValue();

    /**
     * @brief Get the value of object
     * 
     * @param value 
     */
    void getValue(t_vpi_value *value);

    /**
     * @brief Get the object type
     * 
     * @return int 
     */
    int getType();

    /**
     * @brief Get the object size
     * 
     * @return int 
     */
    int getSize();

    /**
     * @brief Get the object Typename
     * 
     * @return std::string 
     */
    std::string getTypeName();

    /**
     * @brief Get the object name
     * 
     * @return std::string 
     */
    std::string getName();

    /**
     * @brief Get the object fullname
     * 
     * @return std::string 
     */
    std::string getFullName();

    /**
     * @brief Get the native handle
     * 
     * @return vpiHandle 
     */
    vpiHandle getNative();


    /**
     * @brief Compare two VPIHandle objects
     * 
     * @param ref 
     * @return true 
     * @return false 
     */
    bool operator==(VPIHandle &ref);
};

inline VPIHandle &VPIHandle::iterate(int type)
{
    if(!iteratorHandle)
        iteratorHandle = new VPIHandle(vpi_iterate(type, this->nativeHandle));
    
    return *iteratorHandle;
}

inline VPIHandle VPIHandle::scan()
{
    return VPIHandle(vpi_scan(this->nativeHandle));
}

inline vpiHandle VPIHandle::getNative()
{
    return this->nativeHandle;
}

inline int VPIHandle::getType()
{
    return vpi_get(vpiType, this->nativeHandle);
}

inline int VPIHandle::getSize()
{
    return vpi_get(vpiSize, this->nativeHandle);
}

inline std::string VPIHandle::getTypeName()
{
    return std::string(vpi_get_str(vpiType, this->nativeHandle));
}

inline std::string VPIHandle::getName()
{
    return std::string(vpi_get_str(vpiName, this->nativeHandle));
}

inline std::string VPIHandle::getFullName()
{
    return std::string(vpi_get_str(vpiFullName, this->nativeHandle));
}

inline bool VPIHandle::operator==(VPIHandle &ref)
{
    return (bool)vpi_compare_objects(this->nativeHandle, ref.nativeHandle);
}

#endif