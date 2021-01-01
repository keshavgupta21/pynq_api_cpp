#include "pynq_api.h"

int PYNQ_openAXIGPIOCH(PYNQ_AXI_GPIO_CH* gpio_ch, size_t base_address, size_t chnum) {
    PYNQ_createMMIOWindow(&(gpio_ch->mmio_window), base_address, 0x10);
    if (chnum == 1) {
        gpio_ch->dataOffset = PYNQ_AXI_GPIO_CH1DATA_OFFSET;
        gpio_ch->dataLen = PYNQ_AXI_GPIO_CH1DATA_LEN;
        gpio_ch->triOffset = PYNQ_AXI_GPIO_CH1TRI_OFFSET;
        gpio_ch->triLen = PYNQ_AXI_GPIO_CH1TRI_LEN;
        return PYNQ_SUCCESS;
    } else if (chnum == 2) {
        gpio_ch->dataOffset = PYNQ_AXI_GPIO_CH2DATA_OFFSET;
        gpio_ch->dataLen = PYNQ_AXI_GPIO_CH2DATA_LEN;
        gpio_ch->triOffset = PYNQ_AXI_GPIO_CH2TRI_OFFSET;
        gpio_ch->triLen = PYNQ_AXI_GPIO_CH2TRI_LEN;
        return PYNQ_SUCCESS;
    } else {
        return PYNQ_ERROR;
    }
}

int PYNQ_writeAXIGPIOCH(PYNQ_AXI_GPIO_CH* gpio_ch, unsigned int *data) {
    return PYNQ_writeMMIO(&(gpio_ch->mmio_window), data, gpio_ch->dataOffset, gpio_ch->dataLen);
}

int PYNQ_readAXIGPIOCH(PYNQ_AXI_GPIO_CH* gpio_ch, unsigned int *data) {
    return PYNQ_readMMIO(&(gpio_ch->mmio_window), data, gpio_ch->dataOffset, gpio_ch->dataLen);
}

int PYNQ_closeAXIGPIOCH(PYNQ_AXI_GPIO_CH* gpio_ch) {
    return PYNQ_closeMMIOWindow(&(gpio_ch->mmio_window));
}