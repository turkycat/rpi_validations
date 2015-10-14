// Copyright (c) Microsoft Open Technologies, Inc.  All rights reserved.  
// Licensed under the BSD 2-Clause License.  
// See License.txt in the project root for license information.

#ifndef _QUARK_L_GPIO_H_
#define _QUARK_L_GPIO_H_

#include <Windows.h>

//
// Define an Interface Guid so that app can find the device and talk to it.
//

// {091A7D51-BB55-42E4-AE25-1D0B563FA177}
DEFINE_GUID(
    GUID_DEVINTERFACE_QuarkLGpio,
    0x91a7d51, 0xbb55, 0x42e4, 0xae, 0x25, 0x1d, 0xb, 0x56, 0x3f, 0xa1, 0x77);


#define FILE_DEVICE_QUARKLGPIO 0x424


#define IOCTL_QUARKLGPIO_GET_DIR                CTL_CODE(FILE_DEVICE_QUARKLGPIO, 0x100, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_QUARKLGPIO_SET_DIR                CTL_CODE(FILE_DEVICE_QUARKLGPIO, 0x101, METHOD_BUFFERED, FILE_WRITE_ACCESS)
#define IOCTL_QUARKLGPIO_SET_DIR_INPUT          CTL_CODE(FILE_DEVICE_QUARKLGPIO, 0x102, METHOD_BUFFERED, FILE_WRITE_ACCESS)
#define IOCTL_QUARKLGPIO_SET_DIR_OUTPUT         CTL_CODE(FILE_DEVICE_QUARKLGPIO, 0x103, METHOD_BUFFERED, FILE_WRITE_ACCESS)

#define IOCTL_QUARKLGPIO_READ_PINS              CTL_CODE(FILE_DEVICE_QUARKLGPIO, 0x200, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_QUARKLGPIO_WRITE_PINS             CTL_CODE(FILE_DEVICE_QUARKLGPIO, 0x201, METHOD_BUFFERED, FILE_WRITE_ACCESS)
#define IOCTL_QUARKLGPIO_SET_PINS_HIGH          CTL_CODE(FILE_DEVICE_QUARKLGPIO, 0x202, METHOD_BUFFERED, FILE_WRITE_ACCESS)
#define IOCTL_QUARKLGPIO_SET_PINS_LOW           CTL_CODE(FILE_DEVICE_QUARKLGPIO, 0x203, METHOD_BUFFERED, FILE_WRITE_ACCESS)

typedef enum _QUARKLGPIO_BANK {
    QUARKLGPIO_BANK_COREWELL = 0,
    QUARKLGPIO_BANK_RESUMEWELL
} QUARKLGPIO_BANK;

#define QUARKLGPIO_COREWELL_PIN_COUNT           2
#define QUARKLGPIO_RESUMEWELL_PIN_COUNT         6

#define QUARKLGPIO_COREWELL_MASK                ((0x1 << QUARKLGPIO_COREWELL_PIN_COUNT) - 1)
#define QUARKLGPIO_RESUMEWELL_MASK              ((0x1 << QUARKLGPIO_RESUMEWELL_PIN_COUNT) - 1)

#define QUARKLGPIO_COREWELL_DEFAULT_DIRECTION   0x3
#define QUARKLGPIO_COREWELL_DEFAULT_VALUE       0
#define QUARKLGPIO_RESUMEWELL_DEFAULT_DIRECTION 0x6
#define QUARKLGPIO_RESUMEWELL_DEFAULT_VALUE     0x4

typedef struct _QUARKLGPIO_INPUT_BUFFER {
    QUARKLGPIO_BANK Bank;
    UINT32 Mask;
} QUARKLGPIO_INPUT_BUFFER;

#endif // _QUARK_L_GPIO_H_
